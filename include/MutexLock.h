#ifndef MUDUO_BASE_MUTEXLOCK_H
#define MUDUO_BASE_MUTEXLOCK_H
#include <pthread.h>
#include "Uncopyable.h"
namespace muduo
{
class MutexLock : Uncopyable // 对互斥锁的操作进行一次封装，锁不可拷贝
{
public:
    MutexLock(){pthread_mutex_init(&_mutex,NULL);}
    ~MutexLock(){pthread_mutex_destroy(&_mutex);}
    void lock() { pthread_mutex_lock(&_mutex); }
    void unlock() { pthread_mutex_unlock(&_mutex); }
    pthread_mutex_t* get(){return &_mutex;}
private:
    /* data */
    pthread_mutex_t _mutex;

};

class MutexGuard : Uncopyable
{
public:
    explicit MutexGuard(MutexLock& mutexlock):_mutexLock(mutexlock){_mutexLock.lock();}
    ~MutexGuard(){_mutexLock.unlock();}
private:
    MutexLock& _mutexLock;
};

} // namespace muduo

#endif //MUDUO_BASE_MUTEXLOCK_H