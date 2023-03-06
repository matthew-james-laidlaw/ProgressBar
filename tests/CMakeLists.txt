add_executable(
    testprogressbar
        TestCanvas.cpp
        TestView.cpp
)

target_link_libraries(
    testprogressbar
        progressbar
        gmock_main
)

add_executable(
    testpubsub
        TestPubSub.cpp
        ${CMAKE_SOURCE_DIR}/sources/Terminal.cpp
)

target_link_libraries(
    testpubsub
        gmock_main   
)

target_include_directories(
    testpubsub
        PRIVATE
            ${CMAKE_SOURCE_DIR}/includes   
)
