
#include"Socket.h"
#include<errno.h>
#include<sys/fcntl.h>
namespace muduo 
{

namespace socket
{

void bind(int fd, const struct sockaddr_in* addr)
{

    int res = ::bind(fd,(const struct sockaddr*)addr,sizeof(sockaddr_in));
    if(res<0){
        close(fd);
        //LOG<<
    }
}

void listen(int fd)
{
    int res = ::listen(fd,SOMAXCONN);
    if(res<0)
    {
        close(fd);
        //LOG<<
    }
}

int acceptNonBlock(int fd, struct sockaddr_in* peeraddr)
{
    socklen_t addrlen = static_cast<socklen_t>(sizeof (sockaddr_in));

    int connfd = ::accept4(fd,(struct sockaddr*)peeraddr,&addrlen,SOCK_NONBLOCK|SOCK_CLOEXEC);
    if(connfd<0)
    {
        //LOG<<
    }
    return connfd;

}




struct sockaddr_in getLocalAddr(int sockfd)
{
    struct sockaddr_in localaddr;
    bzero(&localaddr, sizeof localaddr);
    socklen_t addrlen = static_cast<socklen_t>(sizeof localaddr);
    if (::getsockname(sockfd, (sockaddr*)(&localaddr), &addrlen) < 0)
    {
        //LOG_FATAL("getsockname fial");
    }
    return localaddr;
}


struct sockaddr_in getPeerAddr(int sockfd)
{
  struct sockaddr_in peeraddr;
  bzero(&peeraddr, sizeof peeraddr);
  socklen_t addrlen = static_cast<socklen_t>(sizeof peeraddr);
  if (::getpeername(sockfd, (sockaddr*)(&peeraddr), &addrlen) < 0)
  {
    //LOG_FATAL("getpeername fial");
  }
  return peeraddr;
}

int createNonBlockSocket()
{
    int sockfd = ::socket(AF_INET, SOCK_STREAM | 
                                  SOCK_NONBLOCK | 
                                  SOCK_CLOEXEC, IPPROTO_TCP);
    if (sockfd < 0)
    {
        //LOG_FATAL("createSocket fail, errno=%d");
    }
    return sockfd;
}

int connect(int sockfd, const struct sockaddr_in* addr)
{
    return ::connect(sockfd, (const struct sockaddr*)addr, static_cast<socklen_t>(sizeof(struct sockaddr_in)));
}

void close(int sockfd)
{
    if (::close(sockfd) < 0)
    {
        //LOG_ERROR("close fd=%d fail");
    }
}

int getSocketError(int sockfd)
{
    int optval;
    socklen_t optlen = static_cast<socklen_t>(sizeof optval);

    if (::getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &optval, &optlen) < 0)
    {
        return errno;
    }
    else
    {
        return optval;
    }
}

bool isSelfConnect(int sockfd)
{
    struct sockaddr_in localaddr = getLocalAddr(sockfd);
    struct sockaddr_in peeraddr = getPeerAddr(sockfd);
    if (localaddr.sin_family == AF_INET)
    {
        const struct sockaddr_in* laddr4 = reinterpret_cast<struct sockaddr_in*>(&localaddr);
        const struct sockaddr_in* raddr4 = reinterpret_cast<struct sockaddr_in*>(&peeraddr);
        return (laddr4->sin_port == raddr4->sin_port)
            && (laddr4->sin_addr.s_addr == raddr4->sin_addr.s_addr);
    }
    else
    {
        return false;
    }
}

void shutdownWrite(int sockfd)
{
    if (::shutdown(sockfd, SHUT_WR) < 0)
    {
        //LOG_ERROR("shutdownWrite error");
    }
}


void setReuseAddr(int sockfd, bool on)
{
    int opt = on ? 1 : 0;
    ::setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, socklen_t(sizeof opt));
}

void setReusePort(int sockfd, bool on)
{
    int opt = on ? 1 : 0;
    int ret = ::setsockopt(sockfd, SOL_SOCKET, SO_REUSEPORT, &opt, socklen_t(sizeof opt));
    if (ret < 0 && on)
    {
        //LOG_ERROR("REUSEPORT failed ret=%d");
    }
}

int setSocketNonBlocking(int fd) {
  int flag = fcntl(fd, F_GETFL, 0);
  if (flag == -1) return -1;

  flag |= O_NONBLOCK;
  if (fcntl(fd, F_SETFL, flag) == -1) return -1;
  return 0;
}


} // namespace socket

} // namespace muduo
