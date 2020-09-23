#include "EventLoopThread.h"


namespace muduo
{

EventLoopThread::EventLoopThread()
            :m_loop(nullptr),
            m_exiting(false),
            m_thread(std::bind(&EventLoopThread::threadFun,this),"EventLoopThread"),
            m_mutex(),
            m_cond(m_mutex)
            {}
EventLoopThread::~EventLoopThread()
{
    m_exiting = true;
    if(m_loop!=nullptr)
    {
        m_loop->quit();
        m_thread.join();
    }
}

EventLoop* EventLoopThread::startLoop()
{
    assert(!m_thread.isStarted());
    m_thread.start();
    {
        MutexGuard lock(m_mutex);
        while (m_loop == nullptr)
        {
            m_cond.wait();
        }
        
    }
    return m_loop;
}

void EventLoopThread::threadFun()
{
    EventLoop loop;
    {
        MutexGuard lock(m_mutex);
        m_loop = &loop;
        m_cond.signal();
    }
    loop.loop();

    m_loop = nullptr;
}



}// namespace muduo