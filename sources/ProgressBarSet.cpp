#include <ProgressBar/ProgressBarSet.hpp>
#include <ProgressBar/View.hpp>
#include <ProgressBar/Canvas.hpp>
#include <ProgressBar/Terminal.hpp>
#include <ProgressBar/ThreadPool.hpp>
#include <ProgressBar/Tracker.hpp>

#include <iostream>
#include <thread>

using ProgressBar::Tracker;
using ProgressBar::View;

ProgressBarSet::ProgressBarSet(std::vector<Tracker>& tasks)
    : mTasks { tasks }
    , mCanvas { new Terminal }
    , mThreadPool { mTasks.size() }
{}

void ProgressBarSet::Run()
{
    std::vector<std::thread> threads(mTasks.size());
    std::vector<View> progressBars(mTasks.size());
    
    for (int i = 0; i < threads.size(); ++i)
    {
        progressBars[i] = View();
    }
    
    for (int i = 0; i < mTasks.size(); ++i)
    {
        threads[i] = std::thread(&Tracker::Subscribe, std::ref(mTasks[i]), std::ref(progressBars[i]));
    }
    
    for (int i = 0; i < mTasks.size(); ++i)
    {
        threads[i].join();
    }
}
