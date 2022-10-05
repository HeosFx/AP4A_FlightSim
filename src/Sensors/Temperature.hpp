/**
 * @file Temperature.hpp
 * @author Flavian THEUREL
 * @brief Temperature sensor
 * @version 0.1
 * @date 2022-10-02
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"

class Temperature: public Sensor
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