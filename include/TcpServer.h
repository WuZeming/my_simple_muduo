#ifndef MUDUO_NET_TCPSERVER_H
#define MUDUO_NET_TCPSERVER_H
#include "InetAddress.h"
#include "EventLoop.h"
#include "EventLoopThreadPool.h"
#include "CommunicateChannel.h"
#include <memory>
#include "TcpApp.h"

namespace muduo
{


class ListenChannel;
class TcpServer :public TcpApp
{
public:
    TcpServer(EventLoop* _loop, const InetAddress& _addr);
    virtual ~TcpServer();
    // 供ListenChannel调用
    virtual void newConnection(int connfd, const InetAddress& peerAddr) override;
    // 供CommunicateChannel调用
    virtual void delConnection(CommuChShPtr commuCh) override;
    // 供用户重载
    virtual void onMessage(CommuChShPtr commuCh, Buffer* buff) = 0;// 收到消息
    virtual void onWriteComplete(CommuChShPtr commuCh) override {} // 缓冲区数据发送完成
    virtual void onHighWaterMark(CommuChShPtr commuCh) override {} // 缓冲区有数据未发送
    virtual void onNewConnection(CommuChShPtr commuCh) override {}
    virtual void onDelConnection(CommuChShPtr commuCh) override {}

    void start();

private:
    EventLoop* mp_Mainloop;
    std::string m_name;
    std::unique_ptr<ListenChannel> mp_listenChannel;
    std::unique_ptr<EventLoopThreadPool> mp_threadPool;
    std::map<std::string,CommuChShPtr> m_connMap;
    bool m_started;
    size_t m_nextConnId;
    

}; // class tcpserver

}// namespace muduo



#endif