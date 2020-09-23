#ifndef MUDUO_CONNECTCHANNEL_H
#define MUDUO_CONNECTCHANNEL_H
#include"EventLoop.h"
#include"Channel.h"
#include "InetAddress.h"

namespace muduo
{
class TcpClient;
class ConnectChannel :public Channel
{
public:
    ConnectChannel(EventLoop* _loop, TcpClient* _owner, const InetAddress& _addr);
    ~ConnectChannel();

    virtual void handleWrite() override;
    void start();
    void stop();
    void restart();

private:
    enum States {Stopped, Connecting, Connected};

    void startInLoop();
    void stopInLoop();
    void connect();
    void retry();


    TcpClient* mp_owner;
    InetAddress m_serverAddr;
    States m_state;
};

}

#endif