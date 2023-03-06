add_executable(
    testprogressbar
        TestCanvas.cpp
        TestPubSub.cpp
        TestView.cpp
)

target_link_libraries(
    testprogressbar
        progressbar
        gmock_main
)
