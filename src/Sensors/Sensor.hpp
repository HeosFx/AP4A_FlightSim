/**
 * @file Sensor.hpp
 * @author Flavian THEUREL
 * @brief The sensor generates data from its environment
 * @version 0.1
 * @date 2022-10-02
 */

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
protected:
  int m_mean;
  int m_dispertion;

  /**
   * @brief Generates pseudo-random sensor's data
   * 
   * @return int Data generated
   */
  virtual int aleaGenVal();

public:
  Sensor();
  Sensor(const Sensor& sensor_p);
  ~Sensor();
  Sensor& operator=(const Sensor& sensor_p);

  /**
   * @brief Get the value from the sensor
   * 
   * @return int The value
   */
  virtual int getData();
};

#endif