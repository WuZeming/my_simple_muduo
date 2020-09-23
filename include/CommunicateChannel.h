#ifndef MUDUO_COMMUNICATECHANNEL_H
#define MUDUO_COMMUNICATECHANNEL_H
#include "Channel.h"
#include "EventLoop.h"
#include "InetAddress.h"
#include "Buffer.h"

namespace muduo
{
class TcpApp;
class CommunicateChannel;
using CommuChShPtr = std::shared_ptr<CommunicateChannel>;

class CommunicateChannel: public Channel,
                            public std::enable_shared_from_this<CommunicateChannel>
{
public:
    CommunicateChannel(EventLoop* _loop,
                        int _fd,
                        TcpApp* _owner,
                        const InetAddress& _localAddr, 
                        const InetAddress& _peerAddr, 
                        const std::string& _name );
    ~CommunicateChannel();
    void send(const StringPiece& message);
    void send(Buffer* buff);
    
    void shutdown();
    void forceClose();
    void setHighWaterMark(size_t _mark) {m_highWaterMark = _mark;}
    const std::string name(){return m_name;}
private:

    virtual void handleRead() override;// 处理事件
    virtual void handleWrite() override; 
    virtual void handleClose() override;
    virtual void handleError() override;

    enum StateE { kDisconnected, kConnected, kDisconnecting };

    void setState(StateE s) { m_state = s; }
    void shutdownInLoop();
    void forceCloseInLoop();
    void sendInLoop(const void* data, size_t len);
    StateE m_state;
    
    TcpApp* m_owner;

    const std::string m_name;
    
    const InetAddress m_localAddr;
    
    const InetAddress m_peerAddr;

    size_t m_highWaterMark;
    
    Buffer m_inputBuffer;
    
    Buffer m_outputBuffer;

};

}

#endif