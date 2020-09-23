#ifndef MUDUO_NET_LISTENCHANNEL_H
#define MUDUO_NET_LISTENCHANNEL_H
#include "Channel.h"
#include <functional>

namespace muduo
{
class InetAddress;
class TcpServer;
using NewConnCallBack = std::function<void(int, const InetAddress &)>;

class ListenChannel : public Channel
{
public:
    ListenChannel(EventLoop *_loop, TcpServer* _owner, const InetAddress &listenAddr);
    virtual ~ListenChannel();

    void startListen();


private:
    virtual void handleRead() override;
    TcpServer* mp_owner;
}; // class ListenChannel

} // namespace muduo

#endif