add_executable(
    testprogressbar
        TestCanvas.cpp
)

target_link_libraries(
    testprogressbar
        progressbar
        gmock_main
)
