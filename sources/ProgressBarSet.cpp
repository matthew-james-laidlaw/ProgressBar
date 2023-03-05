#include <ProgressBar/ProgressBarSet.hpp>
#include <ProgressBar/ProgressBarView.hpp>

#include <iostream>
#include <thread>

ProgressBarSet::ProgressBarSet(std::vector<ProgressTracker>& tasks)
    : mTasks { tasks }
{}

void ProgressBarSet::Run()
{
    PreRun();
    
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
    
    std::cout << "\x1B[" << std::to_string(mTasks.size() + 2) << ";0H";
    
    PostRun();
}
    
void ProgressBarSet::PreRun()
{
    std::cout << "\x1B 7";     // save current cursor location
    std::cout << "\x1B[?25l";  // make cursor invisible
}
    
void ProgressBarSet::PostRun()
{
    std::cout << "\x1B[?25h";  // make cursor visible
}