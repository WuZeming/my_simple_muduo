#include "ListenChannel.h"
#include "Socket.h"
#include "InetAddress.h"
#include"TcpServer.h"
namespace muduo
{
ListenChannel::ListenChannel(EventLoop* _loop,TcpServer* _owner, const InetAddress& listenAddr)
            : Channel(_loop,socket::createNonBlockSocket()),
            mp_owner(_owner)
            
{
    socket::setReuseAddr(fd(),true);
    socket::setReusePort(fd(),true);
    socket::bind(m_fd,listenAddr.getSockAddr());
}
ListenChannel::~ListenChannel()
{
    disableAllEvent();
    rmThisFromLoop();
}

void ListenChannel::handleRead()
{
    
    struct sockaddr_in peeradd_in;
    int connfd = socket::acceptNonBlock(fd(),&peeradd_in);
    InetAddress peerAddr(peeradd_in);
    mp_owner->newConnection(connfd,peerAddr);
    
}


void ListenChannel::startListen()
{
    socket::listen(fd());
    enableReadEvent();
    //LOG<<

}

} // namespace muduo