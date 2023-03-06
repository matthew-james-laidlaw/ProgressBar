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

void Tracker::Subscribe(Subscriber& subscriber)
{
    for (int i = 0; i < 16; ++i)
    {
        subscriber.Update();
        std::this_thread::sleep_for(mDelay);
    }
}
