add_library(
    progressbar
        Canvas.cpp
        ProgressTracker.cpp
        ProgressBarSet.cpp
        ProgressBarView.cpp
        Terminal.cpp
        ThreadPool.cpp
        View.cpp
)

target_include_directories(
    progressbar
        PUBLIC
            ${PROJECT_SOURCE_DIR}/includes
)
