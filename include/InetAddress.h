#ifndef MUDUO_NET_INETADDRESS_H
#define MUDUO_NET_INETADDRESS_H

#include <string>
#include <stdint.h>
#include <netinet/in.h>



namespace muduo
{

///
/// Wrapper of sockaddr_in.
///
/// This is an POD interface class.
class InetAddress 
{
public:
    /// Constructs an endpoint with given port number.
    /// Mostly used in TcpServer listening.
    explicit InetAddress(uint16_t port = 0, bool loopbackOnly = false);

    /// Constructs an endpoint with given ip and port.
    /// @c ip should be "1.2.3.4"
    InetAddress(const char* ip, uint16_t port);

    /// Constructs an endpoint with given struct  sockaddr_in
    /// Mostly used when accepting new connections
    explicit InetAddress(const struct sockaddr_in& addr)
    : addr_(addr)
    { }
    
    
    std::string toIpPort() const;
    
    std::string toIp() const;
    
    const struct sockaddr_in* getSockAddr() const
    {
        return &addr_;
    }
    
    void setSockAddr(const struct sockaddr_in& addr) 
    { addr_ = addr; }
    
private:

    struct sockaddr_in  addr_;

};

}

#endif  // MUDUO_INETADDRESS_H_

