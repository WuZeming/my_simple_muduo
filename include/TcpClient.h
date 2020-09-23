#ifndef MUDUO_TCPCLIENT_H
#define MUDUO_TCPCLIENT_H
#include"TcpApp.h"
#include"ConnectChannel.h"
#include"CommunicateChannel.h"

#include<string>
#include<memory>
namespace muduo
{

class TcpClient : public TcpApp
{
public:
    TcpClient(EventLoop *_loop, const InetAddress &_addr);
    ~TcpClient();
    void connect();
    void disconnect();
    void stop();
    virtual void newConnection(int fd, const InetAddress& addr) override;
    virtual void delConnection(CommuChShPtr commuCh) override;

    // 供用户重载
    virtual void onMessage(CommuChShPtr commuCh, Buffer* buff) = 0;// 收到消息
    virtual void onWriteComplete(CommuChShPtr commuCh) override {} // 缓冲区数据发送完成
    virtual void onHighWaterMark(CommuChShPtr commuCh) override {} // 缓冲区有数据未发送
    virtual void onNewConnection(CommuChShPtr commuCh) override {}
    virtual void onDelConnection(CommuChShPtr commuCh) override {}

protected:
    EventLoop* mp_loop;
    InetAddress m_serverAddr;
    const std::string name;
    std::unique_ptr<ConnectChannel> mp_ConnCh;
    CommuChShPtr mp_CommuCh;

};

}

#endif