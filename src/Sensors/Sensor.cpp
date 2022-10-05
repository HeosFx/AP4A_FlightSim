/**
 * @file Sensor.cpp
 * @author Flavian THEUREL
 * @brief The sensor generates data from its environment
 * @version 0.1
 * @date 2022-10-02
 */

#include "Sensor.hpp";

Sensor::Sensor(): m_mean(), m_dispertion()
{
}

Sensor::Sensor(const Sensor& sensor_p): m_mean(sensor_p.m_mean), m_dispertion(sensor_p.m_dispertion)
{
}

Sensor::~Sensor()
{
}

Sensor& Sensor::operator=(const Sensor& sensor_p)
{
  m_mean = sensor_p.m_mean;
  m_dispertion = sensor_p.m_dispertion;
  return *this;
}

int Sensor::getData()
{
  int value = aleaGenVal();
  return value;
}