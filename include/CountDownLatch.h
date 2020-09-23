#ifndef MUDUO_BASE_COUNTDOWNLATCH_H
#define MUDUO_BASE_COUNTDOWNLATCH_H

#include"MutexLock.h"
#include"Condition.h"

namespace muduo
{
class CountDownLatch
{
public:
    explicit CountDownLatch(int _count)
        :m_count(_count),
        m_mutex(),
        m_cond(m_mutex)
        {}
    void wait()
    {
        MutexGuard lock(m_mutex);
        while (m_count>0)
        {
            m_cond.wait();
        }
        
    }
    void countDown()
    {
        MutexGuard lock(m_mutex);
        m_count--;
        if(m_count == 0)
        {
            m_cond.broadcast();
        }
    }
private:
    int m_count;
    MutexLock m_mutex;
    Condition m_cond;

};
}


#endif 