/**
 * @file Temperature.hpp
 * @author Flavian THEUREL
 * @brief Temperature sensor
 * @version 0.2
 * @date 2022-10-19
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"
#include <string>

/**
 * @class Temperature
 * @brief Type of sensor (temperature)
 */
class Temperature: public Sensor<float>
{
private:
  /**
 * @brief Generates pseudo-random sensor's data
 * 
 * @return float Data generated
 */
  float aleaGenVal();

public:
  const std::string m_type = "temperature"; // type of the sensor
  const std::string m_unit = "K"; // Unit of the value

  Temperature();
  Temperature(const Temperature& sensor_p);
  virtual ~Temperature();
  Temperature& operator=(const Temperature& sensor_p);
};

#endif