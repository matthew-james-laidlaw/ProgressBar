#pragma once

#include "Tracker.hpp"
#include "View.hpp"

#include <thread>
#include <vector>

class ThreadPool
{
public:
    explicit ThreadPool(unsigned long i);
    void Enqueue(int i, ProgressBar::Tracker& task, ProgressBar::View& view);
    void Execute();
private:
    std::vector<std::thread> mThreads;
};
