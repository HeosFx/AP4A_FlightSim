/**
 * @file Sensor.hpp
 * @author Flavian THEUREL
 * @brief The sensor generates data from its environment
 * @version 0.1
 * @date 2022-10-02
 */

#ifndef SENSOR_H
#define SENSOR_H

/**
 * @class Sensor
 * @brief The sensor generates data from its environment
 */
class Sensor
{
private:
  /**
   * @brief Generates pseudo-random sensor's data
   * 
   * @return int Data generated
   */
  virtual int aleaGenVal();

public:
  // As the class has no attribute, there is no need to add the constructors

  virtual ~Sensor();
  Sensor& operator=(const Sensor& sensor_p);

  /**
   * @brief Get the value from the sensor
   * 
   * @return int The value
   */
  int getData();
};

#endif