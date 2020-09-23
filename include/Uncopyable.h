#ifndef MUDUO_BASE_UNCOPYABLE_H
#define MUDUO_BASE_UNCOPYABLE_H

namespace muduo
{
class Uncopyable
{
public:
    Uncopyable(const Uncopyable &) = delete;
    Uncopyable &operator=(const Uncopyable &) = delete;

protected: //可在派生类中构造
    Uncopyable() = default;
    ~Uncopyable() = default;
};
} // namespace muduo

#endif