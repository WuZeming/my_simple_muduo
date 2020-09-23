#include "Channel.h"
#include "Poller.h"
#include "EventLoop.h"
// 为了让用户对channel不可见

namespace muduo
{

Poller::Poller(EventLoop *_loop)
        : m_ownerLoop(_loop)
    {
    }

bool Poller::hasChannel(Channel *_ch) const
{
    assertInLoopThread();
    auto it = m_channels.find(_ch->fd());
    return it!=m_channels.cend() && it->second == _ch;
}

void Poller::assertInLoopThread() const
{
    m_ownerLoop->assertInLoopThread();
}

} // namespace muduo