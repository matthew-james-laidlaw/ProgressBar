#pragma once

#include "Observable.hpp"

#include <chrono>

class ProgressTracker final : public Observable
{
public:
    explicit ProgressTracker(std::chrono::milliseconds delay);
    void Subscribe(Subscriber& sub);
private:
    std::chrono::milliseconds mDelay;
};
