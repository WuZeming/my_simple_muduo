#pragma once
#include"TcpServer.h"
#include"InetAddress.h"
#include<string>


using namespace muduo;
class EchoServer : public TcpServer
{
public:
    EchoServer(EventLoop* _loop,const InetAddress& _addr)
        :TcpServer(_loop,_addr)
        {}
    ~EchoServer() = default;

    virtual void onMessage(CommuChShPtr commuCh, Buffer* buff) 
    {
        std::string message = buff->retrieveAllAsString();
        commuCh->send(message);
    }
    //virtual void onWriteComplete(CommuChShPtr commuCh) override {} // 缓冲区数据发送完成
    //virtual void onHighWaterMark(CommuChShPtr commuCh) override {} // 缓冲区有数据未发送
    //virtual void onNewConnection(CommuChShPtr commuCh) override {}
    //virtual void onDelConnection(CommuChShPtr commuCh) override {}

};