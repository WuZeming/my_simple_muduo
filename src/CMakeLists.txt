set(SRC
    Buffer.cpp
    Channel.cpp
    CommunicateChannel.cpp
    ConnectChannel.cpp 
    EpollPoller.cpp 
    EventLoop.cpp 
    EventLoopThread.cpp 
    EventLoopThreadPool.cpp 
    InetAddress.cpp 
    ListenChannel.cpp 
    Poller.cpp 
    Socket.cpp 
    TcpClient.cpp 
    TcpServer.cpp 
    Thread.cpp)


add_library(MyMuduoLib ${SRC})

target_include_directories(MyMuduoLib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(MyMuduoLib pthread rt)

set_target_properties(MyMuduoLib PROPERTIES OUTPUT_NAME "MyMuduolib")
