#include"EchoServer.h"
#include<iostream>

int main()
{
    EventLoop loop;
    InetAddress addr(11000);
    EchoServer server(&loop,addr);
    server.start();
    std::cout<<"server started"<< std::endl;
    loop.loop();
    return 0;
}