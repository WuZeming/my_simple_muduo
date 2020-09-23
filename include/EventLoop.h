#ifndef MUDUO_NET_EVENTLOOP_H
#define MUDUO_NET_EVENTLOOP_H

#include "Uncopyable.h"
#include "MutexLock.h"
#include "Thread.h"
#include "Poller.h"
#include <assert.h>
#include <pthread.h>
#include <functional>
#include <memory>
#include <vector>
namespace muduo
{
class WakeupChannel;
class EventLoop : Uncopyable
{
public:
    using Functor = std::function<void()>;
    EventLoop();
    ~EventLoop();

    void loop(); // 主循环

    void quit(); // 退出主循环
    void runInloop(Functor cb); // 在主循环中执行函数，本线程调用会立即执行，其他线程调用会执行下面的函数。
    void queueInLoop(Functor cb);// 将函数放入执行队列，并唤醒循环，执行函数
    void assertInLoopThread() { assert(isInLoopThread()); }
    bool isInLoopThread() const { return m_tid == CurrentThread::tid(); }

    void shutdownChannel(Channel* _ch); //单向关闭套接字

    void updateChannel(Channel* _ch){m_pPoller->updateChannel(_ch);}
    void removeChannel(Channel* _ch){m_pPoller->removeChannel(_ch);}

private:
    void abortNotInLoopThread();

    bool m_looping;    // 循环中的标志
    const pid_t m_tid; // 此处为Linux线程唯一标示，而非create返回的标示
                       // loop 所在线程的id
    bool m_quit;
    bool m_eventHanding;
    std::unique_ptr<Poller> m_pPoller; // 监听器
     
    MutexLock m_mutex;   // 用于m_pendingFunctors的互斥访问
    std::vector<Functor> m_pendingFunctors; // 待执行的用户回调函数队列，queueinloop（）的队列

    bool m_callingPendingFunctors;          // 正在执行阻塞队列中的函数的标志

    int m_wakeup_fd;                        // linux eventfd 文件描述符
    std::unique_ptr<WakeupChannel> m_pWakeupChannel; //用于唤醒操作channel
    
    Poller::ChannelList m_activeChannels;     // 一次监听返回的活动channel列表
    Channel* m_curr_activeChannel;           // 当前正在处理的channel，io操作


    void wakeup();            // 向m_wakeup_fd中写入一字节，唤醒线程，线程之前阻塞于poll()
    void handleWakeup();      // 收到wakeup数据后的回调函数
    void doPendingFunctors(); // 从queueinloop（）的阻塞队列中取出函数执行。
};

} // namespace muduo

#endif