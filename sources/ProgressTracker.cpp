#include <ProgressBar/ProgressTracker.hpp>
#include <ProgressBar/ProgressBarSet.hpp>
#include <ProgressBar/ProgressBarView.hpp>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

ProgressTracker::ProgressTracker(std::chrono::milliseconds delay)
    : mDelay { delay }
{}
    
void ProgressTracker::Subscribe(Subscriber& sub)
{
    for (int i = 0; i < 32; ++i)
    {
        int percentComplete = (int)(float(i) / 32);
        sub.Update(percentComplete);
        std::this_thread::sleep_for(mDelay);
    }
}
