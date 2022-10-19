cmake_minimum_required(VERSION 3.0.0)
project(FlightSim VERSION 0.1.0)

find_package(Threads)
add_library(Scheduler Scheduler.hpp Scheduler.cpp)
target_link_libraries(Scheduler PRIVATE Threads::Threads)
target_include_directories(Scheduler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")