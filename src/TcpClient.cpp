#include "TcpClient.h"
#include "Socket.h"
#include <iostream>
namespace muduo
{

    TcpClient::TcpClient(EventLoop *_loop, const InetAddress &_addr)
        : mp_loop(_loop),
          m_serverAddr(_addr)
    {
        mp_ConnCh = std::make_unique<ConnectChannel>(_loop, this, m_serverAddr);
    }

    TcpClient::~TcpClient()
    {
    }

    void TcpClient::connect()
    {
        mp_ConnCh->start();
    }

    void TcpClient::disconnect()
    {
    }

    void TcpClient::stop()
    {
        mp_ConnCh->stop();
    }

    void TcpClient::newConnection(int fd, const InetAddress &serverAddr)
    {
        InetAddress localAddr(socket::getLocalAddr(fd));
        std::string connName = "name";

        mp_CommuCh = std::make_shared<CommunicateChannel>(
            mp_loop,
            fd,
            this,
            localAddr,
            serverAddr,
            connName);
        
        mp_CommuCh->enableReadEvent();
        
        onNewConnection(mp_CommuCh);
    }

    void TcpClient::delConnection(CommuChShPtr conn)
    {
        onDelConnection(conn);
        mp_CommuCh.reset();
    }

} // namespace muduo