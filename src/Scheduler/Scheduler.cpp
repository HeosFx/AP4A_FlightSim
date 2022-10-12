/**
 * @file Scheduler.cpp
 * @author Flavian THEUREL
 * @brief Class that trasmits data from the sensors to the server at a predetermined time
 * @version 0.1
 * @date 2022-10-05
 */

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "Scheduler.hpp"
#include <queue>
#include <iostream>


Scheduler::Scheduler(): m_server(), m_humiditySensor(), m_lightSensor(), m_pressureSensor(), m_temperatureSensor()
{
}

Scheduler::Scheduler(const Scheduler& sch_p): m_server(sch_p.m_server), m_humiditySensor(sch_p.m_humiditySensor), m_lightSensor(sch_p.m_lightSensor), m_pressureSensor(sch_p.m_pressureSensor), m_temperatureSensor(sch_p.m_temperatureSensor)
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::StartSimul(int simulSec_p, unsigned int waitingTime_p)
{
  std::queue<Package> pkgBuffer;

  m_server.askParameters();

  // Loop until the simulation end
  while (simulSec_p > 0)
  {
    // Get all the datas
    Package temperaturePkg(m_temperatureSensor.m_type, m_temperatureSensor.m_unit, m_temperatureSensor.getData());
    pkgBuffer.push(temperaturePkg);
    Package humidityPkg(m_humiditySensor.m_type, m_humiditySensor.m_unit, m_humiditySensor.getData());
    pkgBuffer.push(humidityPkg);
    Package pressurePkg(m_pressureSensor.m_type, m_pressureSensor.m_unit, m_pressureSensor.getData());
    pkgBuffer.push(pressurePkg);
    Package lightPkg(m_lightSensor.m_type, m_lightSensor.m_unit, m_lightSensor.getData());
    pkgBuffer.push(lightPkg);

    // Transmit the packages
    while (!pkgBuffer.empty())
    {
      m_server.receiveData(pkgBuffer.front());
      pkgBuffer.pop();
    }

    // Reduce the simulation time remaining
    simulSec_p-=waitingTime_p;
    
    // Wait WAIT_TIMER
    // Select the OS on which you are and call the correct method
    #ifdef WIN32
      // Convertion milliseconds to seconds
      Sleep(waitingTime_p*1000);
    #else
      // Convertion microseconds to seconds
      usleep(waitingTime_p*1000000);
    #endif
  }
  
}