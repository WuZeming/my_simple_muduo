#ifndef MUDUO_NET_POLLER_H
#define MUDUO_NET_POLLER_H

#include "Uncopyable.h"
#include <map>
#include<vector>


namespace muduo
{
class Channel;
class EventLoop;


class Poller : Uncopyable
{
public:
    using ChannelList = std::vector<Channel*>;
    Poller(EventLoop *_loop);
    virtual ~Poller() = default;

    virtual void poll(ChannelList *activeChannels) = 0; // 封装监听函数，poll(), epoll_wait()
    virtual void updateChannel(Channel *_ch) = 0; // 更新channel在poller中的监听状态，增删改操作
    virtual void removeChannel(Channel *_ch) = 0; // 移除channel

    bool hasChannel(Channel *_ch) const;  // 查

    void assertInLoopThread() const;

protected:
    using ChannelMap = std::map<int, Channel*>; // fd到channel的map
    ChannelMap m_channels; // poller 所监听的channel
private:
    EventLoop *m_ownerLoop; // 所属loop
};

} //namespace muduo

#endif