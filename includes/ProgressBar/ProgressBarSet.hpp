#pragma once

#include "ProgressTracker.hpp"

#include <vector>

class ProgressBarSet
{
public:
    ProgressBarSet(std::vector<ProgressTracker>& tasks);
    void Run();
private:
    void PreRun();
    void PostRun();
    std::vector<ProgressTracker>& mTasks;
};
