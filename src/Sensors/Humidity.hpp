/**
 * @file Humidity.hpp
 * @author Flavian THEUREL
 * @brief Humidity sensor
 * @version 0.1
 * @date 2022-10-05
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

class Humidity: public Sensor
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