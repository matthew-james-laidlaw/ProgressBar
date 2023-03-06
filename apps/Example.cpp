#include <ProgressBar/ProgressBar.hpp>

#include <chrono>

using ProgressBar::Tracker;
using ProgressBar::View;

using std::chrono::milliseconds;

int main()
{
    Tracker tracker(milliseconds(25));
    
    View view;
    tracker.Subscribe(view);

    return 0;
}
