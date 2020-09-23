#ifndef MUDUO_BASE_CONDITION_H
#define MUDUO_BASE_CONDITION_H

#include<pthread.h>
#include<time.h>
#include<errno.h>
#include"MutexLock.h"
#include"Uncopyable.h"
namespace muduo
{
class Condition : Uncopyable
{
public:
    Condition(MutexLock& mutexlock) :_mutexLock(mutexlock){pthread_cond_init(&_cond,NULL);}
    ~Condition(){pthread_cond_destroy(&_cond);}
    void signal() {pthread_cond_signal(&_cond);}
    void broadcast(){pthread_cond_broadcast(&_cond);}
    void wait() {pthread_cond_wait(&_cond,_mutexLock.get());}
    bool waitForSeconds(int seconds)
    {
        timespec abstime;
        clock_gettime(CLOCK_REALTIME,&abstime);
        abstime.tv_sec+= static_cast<time_t>(seconds);
        return ETIMEDOUT == pthread_cond_timedwait(&_cond,_mutexLock.get(),&abstime);
    }
private:
    MutexLock& _mutexLock;
    pthread_cond_t _cond;

};

}


#endif