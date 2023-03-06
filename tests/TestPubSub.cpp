#include <gtest/gtest.h>
#include <ProgressBar/ProgressBar.hpp>
#include <chrono>

using ProgressBar::Tracker;
using ProgressBar::View;
using std::chrono::milliseconds;

TEST(PubSub, PubSub)
{
    Tracker tracker(milliseconds(25));
    
    View view;
    tracker.Subscribe(view);
}
