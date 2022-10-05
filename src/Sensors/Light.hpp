/**
 * @file Light.hpp
 * @author Flavian THEUREL
 * @brief Light sensor
 * @version 0.1
 * @date 2022-10-05
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"

/**
 * @class Light
 * @brief Type of sensor (light)
 */
class Light: public Sensor
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