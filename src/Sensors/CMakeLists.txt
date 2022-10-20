cmake_minimum_required(VERSION 3.0.0)
project(FlightSim VERSION 0.1.0)

add_library(Sensors
            Sensor.hpp     
            Humidity.hpp    Humidity.cpp
            Light.hpp       Light.cpp
            Pressure.hpp    Pressure.cpp
            Temperature.hpp Temperature.cpp)
target_include_directories(Sensors PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")