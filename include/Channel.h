#ifndef MUDUO_NET_CHANNEL_H
#define MUDUO_NET_CHANNEL_H

#include"Uncopyable.h"
#include<functional>
#include"EventLoop.h"

namespace muduo
{

enum class ChannelState{kNew,kAdded,kDeleted};

class Channel : Uncopyable
{
public:
    Channel(EventLoop* loop,int fd);
    virtual ~Channel();

    void handleEvent(); // 处理监听到的事件
    void enableReadEvent(); // 监听事件设置
    void disableReadEvent();
    void enableWriteEvent();
    void disableWriteEvent();
    void disableAllEvent();
    void rmThisFromLoop();

    bool isNoneEvevts() const; // 返回监听的事件
    bool isReadEvent() const;
    bool isWriteEvent() const;

    int fd() const;

    int events() const;
    void set_revents(int _revents);

    ChannelState state() const;
    void set_state(ChannelState _state);
    
    EventLoop* ownerLoop() const;

protected:
    void updateThisInEventLoop();
    virtual void handleRead() {};// 处理事件
    virtual void handleWrite(){}; 
    virtual void handleClose(){};
    virtual void handleError(){};

    EventLoop* mp_loop; // 所属循环，即被哪个线程循环监听
    int m_fd;     // 所监听的文件描述符
private:
    int m_events;       // 监听的事件
    int m_revents;      // 监听到的发生的事件
    ChannelState m_state;        // used by poller,记录自己在Poller中的状态，自动执行增删改

};
} // muduo
#endif // MUDUO_NET_CHANNEL_H