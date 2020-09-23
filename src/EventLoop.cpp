#include "EventLoop.h"
#include <sys/eventfd.h>
#include <unistd.h>
#include "EpollPoller.h"
#include "Channel.h"
namespace muduo
{

int creatEventFd()
{
    int efd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if (efd < 0)
    {
        //LOG<<
        abort();
    }
}

class WakeupChannel : public Channel
{
public:
    WakeupChannel(EventLoop *_loop)
        : Channel(_loop, creatEventFd())
    {
        enableReadEvent();
    }
    ~WakeupChannel()
    {
        disableAllEvent();
        rmThisFromLoop();
    }
    void wakeup()
    {
        uint64_t one = 1;
        ssize_t n = ::write(fd(), &one, sizeof one); // 考虑换成writen
        if (n != sizeof one)
        {
            //LOG<<
        }
    }
private:
    virtual void handleRead() override
    {
        uint64_t one = 0;
        ssize_t n = ::read(fd(), &one, sizeof one); // 考虑换成 readn
        if (n != sizeof one)
        {
            //LOG<<
        }
    }
};

__thread EventLoop *t_loopInThisThread = nullptr; // 保证一个线程只有一个loop

EventLoop::EventLoop()
    : m_looping(false),
      m_tid(CurrentThread::tid()),
      m_eventHanding(false),
      m_quit(false),
      m_callingPendingFunctors(false),
      m_wakeup_fd(creatEventFd()),
      m_pPoller(new EpollPoller(this)), // 设置监听器，选择poll或者epoll Poller
      m_pWakeupChannel(new WakeupChannel(this)),
      m_curr_activeChannel(nullptr)
{
    if (t_loopInThisThread)
    {
        //LOG<<
        abort();
    }
    else
    {
        t_loopInThisThread = this;
    }
}

EventLoop::~EventLoop(){}

void EventLoop::loop() // 主循环
{
    assert(!m_looping);
    assertInLoopThread();
    m_looping = true;
    m_quit = false;

    while (!m_quit)
    {
        m_activeChannels.clear();
        m_pPoller->poll(&m_activeChannels);

        m_eventHanding = true;
        for (auto ch : m_activeChannels)
        {
            m_curr_activeChannel = ch;
            ch->handleEvent();
        }
        m_curr_activeChannel = nullptr;
        m_eventHanding = false;

        doPendingFunctors();
    }

    m_looping = false;
}

void EventLoop::runInloop(Functor cb)
{
    if (isInLoopThread())
    {
        cb();
    }
    else
    {
        queueInLoop(cb);
    }
}

void EventLoop::queueInLoop(Functor cb)
{
    {
        MutexGuard lock(m_mutex);
        m_pendingFunctors.emplace_back(cb);
    }
    if (!isInLoopThread() || m_callingPendingFunctors)
    {
        wakeup();
    }
}


void EventLoop::wakeup()
{
    m_pWakeupChannel->wakeup();
}

void EventLoop::doPendingFunctors()
{
    std::vector<Functor> temp;
    m_callingPendingFunctors = true;
    {
        MutexGuard lock(m_mutex);
        temp.swap(m_pendingFunctors);
    }
    for (auto fun : temp)
    {
        fun();
    }
    m_callingPendingFunctors = false;
}

void EventLoop::quit()
{
    m_quit = true;
    if (!isInLoopThread())
    {
        wakeup();
    }
}
void EventLoop::shutdownChannel(Channel *_ch)
{
}

} // namespace muduo