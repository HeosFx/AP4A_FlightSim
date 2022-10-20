/**
 * @file Pressure.hpp
 * @author Flavian THEUREL
 * @brief Pressure sensor
 * @version 0.2
 * @date 2022-10-19
 */

#ifndef PRESSURE_H
#define PRESSURE_H

#include "Sensor.hpp"
#include <string>

/**
 * @class Pressure
 * @brief Type of sensor (pressure)
 */
class Pressure: public Sensor<int>
{
private:
  /**
 * @brief Generates pseudo-random sensor's data
 * 
 * @return int Data generated
 */
  int aleaGenVal();

public:
  const std::string m_type = "pressure"; // type of the sensor
  const std::string m_unit = "Pa"; // Unit of the value
  
  Pressure();
  Pressure(const Pressure& sensor_p);
  virtual ~Pressure();
  Pressure& operator=(const Pressure& sensor_p);
};

#endif