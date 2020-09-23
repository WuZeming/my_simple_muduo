#ifndef MUDUO_NET_EPOLL_H
#define MUDUO_NET_EPOLL_H

#include "Poller.h"
#include <sys/epoll.h>
#include <vector>

namespace muduo
{

class EpollPoller : public Poller
{
public:
    explicit EpollPoller(EventLoop *_loop);
    ~EpollPoller();

    void poll(ChannelList *activeChannels) override; // 封装epoll_wait()
    void updateChannel(Channel *_ch) override;
    void removeChannel(Channel *_ch) override;

private:
    static const int kInitEventListSize = 16;                                  // 初始events数组大小
    static const char *operationToString(int operation);                       // LOG辅助函数
    
    void update(int operation, Channel *_ch);                                  // 调用epoll_ctl()更新内核中的channel所管理的文件描述符
    void fillActiveChannels(int numEvents, ChannelList *activeChannels) const; // 将epoll监听到的事件放入channel list

    using EventList = std::vector<epoll_event>;

    EventList m_events; // epoll 返回的事件缓存
    int m_epoll_fd;     // epoll 文件描述符
};
} // namespace muduo

#endif