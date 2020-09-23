#ifndef MUDUO_BASE_THREAD_H
#define MUDUO_BASE_THREAD_H

#include<pthread.h>
#include<functional>
#include"CountDownLatch.h"
#include"Uncopyable.h"
#include<string>
namespace muduo
{

class Thread :Uncopyable
{
public:
    using ThreadFun = std::function<void()>;
    explicit Thread(const ThreadFun& _fun, const std::string& _name = std::string());
    ~Thread();
    void start();
    int join();
    bool isStarted() const {return m_started;}
    pid_t tid() const {return m_tid;}
    const std::string& threadName() const {return m_thread_name;}

private:

    bool m_started;
    bool m_joined;
    ThreadFun m_fun;
    CountDownLatch m_latch;
    std::string m_thread_name;
    pthread_t m_threadId;
    pid_t m_tid;
};


namespace CurrentThread
{
    extern __thread pid_t curr_tid;
    extern __thread char curr_tidString[32];
    extern __thread int curr_tidStringLen;
    extern __thread const char* curr_threadName;
    void catchTid();
    inline pid_t tid()
    {
        if(__builtin_expect(curr_tid == 0,0))
        {
            catchTid();
        }
        return curr_tid;
    }
    inline const char* tidString()
    {
        return curr_tidString;
    }
    inline int tidStringLen()
    {
        return curr_tidStringLen;
    }
    inline const char* threadName()
    {
        return curr_threadName;
    } 
}

}

#endif