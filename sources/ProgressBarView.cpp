#include <ProgressBar/ProgressBarView.hpp>

#include <iostream>
#include <mutex>

std::mutex ProgressBarView::stdoutMutex;

ProgressBarView::ProgressBarView(int mTerminalRowIndex)
    : mBuffer { "[                                ] " + std::to_string(mTerminalRowIndex + 1) }
    , mCurrentItem { 1 }
    , mTerminalRowIndex { mTerminalRowIndex }
{}
  
void ProgressBarView::Update(double percentComplete)
{
    mBuffer[mCurrentItem] = '=';
    ++mCurrentItem;

    Draw();
}
    
void ProgressBarView::Draw()
{
    std::lock_guard<std::mutex> mBufferLock(ProgressBarView::stdoutMutex);
    std::cout << "\x1B[" << std::to_string(mTerminalRowIndex + 2) << ";0H";
    std::cout << mBuffer << std::endl;
}
