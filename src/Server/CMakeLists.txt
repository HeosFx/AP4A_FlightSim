cmake_minimum_required(VERSION 3.0.0)
project(FlightSim VERSION 0.1.0)

add_library(Server Server.hpp Server.cpp)
target_include_directories(Server PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")