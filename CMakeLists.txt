cmake_minimum_required(VERSION 3.10)

project(MyMuduo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER "g++")



add_executable(EchoServer main_server.cpp)
target_link_libraries(EchoServer MyMuduoLib)
target_include_directories(EchoServer PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(EchoClient main_client.cpp)
target_link_libraries(EchoClient MyMuduoLib)
target_include_directories(EchoClient PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

