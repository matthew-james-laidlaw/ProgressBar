#include <ProgressBar/ThreadPool.hpp>
#include <ProgressBar/ProgressTracker.hpp>
#include <ProgressBar/ProgressBarView.hpp>

ThreadPool::ThreadPool(unsigned long i)
    : mThreads { 0 }
{}

void ThreadPool::Enqueue(int i, ProgressTracker& task, ProgressBarView& view)
{
    mThreads.emplace_back(&ProgressTracker::Subscribe, std::ref(task), std::ref(view));
}

void ThreadPool::Execute()
{
    for (auto& thread : mThreads)
    {
        thread.join();
    }
}
