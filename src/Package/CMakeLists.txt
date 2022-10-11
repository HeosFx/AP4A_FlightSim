cmake_minimum_required(VERSION 3.0.0)
project(FlightSim VERSION 0.1.0)

add_library(Package Package.hpp Package.cpp)
target_include_directories(Package PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")