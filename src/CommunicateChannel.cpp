#include "CommunicateChannel.h"
#include "Socket.h"
#include "TcpApp.h"

namespace muduo
{
CommunicateChannel::CommunicateChannel(EventLoop* _loop,
                        int _fd,
                        TcpApp* _owner,
                        const InetAddress& _localAddr, 
                        const InetAddress& _peerAddr, 
                        const std::string& _name )
                        :Channel(_loop,_fd),
                        m_owner(_owner),
                        m_name(_name),
                        m_localAddr(_localAddr),
                        m_peerAddr(_peerAddr),
                        m_state(kConnected),
                        m_highWaterMark(0)
                        {
                            
                        }


CommunicateChannel::~CommunicateChannel()
{
    
}

void CommunicateChannel::send(const StringPiece& message)
{
    if(m_state == kConnected)
    {
        ownerLoop()->runInloop(std::bind(&CommunicateChannel::sendInLoop,this,message.data(),message.size()));
    }
}

void CommunicateChannel::send(Buffer* buff)
{
    if(m_state == kConnected)
    {
        send(buff->retrieveAllAsString());
    }
}


void CommunicateChannel::sendInLoop(const void* data, size_t len)
{
    ownerLoop()->assertInLoopThread();
    ssize_t nwrote = 0;
    size_t remaining = len;
    bool faultError = false; // 直接发送是否出错
    if(m_state == kDisconnected)
    {
        //LOG<<
        return;
    }
    if(!isWriteEvent()&& m_outputBuffer.readableBytes() == 0)
    {
        nwrote = ::write(fd(),data,len);
        if(nwrote>=0)
        {
            remaining = len-nwrote;
            if(remaining == 0)
            {
                m_owner->onWriteComplete(shared_from_this());
            }
        }
        else
        {
            nwrote = 0;
            if(errno !=EAGAIN)
            {
                if(errno == EPIPE || errno == ECONNRESET)
                {
                    faultError = true;
                }
            }
        }
        
    }

    assert(remaining<=len);
    if(!faultError && remaining>0)
    {
        size_t oldlen = m_outputBuffer.readableBytes();
        if(oldlen+remaining>=m_highWaterMark && oldlen<m_highWaterMark)
        {
            m_owner->onHighWaterMark(shared_from_this());
        }
        m_outputBuffer.append(static_cast<const char*>(data)+nwrote, remaining);
        if(!isWriteEvent())
        {
            enableWriteEvent();
        }
    }

}




void CommunicateChannel::handleRead()
{
    ownerLoop()->assertInLoopThread();
    int savedErrno = 0;
    ssize_t n = m_inputBuffer.readFd(fd(),&savedErrno);
    if(n>0)
    {
        m_owner->onMessage(shared_from_this(),&m_inputBuffer);
    }else if(n == 0)
    {
        handleClose();
    }else
    {
        errno = savedErrno;
        handleError();
    }
    
}

void CommunicateChannel::handleWrite()
{
    ownerLoop()->assertInLoopThread();
    if (isWriteEvent())
    {
        ssize_t n = ::write(fd(), m_outputBuffer.peek(), m_outputBuffer.readableBytes());
        if (n > 0)
        {
            m_outputBuffer.retrieve(n);
            if (m_outputBuffer.readableBytes() == 0)
            {
                disableWriteEvent();

                m_owner->onWriteComplete(shared_from_this());
                
                if (m_state == kDisconnecting)
                {
                    shutdownInLoop();
                }
            }
        }
        else
        {
            //LOG_ERROR("TcpConnection::handleWrite");
        }
    }
    else
    {
        //LOG_TRACE("Connection fd=%d no more writing", fd_);
    }
}

void CommunicateChannel::handleClose()
{
    ownerLoop()->assertInLoopThread();
    assert(m_state == kConnected|| m_state == kDisconnecting);
    setState(kDisconnected);
    
    disableAllEvent();
    m_owner->delConnection(shared_from_this());
}

void CommunicateChannel::handleError()
{
    int err = socket::getSocketError(fd());
    //LOG<<
}

void CommunicateChannel::shutdown()
{
    if(m_state == kConnected)
    {
        setState(kDisconnecting);
        ownerLoop()->runInloop(std::bind(&CommunicateChannel::shutdownInLoop,this));
    }
}
void CommunicateChannel::shutdownInLoop()
{
    ownerLoop()->assertInLoopThread();
    
    if (!isWriteEvent())
    {
        socket::shutdownWrite(fd());
    }
}
void CommunicateChannel::forceClose()
{
    if(m_state == kConnected)
    {
        setState(kDisconnecting);
        ownerLoop()->runInloop(std::bind(&CommunicateChannel::forceCloseInLoop,this));
    }
}
void CommunicateChannel::forceCloseInLoop()
{
    ownerLoop()->assertInLoopThread();
    if(m_state == kDisconnecting)
    {
        handleClose();
    }
}

} // namespace muduo