#ifndef MUDUO_NET_EVENTLOOPTHREADPOOL_H
#define MUDUO_NET_EVENTLOOPTHREADPOOL_H
#include "Uncopyable.h"
#include <vector>
#include <memory>
#include <string>
#include "EventLoopThread.h"
namespace muduo
{

class EventLoop;

class EventLoopThreadPool : Uncopyable
{
public:
    EventLoopThreadPool(EventLoop *_baseloop, int _numThreads,const std::string& _name = "EventLoopThreadPool");
    ~EventLoopThreadPool() = default;

    void start(); // 线程池初始化，并运行

    EventLoop *getNextLoop(); // 循环取出下一个对象

private:
    std::string m_name;
    EventLoop *m_baseLoop;                                   //分发事件的EventLoop
    bool m_started;                                          // 线程池开始标志
    int m_numThreads;                                        // 线程数
    int m_next;                                              // 按顺序给loop对象分发
    std::vector<std::unique_ptr<EventLoopThread>> m_threads; // 线程池
    std::vector<EventLoop*> m_loops;                        // 每个线程的EventLoop指针
};

} // namespace muduo

#endif