
#include "InetAddress.h"
// #include "Logging.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <endian.h>
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace muduo;

InetAddress::InetAddress(uint16_t port, bool loopbackOnly)
{
    
    bzero(&addr_, sizeof addr_);
    addr_.sin_family = AF_INET;
    in_addr_t ip = loopbackOnly ? INADDR_LOOPBACK : INADDR_ANY;
    addr_.sin_addr.s_addr = htobe32(ip);
    addr_.sin_port = htobe16(port);
    
}

InetAddress::InetAddress(const char* ip, uint16_t port)
{

    
    bzero(&addr_, sizeof addr_);
    addr_.sin_family = AF_INET;
    addr_.sin_port = htobe16(port);
    if (::inet_pton(AF_INET, ip, &addr_.sin_addr) <= 0)
    {
        //muduo::LOG_FATAL("IPaddress Error");
    }
    
}

std::string InetAddress::toIpPort() const
{
    char buf[64] = "";
    size_t size = sizeof(buf);
    
    uint16_t port;
    
    assert(size >= INET_ADDRSTRLEN);
    port = be16toh(addr_.sin_port);
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, static_cast<socklen_t>(size));
    
    size_t end = ::strlen(buf);
    assert(size > end);
    snprintf(buf+end, size-end, ":%u", port);

    return buf;
}

std::string InetAddress::toIp() const
{
    char buf[64] = "";
    size_t size = sizeof(buf);

    assert(size >= INET_ADDRSTRLEN);
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, static_cast<socklen_t>(size));
    

    return buf;
}

