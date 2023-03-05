add_library(
    progressbar
        ProgressTracker.cpp
        ProgressBarSet.cpp
        ProgressBarView.cpp        
)

target_include_directories(
    progressbar
        PUBLIC
            ${PROJECT_SOURCE_DIR}/includes
)
