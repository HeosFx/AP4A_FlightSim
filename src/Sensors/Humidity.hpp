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
#include <string>

/**
 * @class Humidity
 * @brief Type of sensor (humidity)
 */
class Humidity: public Sensor
{
private:
  /**
 * @brief Generates pseudo-random sensor's data
 * 
 * @return int Data generated
 */
  int aleaGenVal();

public:
  const std::string m_type = "humidity"; // type of the sensor
  const std::string m_unit = "%"; // Unit of the value

  virtual ~Humidity();
};

#endif