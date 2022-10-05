/**
 * @file Pressure.hpp
 * @author Flavian THEUREL
 * @brief Pressure sensor
 * @version 0.1
 * @date 2022-10-05
 */

#ifndef PRESSURE_H
#define PRESSURE_H

#include "Sensor.hpp"

/**
 * @class Pressure
 * @brief Type of sensor (pressure)
 */
class Pressure: public Sensor
{
private:
  /**
 * @brief Generates pseudo-random sensor's data
 * 
 * @return int Data generated
 */
  int aleaGenVal();
};

#endif