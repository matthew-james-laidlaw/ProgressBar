add_library(
    progressbar
        Canvas.cpp
        ProgressBarSet.cpp
        Terminal.cpp
        ThreadPool.cpp
        Tracker.cpp
        View.cpp
)

target_include_directories(
    progressbar
        PUBLIC
            ${PROJECT_SOURCE_DIR}/includes
)
