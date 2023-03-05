#include <ProgressBar/ProgressBar.hpp>

#include <chrono>
#include <vector>

int main()
{
    ProgressTracker t0(std::chrono::milliseconds(50));
    ProgressTracker t1(std::chrono::milliseconds(15));
    ProgressTracker t2(std::chrono::milliseconds(10));
    ProgressTracker t3(std::chrono::milliseconds(25));
    
    std::vector<ProgressTracker> tasks { t0, t1, t2, t3 };
    ProgressBarSet set { tasks };

    set.Run();

    return 0;
}
