cmake_minimum_required(VERSION 3.0.0)
project(FlightSim VERSION 0.1.0)

add_subdirectory(Package)
add_subdirectory(Sensors)
add_subdirectory(Server)
add_subdirectory(Scheduler)

add_executable(FlightSim main.cpp)
target_link_libraries(FlightSim PRIVATE Scheduler Package Server Sensors)