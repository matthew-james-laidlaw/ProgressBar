#include <ProgressBar/Tracker.hpp>
#include <ProgressBar/ProgressBarSet.hpp>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using ProgressBar::Tracker;

Tracker::Tracker(std::chrono::milliseconds delay)
    : mDelay { delay }
{}

void Tracker::Subscribe(Subscriber& sub)
{
    for (int i = 0; i < 32; ++i)
    {
        int percentComplete = (int)(float(i) / 32);
        sub.Update();
        std::this_thread::sleep_for(mDelay);
    }
}
