#pragma once

#include "Subscriber.hpp"

#include <string>
#include <mutex>

class ProgressBarView final : public Subscriber
{
public:
    static std::mutex stdoutMutex;
    explicit ProgressBarView(int mTerminalRowIndex);
    void Update(int percentComplete);
private:
    void Draw();  
    std::string mBuffer;
    int mCurrentItem;
    int mTerminalRowIndex;
};
