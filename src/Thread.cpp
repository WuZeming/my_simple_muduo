#include "Thread.h"
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <unistd.h>
#include <assert.h>

namespace muduo
{
namespace CurrentThread
{
__thread pid_t curr_tid = 0;
__thread char curr_tidString[32];
__thread int curr_tidStringLen = 6;
__thread const char *curr_threadName = "default";

pid_t gettid() { return static_cast<pid_t>(::syscall(SYS_gettid)); }

void catchTid()
{
    if (curr_tid == 0)
    {
        curr_tid = gettid();
        //将tid转为字符串存储
        curr_tidStringLen = snprintf(curr_tidString, sizeof curr_tidString, "%5d", curr_tid);
    }
}
} // namespace CurrentThread

struct ThreadData // 作为线程函数的参数传入，主要是为了将线程类中的成员地址传入线程中，以设定和使用线程类成员
{
    Thread::ThreadFun *pFun;
    CountDownLatch *pLatch;
    pid_t *ptid;
    std::string threadName;
    ThreadData(Thread::ThreadFun *_pfun, CountDownLatch *_pLatch, pid_t *_tid, const std::string &_name)
        : pFun(_pfun),
          pLatch(_pLatch),
          ptid(_tid),
          threadName(_name)
    {
    }
    void runInThread()
    {
        *ptid = CurrentThread::tid();
        ptid = nullptr;
        pLatch->countDown(); // 通知主线程start可以返回。
        pLatch = nullptr;
        CurrentThread::curr_threadName = threadName.empty() ? "Thread" : threadName.c_str();

        (*pFun)();                                          //调用设定的线程函数
        
        prctl(PR_SET_NAME, CurrentThread::curr_threadName); // 给当前线程命名
        CurrentThread::curr_threadName = "finished";
    }
};

void *threadFun(void *data)
{
    ThreadData *pdata = static_cast<ThreadData *>(data);
    pdata->runInThread();
    delete pdata;
    return nullptr;
}

Thread::Thread(const ThreadFun &_fun, const std::string &_name)
    : m_joined(false),
      m_started(false),
      m_fun(_fun),
      m_latch(1),
      m_thread_name(_name),
      m_threadId(0),
      m_tid(0)
{
    if (m_thread_name.empty())
    {
        m_thread_name = "Thread";
    }
}
Thread::~Thread()
{
    if (m_started && !m_joined)
        pthread_detach(m_threadId);
}

void Thread::start()
{
    assert(!m_started); // 确保一个线程对象只能开一个线程
    m_started = true;
    auto data = new ThreadData(&m_fun, &m_latch, &m_tid, m_thread_name);
    if (pthread_create(&m_threadId, NULL, &threadFun, data))
    {
        m_started = false;
        delete data;
    }
    else
    {
        m_latch.wait(); // 等待新创建的线程执行后再返回
        assert(m_tid > 0);
    }
}

int Thread::join()
{
    assert(m_started);
    assert(!m_joined);
    m_joined = true;
    return pthread_join(m_threadId, NULL);
}

} // namespace muduo
