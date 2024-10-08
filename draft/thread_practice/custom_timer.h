#include <windows.h>

class stop_watch
{
public:
    stop_watch()
        : elapsed_(0)
    {
        QueryPerformanceFrequency(&freq_);
    }
    ~stop_watch() {}

public:
    void start()
    {
        QueryPerformanceCounter(&begin_time_);
    }

    void stop()
    {
        LARGE_INTEGER end_time;
        QueryPerformanceCounter(&end_time);
        elapsed_ += (end_time.QuadPart - begin_time_.QuadPart) * 1000000 / freq_.QuadPart;
    }

    void restart()
    {
        elapsed_ = 0;
        start();
    }

    // 微秒
    double elapsed() const
    {
        return static_cast<double>(elapsed_);
    }

    // 毫秒
    double elapsed_ms() const
    {
        return elapsed_ / 1000.0;
    }

    // 秒
    double elapsed_seconds() const
    {
        return elapsed_ / 1000000.0;
    }

private:
    LARGE_INTEGER freq_;
    LARGE_INTEGER begin_time_;
    long long elapsed_;
};
