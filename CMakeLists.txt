cmake_minimum_required(VERSION 3.14)
project(Lab33_Figures)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)
FetchContent_MakeAvailable(googletest)

add_executable(main
    src/main.cpp
)

add_executable(runTests
    tests/FigureTests.cpp
)

target_link_libraries(runTests
    gtest_main
)

enable_testing()
add_test(NAME FigureTests COMMAND runTests)