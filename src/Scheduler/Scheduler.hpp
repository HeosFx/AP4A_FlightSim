/**
 * @file Scheduler.hpp
 * @author Flavian THEUREL
 * @brief Class that trasmits data from the sensors to the server at a predetermined time
 * @version 0.1
 * @date 2022-10-05
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "../Server/Server.hpp"
#include "../Sensors/Sensor.hpp"
#include "../Sensors/Temperature.hpp"
#include "../Sensors/Humidity.hpp"
#include "../Sensors/Pressure.hpp"
#include "../Sensors/Light.hpp"

/**
 * @class Scheduler 
 * @brief Class that trasmits data from the sensors to the server at a predetermined time
 */
class Scheduler
{
private:
  Server m_server; // Main server
  Temperature m_temperatureSensor; // Temperature sensor
  Humidity m_humiditySensor; // Humidity sensor
  Pressure m_pressureSensor; // Pressure sensor
  Light m_lightSensor; // Light sensor

public:
  Scheduler();
  Scheduler(const Scheduler& sch_p);
  ~Scheduler();
  Scheduler& operator=(const Scheduler& sch_p);

  /**
   * @brief Do the transmition with a clock
   * 
   * @param simulSec_p Total time of the simulation
   * @param waitingTime_p Time between each data measurement
   */
  void StartSimul(int simulSec_p, unsigned int waitingTime_p);
};

#endif