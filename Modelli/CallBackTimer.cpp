#include "CallBackTimer.h"

CallBackTimer::CallBackTimer()
:_execute(false)
{}

CallBackTimer::~CallBackTimer() {
    if( _execute.load(std::memory_order_acquire) ) {
        stop();
    };
}

void CallBackTimer::stop()
{
    _execute.store(false, std::memory_order_release);
    if( _thd.joinable() )
        _thd.join();
}

void CallBackTimer::start(int interval, std::function<void(void)> func)
{
    if( _execute.load(std::memory_order_acquire) ) {
        stop();
    };
    _execute.store(true, std::memory_order_release);
    _thd = std::thread([this, interval, func]()
    {
        while (_execute.load(std::memory_order_acquire)) {
            func();
            std::this_thread::sleep_for(
                std::chrono::milliseconds(interval)
            );
        }
    });
}

bool CallBackTimer::is_running() const noexcept {
    return ( _execute.load(std::memory_order_acquire) &&
             _thd.joinable() );
}
