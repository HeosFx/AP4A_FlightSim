/**
 * @file Light.hpp
 * @author Flavian THEUREL
 * @brief Light sensor
 * @version 0.2
 * @date 2022-10-19
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"
#include <string>

/**
 * @class Light
 * @brief Type of sensor (light)
 */
class Light: public Sensor<bool>
{
private:
  /**
 * @brief Generates pseudo-random sensor's data
 * 
 * @return bool Data generated
 */
  bool aleaGenVal();

public:
  const std::string m_type = "light"; // type of the sensor
  const std::string m_unit; // Unit of the value
  
  Light();
  Light(const Light& sensor_p);
  virtual ~Light();
  Light& operator=(const Light& sensor_p);
};

#endif