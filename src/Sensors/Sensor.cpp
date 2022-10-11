/**
 * @file Sensor.cpp
 * @author Flavian THEUREL
 * @brief The sensor generates data from its environment
 * @version 0.1
 * @date 2022-10-02
 */

#include "Sensor.hpp"

Sensor::~Sensor()
{
}

Sensor& Sensor::operator=(const Sensor& sensor_p)
{
  return *this;
}

int Sensor::getData()
{
  return aleaGenVal();
}

int Sensor::aleaGenVal()
{
  return -1;
}