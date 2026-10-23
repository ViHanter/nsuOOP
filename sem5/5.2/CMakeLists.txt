cmake_minimum_required(VERSION 3.14)
project(Task5_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(math_lib)

add_executable(main_app main.cpp)
target_link_libraries(main_app PRIVATE my_functions)
