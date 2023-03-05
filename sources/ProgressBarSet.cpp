#include <ProgressBar/ProgressBarSet.hpp>
#include <ProgressBar/ProgressBarView.hpp>
#include <ProgressBar/Canvas.hpp>
#include <ProgressBar/Terminal.hpp>
#include <ProgressBar/ThreadPool.hpp>

#include <iostream>
#include <thread>

ProgressBarSet::ProgressBarSet(std::vector<ProgressTracker>& tasks)
    : mTasks { tasks }
    , mCanvas { new Terminal }
    , mThreadPool { mTasks.size() }
{}

void ProgressBarSet::Run()
{   
    std::vector<std::thread> threads(mTasks.size());
    std::vector<ProgressBarView> progressBars;
    
    for (int i = 0; i < threads.size(); ++i)
    {
        progressBars.emplace_back(i);
    }
    
    for (int i = 0; i < mTasks.size(); ++i)
    {
        threads[i] = std::thread(&ProgressTracker::Subscribe, std::ref(mTasks[i]), std::ref(progressBars[i]));
    }
    
    for (int i = 0; i < mTasks.size(); ++i)
    {
        threads[i].join();
    }
}
