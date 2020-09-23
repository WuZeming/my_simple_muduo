#include"EchoClient.h"

int main()
{
    EventLoop loop;
    InetAddress addr(11000,true);

    EchoClient client(&loop,addr);
    client.connect();
    loop.loop();
    return 0;
}