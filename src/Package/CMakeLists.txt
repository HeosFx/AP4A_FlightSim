cmake_minimum_required(VERSION 3.0.0)
project(FlightSim VERSION 0.1.0)

add_library(Package Package.hpp)
set_target_properties(Package PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(Package PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")