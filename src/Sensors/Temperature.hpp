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
#include <string>

/**
 * @class Temperature
 * @brief Type of sensor (temperature)
 */
class Temperature: public Sensor
{
private:
  /**
 * @brief Generates pseudo-random sensor's data
 * 
 * @return int Data generated
 */
  int aleaGenVal();

public:
  const std::string m_type = "temperature"; // type of the sensor
  const std::string m_unit = "K"; // Unit of the value

  virtual ~Temperature();
};

#endif