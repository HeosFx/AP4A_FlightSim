/**
 * @file Humidity.hpp
 * @author Flavian THEUREL
 * @brief Humidity sensor
 * @version 0.2
 * @date 2022-10-19
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"
#include <string>

/**
 * @class Humidity
 * @brief Type of sensor (humidity)
 */
class Humidity: public Sensor<float>
{
private:
  /**
 * @brief Generates pseudo-random sensor's data
 * 
 * @return float Data generated
 */
  float aleaGenVal();

public:
  const std::string m_type = "humidity"; // type of the sensor
  const std::string m_unit = "%"; // Unit of the value

  Humidity();
  Humidity(const Humidity& sensor_p);
  virtual ~Humidity();
  Humidity& operator=(const Humidity& sensor_p);
};

#endif