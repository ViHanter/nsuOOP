cmake_minimum_required(VERSION 3.14)
project(Task5_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(my_functions STATIC hypo.cpp mod_hypo.cpp)
target_include_directories(my_functions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(main_app main.cpp)
target_link_libraries(main_app PRIVATE my_functions)
