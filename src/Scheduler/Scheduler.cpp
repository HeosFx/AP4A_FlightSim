/**
 * @file Scheduler.cpp
 * @author Flavian THEUREL
 * @brief Class that transmits data from the sensors to the server at a predetermined time
 * @version 0.2
 * @date 2022-10-26
 */

// Define periods between each measure
#define PERIOD_TEMP 2
#define PERIOD_HUMI 4
#define PERIOD_LIGHT 5
#define PERIOD_PRES 1

#include "Scheduler.hpp"
#include <iostream>
#include <thread>
#include <chrono>


Scheduler::Scheduler(): m_server(), m_humiditySensor(), m_lightSensor(), m_pressureSensor(), m_temperatureSensor(){}

Scheduler::Scheduler(const Scheduler& sch_p): m_server(sch_p.m_server), m_humiditySensor(sch_p.m_humiditySensor), m_lightSensor(sch_p.m_lightSensor), m_pressureSensor(sch_p.m_pressureSensor), m_temperatureSensor(sch_p.m_temperatureSensor){}

Scheduler::~Scheduler(){}

Scheduler& Scheduler::operator=(const Scheduler &sch_p)
{
  return *this;
}

void Scheduler::temperatureTask(Package<float>& pkg_p)
{
  // Run the task until stop is required by the user
  while (!m_stopRequired)
  {
    // Initialize the package
    pkg_p.initializeValue(m_temperatureSensor.m_type, m_temperatureSensor.m_unit, m_temperatureSensor.getData());
    // Transmission
    m_server.receiveData<float>(pkg_p);

    // Wait
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD_TEMP));
  }
}

void Scheduler::pressureTask(Package<int>& pkg_p)
{
  // Run the task until stop is required by the user
  while (!m_stopRequired)
  {
    // Initialize the package
    pkg_p.initializeValue(m_pressureSensor.m_type, m_pressureSensor.m_unit, m_pressureSensor.getData());
    // Transmission
    m_server.receiveData<int>(pkg_p);

    // Wait
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD_PRES));
  }
}

void Scheduler::humidityTask(Package<float>& pkg_p)
{
  // Run the task until stop is required by the user
  while (!m_stopRequired)
  {
    // Initialize the package
    pkg_p.initializeValue(m_humiditySensor.m_type, m_humiditySensor.m_unit, m_humiditySensor.getData());
    // Transmission
    m_server.receiveData<float>(pkg_p);

    // Wait
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD_HUMI));
  }
}

void Scheduler::lightTask(Package<bool>& pkg_p)
{
  // Run the task until stop is required by the user
  while (!m_stopRequired)
  {
    // Initialize the package
    pkg_p.initializeValue(m_lightSensor.m_type, m_lightSensor.m_unit, m_lightSensor.getData());
    // Transmission
    m_server.receiveData<bool>(pkg_p);

    // Wait
    std::this_thread::sleep_for(std::chrono::seconds(PERIOD_LIGHT));
  }
}

void Scheduler::getKBInput()
{
  // Stand still until the user input "q"
  std::string input;
  std::cin >> input;
  if (input == "q")
  {
    m_stopRequired = true;
  }
}

void Scheduler::StartSimul()
{
  // Parameters the server
  m_server.askParameters();

  // Initialize packages for data transfer
  Package<float> temperaturePkg(m_temperatureSensor.m_type, m_temperatureSensor.m_unit, m_temperatureSensor.getData());
  Package<float> humidityPkg(m_temperatureSensor.m_type, m_temperatureSensor.m_unit, m_temperatureSensor.getData());
  Package<int> pressurePkg(m_temperatureSensor.m_type, m_temperatureSensor.m_unit, m_temperatureSensor.getData());
  Package<bool> lightPkg(m_temperatureSensor.m_type, m_temperatureSensor.m_unit, m_temperatureSensor.getData());

  // Initialize a list of threads
  std::thread sensorThreads[4];

  sensorThreads[0] = std::thread(&Scheduler::temperatureTask, this, std::ref(temperaturePkg)); // Thread for temperature
  sensorThreads[1] = std::thread(&Scheduler::pressureTask, this, std::ref(pressurePkg)); // Thread for pressure
  sensorThreads[2] = std::thread(&Scheduler::humidityTask, this, std::ref(humidityPkg)); // Thread for humidity
  sensorThreads[3] = std::thread(&Scheduler::lightTask, this, std::ref(lightPkg)); // Thread for temperature

  // Initialize the input thread
  std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait to delay the input thread
  std::thread tInput(&Scheduler::getKBInput, this);

  // Wait for all thread to synchronize
  for (auto & sensorThread : sensorThreads)
  {
    sensorThread.join();
  }
  tInput.join();

}