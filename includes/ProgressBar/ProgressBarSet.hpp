#pragma once

#include "ProgressTracker.hpp"
#include "Canvas.hpp"
#include "ThreadPool.hpp"

#include <vector>

class ProgressBarSet
{
public:
    ProgressBarSet(std::vector<ProgressTracker> &tasks);
    void Run();
private:
    std::vector<ProgressTracker> &mTasks;
    Canvas mCanvas;
    ThreadPool mThreadPool;
};
