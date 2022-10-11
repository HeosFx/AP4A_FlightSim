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
#include <string>

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

public:
  const std::string m_type = "light"; // type of the sensor
  const std::string m_unit = "L"; // Unit of the value

  virtual ~Light();
};

#endif