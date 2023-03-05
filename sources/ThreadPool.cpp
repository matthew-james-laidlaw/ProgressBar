#include <ProgressBar/ThreadPool.hpp>
#include <ProgressBar/ProgressTracker.hpp>
#include <ProgressBar/ProgressBarView.hpp>

ThreadPool::ThreadPool(unsigned long i)
    : mThreads { i }
{}

void ThreadPool::Enqueue(int i, ProgressTracker& task, ProgressBarView& view)
{
    mThreads[i] = std::thread(&ProgressTracker::Subscribe, std::ref(task), std::ref(view));
}

void ThreadPool::Execute()
{
    for (auto& thread : mThreads)
    {
        thread.join();
    }
}
