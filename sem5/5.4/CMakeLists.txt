cmake_minimum_required(VERSION 3.14)
project(Task5_4 LANGUAGES CXX)

if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build the Google Test suite" ON)

add_subdirectory(math_lib)

if(BUILD_TESTS)
    message(STATUS ">>> Сборка тестов ВКЛЮЧЕНА <<<")

    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.tar.gz
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()
    add_subdirectory(tests)
else()
    message(STATUS ">>> Сборка тестов ВЫКЛЮЧЕНА <<<")
endif()

add_executable(main_app main.cpp)
target_link_libraries(main_app PRIVATE my_functions)
