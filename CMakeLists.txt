cmake_minimum_required(VERSION 3.30 FATAL_ERROR)

project(CPP)

add_executable(CPP src/main.cpp)
add_subdirectory(external/glfw)
target_link_libraries(CPP glfw)