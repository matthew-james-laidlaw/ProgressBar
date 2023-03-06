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
    std::vector<ProgressBarView> progressBars;

    for (int i = 0; i < mTasks.size(); ++i)
    {
        progressBars.emplace_back(i);
        mThreadPool.Enqueue(i, mTasks[i], progressBars[i]);
    }

    mThreadPool.Execute();
}
