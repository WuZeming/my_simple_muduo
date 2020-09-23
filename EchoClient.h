#pragma once
#include"TcpClient.h"
#include"unistd.h"
#include<iostream>


using namespace muduo;


class EchoClient;
class StdIn :public Channel
{
public:
    StdIn(EventLoop* loop,EchoClient * owner)
        :Channel(loop,0),// 标准输入
        m_owner(owner)

    {
        
    }
    ~StdIn(){}
    void handleRead();
private: 
    EchoClient* m_owner;
};


class EchoClient :public TcpClient
{
public:
    EchoClient(EventLoop* loop,const InetAddress& addr)
        :TcpClient(loop,addr),
        m_stdin(loop,this)
    {
        m_stdin.enableReadEvent();
    }
    ~EchoClient(){};
    virtual void onMessage(CommuChShPtr connCh, Buffer* buff) override
    {
        std::string msg = buff->retrieveAllAsString();
        std::cout<<msg<<std::endl;
    }
    void handleStdin(int infd)
    {
        char buf[1024]={0};
        ::read(infd, buf, sizeof(buf)-1);

        mp_CommuCh->send(buf);

    }
private:
    StdIn m_stdin;
};


void StdIn::handleRead()
{
    m_owner->handleStdin(m_fd);
}