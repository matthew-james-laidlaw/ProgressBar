add_executable(
    example
        example.cpp

        ${CMAKE_SOURCE_DIR}/sources/Terminal.cpp
)
target_include_directories(example PUBLIC ${CMAKE_SOURCE_DIR}/includes)
