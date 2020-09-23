#ifndef MUDUO_NET_SOCKET_H
#define MUDUO_NET_SOCKET_H
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

namespace muduo 
{
namespace socket
{

int createNonBlockSocket();
void bind(int sockfd, const struct sockaddr_in* addr);
void listen(int sockfd);
int acceptNonBlock(int sockfd, struct sockaddr_in* peeraddr);
int connect(int sockfd, const struct sockaddr_in* addr);
void close(int sockfd);


struct sockaddr_in getLocalAddr(int sockfd);
struct sockaddr_in getPeerAddr(int sockfd);


int getSocketError(int sockfd);
bool isSelfConnect(int sockfd);

void shutdownWrite(int sockfd);
void setReuseAddr(int sockfd, bool on);
void setReusePort(int sockfd, bool on);
int setSocketNonBlocking(int fd);
} // namespace socket

} // namespace muduo

#endif