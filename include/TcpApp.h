#ifndef MUDUO_TCPAPP_H
#define MUDUO_TCPAPP_H
#include"Uncopyable.h"
#include"CommunicateChannel.h"
namespace muduo
{
class TcpApp :Uncopyable
{
public:
    TcpApp() = default;
    virtual ~TcpApp() = default;

    virtual void onMessage(CommuChShPtr commuCh, Buffer* buff) = 0;// 收到消息
    virtual void onWriteComplete(CommuChShPtr commuCh) = 0; // 缓冲区数据发送完成
    virtual void onHighWaterMark(CommuChShPtr commuCh) = 0; // 缓冲区有数据未发送
    virtual void onNewConnection(CommuChShPtr commuCh) = 0;
    virtual void onDelConnection(CommuChShPtr commuCh) = 0;

    virtual void newConnection(int connfd, const InetAddress& peerAddr) = 0;
    virtual void delConnection(CommuChShPtr commuCh) = 0;
    
};
} // namespace muduo

#endif