#include"ConnectChannel.h"
#include"Socket.h"
#include"TcpClient.h"
namespace muduo
{

ConnectChannel::ConnectChannel(EventLoop* _loop,TcpClient* _owner,const InetAddress& _addr)
                    :Channel(_loop,-1),
                    mp_owner(_owner),
                    m_serverAddr(_addr),
                    m_state(Stopped)
                    {}

ConnectChannel::~ConnectChannel()
{

}

void ConnectChannel::start()
{
    mp_loop->runInloop(std::bind(&ConnectChannel::startInLoop,this));
}


void ConnectChannel::stop()
{
    mp_loop->runInloop(std::bind(&ConnectChannel::stopInLoop,this));
}

void ConnectChannel::startInLoop()
{
    if(m_state == Stopped)
    {
        connect();
    }
}

void ConnectChannel::stopInLoop()
{
    if(m_state == Connecting)
    {
        m_state = Stopped;
        disableAllEvent();
        socket::close(m_fd);
    }
}

void ConnectChannel::connect()
{
    m_state = Connecting;
    m_fd = socket::createNonBlockSocket();

    int ret = socket::connect(m_fd,m_serverAddr.getSockAddr());

    int savedErrno = (ret == 0) ? 0 : errno;
    switch (savedErrno)
    {
        case 0:
        case EINPROGRESS:
        case EINTR:
        case EISCONN:
            enableWriteEvent();
            break;

        case EAGAIN:
        case EADDRINUSE:
        case EADDRNOTAVAIL:
        case ECONNREFUSED:
        case ENETUNREACH:
            retry();
            break;

        case EACCES:
        case EPERM:
        case EAFNOSUPPORT:
        case EALREADY:
        case EBADF:
        case EFAULT:
        case ENOTSOCK:
            //LOG_ERROR("connect error=%d", savedErrno);
            socket::close(m_fd);
            break;

        default:
            //LOG_ERROR("Unexpected error=%d", savedErrno);
            socket::close(m_fd);
            break;
    }
}

void ConnectChannel::handleWrite()
{
    if(m_state == Connecting)
    {
        disableAllEvent();
        rmThisFromLoop();
        int err = socket::getSocketError(m_fd);
        if(err)
        {
            //LOG
            retry();
        }
        else if(socket::isSelfConnect(m_fd))
        {
            retry();
        }
        else
        {
            m_state = Connected;
            mp_owner->newConnection(m_fd,m_serverAddr);
        }
    }
}

void ConnectChannel::retry()
{
    m_state = Stopped;
    socket::close(m_fd);
    sleep(2);// 延时后重连
    mp_loop->runInloop(std::bind(&ConnectChannel::start,this));

}

}