#ifndef MUDUO_NET_EVENTLOOPTHREAD_H
#define MUDUO_NET_EVENTLOOPTHREAD_H
#include "Uncopyable.h"
#include"Thread.h"
#include"Condition.h"
#include"MutexLock.h"
#include"EventLoop.h"

// 该类将EventLoop 和 thread 封装在一起 
namespace muduo
{

class EventLoopThread: Uncopyable
{
public:
    EventLoopThread();
    ~EventLoopThread();
    EventLoop* startLoop(); // 开始线程，在线程中建立EventLoop对象，并返回对象指针
                            // 子线程开始执行，EventLoop建立后，才返回
private:
    void threadFun(); // 线程函数，在其中建立EventLoop对象，该对象和线程共存亡
    EventLoop* m_loop; // 指向建立EventLoop对象
    bool m_exiting;
    Thread m_thread;   // 线程
    MutexLock m_mutex;
    Condition m_cond;
};

} // namespace muduo





#endif