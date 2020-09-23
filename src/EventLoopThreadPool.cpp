#include "EventLoopThreadPool.h"
#include "EventLoop.h"

namespace muduo
{

EventLoopThreadPool::EventLoopThreadPool(EventLoop *_baseloop, int _numThreads,const std::string& _name)
    : m_name(_name),
      m_baseLoop(_baseloop),
      m_started(false),
      m_numThreads(_numThreads),
      m_next(0)
{
    if (m_numThreads <= 0)
    {
        //LOG<<
        abort();
    }
}

void EventLoopThreadPool::start()
{
    m_baseLoop->assertInLoopThread();
    m_started = true;
    for (int i = 0; i < m_numThreads; i++)
    {
        auto t = new EventLoopThread();
        m_threads.push_back(std::unique_ptr<EventLoopThread>(t));
        m_loops.push_back(t->startLoop());
    }
}

EventLoop *EventLoopThreadPool::getNextLoop()
{
    m_baseLoop->assertInLoopThread();
    assert(m_started);
    EventLoop *loop = m_baseLoop;
    if (!m_loops.empty())
    {
        loop = m_loops[m_next];
        m_next = (m_next + 1) % m_numThreads;
    }
    return loop;
}

} // namespace muduo