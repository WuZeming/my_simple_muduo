#include "EpollPoller.h"
#include <unistd.h>
#include <string.h>
#include "Channel.h"
#include <assert.h>
#include <poll.h>
namespace muduo
{



const int EPOLL_WAIT_TIME = 10000; // epoll_wait timeout time

EpollPoller::EpollPoller(EventLoop *_loop)
    : Poller(_loop),
      m_epoll_fd(::epoll_create1(EPOLL_CLOEXEC)), // 创建epoll对象
      m_events(kInitEventListSize)
{
    if (m_epoll_fd < 0)
    {
        //LOG<<
    }
}

EpollPoller::~EpollPoller()
{
    ::close(m_epoll_fd);
}

void EpollPoller::update(int operation, Channel *_ch)
{
    epoll_event event;
    memset(&event, 0, sizeof event);
    event.events = _ch->events();
    event.data.ptr = _ch;
    int fd = _ch->fd();

    //LOG<<

    if (::epoll_ctl(m_epoll_fd, operation, fd, &event) < 0)
    {
        //LOG
    }
}

const char *EpollPoller::operationToString(int operation)
{
    switch (operation)
    {
    case EPOLL_CTL_ADD:
        return "ADD";
    case EPOLL_CTL_DEL:
        return "DEL";
    case EPOLL_CTL_MOD:
        return "MOD";
    default:

        assert(false && "ERROR_OP");
    }
}

void EpollPoller::updateChannel(Channel *_ch)
{
    Poller::assertInLoopThread();
    ChannelState state = _ch->state();
    //LOG<<
    if (state == ChannelState::kNew || state == ChannelState::kDeleted)
    {
        int fd = _ch->fd();
        if (state == ChannelState::kNew)
        {
            assert(m_channels.find(fd) == m_channels.end()); // 不在channel列表中
            m_channels[fd] = _ch;
        }
        else
        {
            assert(m_channels.find(fd) != m_channels.end()); // ch在channel列表中
            assert(m_channels[fd] == _ch);
        }
        _ch->set_state(ChannelState::kAdded);
        update(EPOLL_CTL_ADD, _ch);
    }
    else //
    {
        int fd = _ch->fd();
        assert(m_channels.find(fd) != m_channels.end());
        assert(m_channels[fd] == _ch);
        assert(state == ChannelState::kAdded);
        if (_ch->isNoneEvevts())
        {
            update(EPOLL_CTL_DEL, _ch);
            _ch->set_state(ChannelState::kDeleted);
        }
        else
        {
            update(EPOLL_CTL_MOD, _ch);
        }
    }
}

void EpollPoller::removeChannel(Channel *_ch)
{
    Poller::assertInLoopThread();
    int fd = _ch->fd();
    //LOG<<
    assert(m_channels.find(fd) != m_channels.end());
    assert(m_channels[fd] == _ch);

    assert(_ch->isNoneEvevts());

    ChannelState state = _ch->state();
    assert(state == ChannelState::kAdded || state == ChannelState::kDeleted);
    size_t n = m_channels.erase(fd);
    assert(n == 1);
    if (state == ChannelState::kAdded)
    {
        update(EPOLL_CTL_DEL, _ch);
    }
    _ch->set_state(ChannelState::kNew);
}

void EpollPoller::poll(ChannelList *activeChannels)
{
    int numEvents = ::epoll_wait(m_epoll_fd,&*m_events.begin(),static_cast<int>(m_events.size()),EPOLL_WAIT_TIME);
    /////
    //hand errors
    //////
    fillActiveChannels(numEvents,activeChannels);

    if(static_cast<size_t>(numEvents) == m_events.size())
    {
        m_events.resize(m_events.size() * 2); // event 缓冲区动态增长
    }
}

void EpollPoller::fillActiveChannels(int numEvents, ChannelList *activeChannels) const
{
    assert(static_cast<size_t>(numEvents) < m_events.size());
    for (int i = 0; i < numEvents; i++)
    {
        auto pchannel = static_cast<Channel *>(m_events[i].data.ptr);

        pchannel->set_revents(m_events[i].events);
        activeChannels->push_back(pchannel);
    }
}
} // namespace muduo