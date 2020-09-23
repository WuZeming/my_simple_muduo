#include "TcpServer.h"
#include "ListenChannel.h"
#include <functional>
#include "Socket.h"

namespace muduo
{

const int ThreadNum = 5;

TcpServer::TcpServer(EventLoop* _loop, const InetAddress& _addr)
    :mp_Mainloop(_loop),
    m_name("TcpServer"),
    mp_threadPool(new EventLoopThreadPool(_loop,ThreadNum)),
    mp_listenChannel(new ListenChannel(_loop,this,_addr)),
    m_nextConnId(1)
{
}

TcpServer::~TcpServer()
{
    
}
void TcpServer::start()
{
    if(!m_started)
    {
        m_started = true;
        mp_listenChannel->startListen();
        mp_threadPool->start();
    }
}


void TcpServer::newConnection(int connfd, const InetAddress& peerAddr)
{
    std::string connName = std::to_string(m_nextConnId);
    m_nextConnId++;
    InetAddress localAddr(socket::getLocalAddr(connfd));
    EventLoop* nextLoop = mp_threadPool->getNextLoop();

    CommuChShPtr newCommuCh = std::make_shared<CommunicateChannel>(
                                    nextLoop,
                                    connfd,
                                    this,
                                    localAddr,
                                    peerAddr,
                                    connName);
    m_connMap[connName] = newCommuCh;
    
    nextLoop->queueInLoop(std::bind(&CommunicateChannel::enableReadEvent,newCommuCh.get()));

    onNewConnection(newCommuCh);
}


void TcpServer::delConnection(CommuChShPtr commuCh)
{
    onDelConnection(commuCh);
    commuCh->rmThisFromLoop();
    m_connMap.erase(commuCh->name());
}




}// namespace muduo