cmake_minimum_required(VERSION 3.0.0)
project(FlightSim VERSION 0.1.0)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../Simulation)

add_subdirectory(Package)
add_subdirectory(Sensors)
add_subdirectory(Server)
add_subdirectory(Scheduler)

add_executable(FlightSim main.cpp)
target_link_libraries(FlightSim PRIVATE Scheduler Package Server Sensors)

set_property(TARGET FlightSim PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../Simulation")