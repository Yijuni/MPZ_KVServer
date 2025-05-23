#ifndef AFTERTIMER_HPP
#define AFTERTIMER_HPP
/**
 * 2025-4-24 moyoj
 * 设计了一个定时器，可以传入回调函数，可以设置时间，可以重置时间
 * 时间到达后执行回调函数
 */
#include <functional>
#include <atomic>
#include <condition_variable>
#include <memory>
#include<thread>
using AfterTimerCallback = std::function<void()>;
class AfterTimer:public std::enable_shared_from_this<AfterTimer>
{
public:
    /// @brief 
    /// @param timelen 时间大小
    /// @param type 事件类型（秒、毫秒) 0：毫秒 1：秒
    /// @param callback 回调函数
    AfterTimer(double timelen = 1000, int type = 1, AfterTimerCallback callback = []() {});
    void SetTime(double timelen, int type);
    // Reset只执行一次，要想再次执行需要再调用Reset
    bool Reset();
    bool RandomReset(double begin,double end);
    void SetCallback(AfterTimerCallback);
    void run();
    ~AfterTimer();

private:
    AfterTimerCallback callback_myj;
    std::atomic<double> timelen_myj;
    std::atomic<double> type_myj;
    std::atomic<bool> running_myj;
    std::atomic<double> timecount_myj;
    std::atomic<bool> isReset;
    std::atomic<bool> created_myj;
    std::shared_ptr<std::thread> td_myj;
};
#endif