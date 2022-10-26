/**
 * @file Sensor.hpp
 * @author Flavian THEUREL
 * @brief The sensor generates data from its environment
 * @version 0.2
 * @date 2022-10-19
 */

#ifndef SENSOR_H
#define SENSOR_H

/**
 * @class Sensor
 * @brief The sensor generates data from its environment
 * @tparam T The type of the data measured by the sensor
 */
template <typename T> class Sensor
{
private:
  /**
   * @brief Generates pseudo-random sensor's data
   * 
   * @return T Data generated
   */
  virtual T aleaGenVal()=0;

public:
  Sensor<T>(){};
  Sensor<T>(const Sensor& sensor_p){};
  virtual ~Sensor<T>(){};
  Sensor& operator=(const Sensor& sensor_p){};

  /**
   * @brief Get the value from the sensor
   * 
   * @return T The value
   */
  T getData()
  {
    return aleaGenVal();
  };
};

#endif