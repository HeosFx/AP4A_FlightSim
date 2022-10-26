/**
 * @file Scheduler.hpp
 * @author Flavian THEUREL
 * @brief Class that transmits data from the sensors to the server
 * @version 0.2
 * @date 2022-10-26
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
 * @brief Class that transmits data from the sensors to the server at a predetermined time
 */
class Scheduler
{
private:
  bool m_stopRequired = false; // Want to stop the simulation ?
  Server m_server; // Main server
  Temperature m_temperatureSensor; // Temperature sensor
  Humidity m_humiditySensor; // Humidity sensor
  Pressure m_pressureSensor; // Pressure sensor
  Light m_lightSensor; // Light sensor

public:
  Scheduler();
  Scheduler(const Scheduler& sch_p);
  virtual ~Scheduler();
  Scheduler& operator=(const Scheduler& sch_p);

  /**
   * @brief Run the temperature measurement on a thread
   *
   * @param pkg_p A float package
   */
  void temperatureTask(Package<float>& pkg_p);

  /**
   * @brief Run the humidity measurement on a thread
   *
   * @param pkg_p A float package
   */
  void humidityTask(Package<float>& pkg_p);

  /**
   * @brief Run the light measurement on a thread
   *
   * @param pkg_p A boolean package
   */
  void lightTask(Package<bool>& pkg_p);

  /**
   * @brief Run the pressure measurement on a thread
   *
   * @param pkg_p A integer package
   */
  void pressureTask(Package<int>& pkg_p);

  /**
   * @brief Get the input from the console in a separate thread
   *
   */
  void getKBInput();

  /**
   * @brief Start the whole simulation
   *
   */
  void StartSimul();
};

#endif