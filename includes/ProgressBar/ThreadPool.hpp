#pragma once

#include "ProgressTracker.hpp"
#include "ProgressBarView.hpp"

#include <thread>
#include <vector>

class ThreadPool
{
public:
    explicit ThreadPool(unsigned long i);
    void Enqueue(int i, ProgressTracker& task, ProgressBarView& view);
    void Execute();
private:
    std::vector<std::thread> mThreads;
};
