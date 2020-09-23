#include "Channel.h"
#include "EventLoop.h"
#include <poll.h>
#include "Socket.h"
namespace muduo
{
static const int kNoneEvent = 0;
static const int kReadEvent = POLLIN | POLLPRI; //poll和epoll共用标志
static const int kWriteEvent = POLLOUT;


Channel::Channel(EventLoop *loop, int fd)
    : mp_loop(loop),
      m_fd(fd),
      m_events(0),
      m_revents(0),
      m_state(ChannelState::kNew) 
{
}
Channel::~Channel() {
    socket::close(m_fd);
}


void Channel::handleEvent()
{
    if ((m_revents & POLLHUP) && !(m_revents & POLLIN)) //挂断，且无数据
    {
        handleClose();
    }
    if (m_revents & (POLLERR | POLLNVAL)) // 出错，或者文件描述符未打开
    {
        handleError();
    }
    if (m_revents & (POLLIN | POLLPRI | POLLRDHUP))// 可读，高优先级可读，对端套接字关闭
    {
        handleRead();
    }
    if (m_revents & POLLOUT)
    {
        handleWrite();
    }
}


void Channel::enableReadEvent()
{
    m_events |= kReadEvent;
    updateThisInEventLoop();
}

void Channel::disableReadEvent()
{
    m_events &= ~kReadEvent;
    updateThisInEventLoop();
}
void Channel::enableWriteEvent()
{
    m_events |= kWriteEvent;
    updateThisInEventLoop();
}
void Channel::disableWriteEvent()
{
    m_events &= ~kWriteEvent;
    updateThisInEventLoop();
}
void Channel::disableAllEvent()
{
    m_events = kNoneEvent;
    updateThisInEventLoop();
}
void Channel::updateThisInEventLoop()
{
    mp_loop->updateChannel(this);
}


void Channel::rmThisFromLoop()
{
    mp_loop->removeChannel(this);
}



bool Channel::isNoneEvevts() const
{
    return m_events == kNoneEvent;
}

bool Channel::isReadEvent() const
{
    return m_events & kReadEvent;
}

bool Channel::isWriteEvent() const
{
    return m_events & kWriteEvent;
}




int Channel::fd() const
{
    return m_fd;
}

EventLoop *Channel::ownerLoop() const
{
    return mp_loop;
}

int Channel::events() const
{
    return m_events;
}

void Channel::set_revents(int _revent)
{
    m_revents = _revent;
}

ChannelState Channel::state() const
{
    return m_state;
}

void Channel::set_state(ChannelState _state)
{
    m_state = _state;
}


}// namespace muduo