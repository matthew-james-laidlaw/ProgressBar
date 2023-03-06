#pragma once

#include "Publisher.hpp"

#include <chrono>

namespace ProgressBar
{

class Tracker final : public Publisher
{
public:
    explicit Tracker(std::chrono::milliseconds delay);
    void Subscribe(Subscriber& sub);
private:
    std::chrono::milliseconds mDelay;
};

}
