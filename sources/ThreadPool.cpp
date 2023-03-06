#include <ProgressBar/ThreadPool.hpp>
#include <ProgressBar/Tracker.hpp>
#include <ProgressBar/View.hpp>

using ProgressBar::Tracker;
using ProgressBar::View;

ThreadPool::ThreadPool(unsigned long i)
    : mThreads { 0 }
{}

void ThreadPool::Enqueue(int i, Tracker& task, View& view)
{
    mThreads.emplace_back(&Tracker::Subscribe, std::ref(task), std::ref(view));
}

void ThreadPool::Execute()
{
    for (auto& thread : mThreads)
    {
        thread.join();
    }
}
