#pragma once

#include "Tracker.hpp"
#include "Canvas.hpp"
#include "ThreadPool.hpp"

#include <vector>

class ProgressBarSet
{
public:
    ProgressBarSet(std::vector<ProgressBar::Tracker> &tasks);
    void Run();
private:
    std::vector<ProgressBar::Tracker> &mTasks;
    Canvas mCanvas;
    ThreadPool mThreadPool;
};
