/**
 * @file Server.cpp
 * @author Flavian THEUREL
 * @brief The server receives datas from captors and displays/saves them
 * @version 0.2
 * @date 2022-10-02
 */

#include "Server.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

Server::Server(): m_dataList(), m_settingDisplay(true), m_settingLog(true)
{
}

Server::Server(const Server& serv_p): m_dataList(serv_p.m_dataList), m_settingDisplay(serv_p.m_settingDisplay), m_settingLog(serv_p.m_settingLog)
{
}

Server::~Server(){}

Server& Server::operator=(const Server& serv_p)
{
  m_dataList = serv_p.m_dataList;
  m_settingDisplay = serv_p.m_settingDisplay;
  m_settingLog = serv_p.m_settingLog;
  return *this;
}

void Server::fileWriter(std::string type_p)
{
  std::ofstream m_outfile;

  // Select the correct data type to print in the corresponding log file
  // switch (type_p)
  // {
  //   case e_temperature:
  //   {
  //     m_outfile.open("logs/temperature_log.txt", std::ios_base::app); // Append the new data to the Save file
  //     m_outfile << m_temperatureBuffer << "\t";
  //   }
  //   break;

  //   case e_humidity:
  //   {
  //     m_outfile.open("logs/humidity_log.txt", std::ios_base::app); // Append the new data to the Save file
  //     m_outfile << m_humidityBuffer << "\t";
  //   }
  //   break;

  //   case e_pressure:
  //   {
  //     m_outfile.open("logs/presure_log.txt", std::ios_base::app); // Append the new data to the Save file
  //     m_outfile << m_pressureBuffer << "\t";
  //   }
  //   break;

  //   case e_light:
  //   {
  //     m_outfile.open("logs/light_log.txt", std::ios_base::app); // Append the new data to the Save file
  //     m_outfile << m_lightBuffer << "\t";
  //   }
  //   break;
  
  //   default:
  //   break;
  // }

  // Open the corresponding log file
  m_outfile.open("../logs/"+type_p+"_log.txt", std::ios_base::app);
  // Print the data from the corresponding sensor
  if (type_p=="temperature")
  {
    m_outfile << m_dataList[0];
  } else if (type_p=="humidity")
  {
    m_outfile << m_dataList[1];
  } else if (type_p=="pressure")
  {
    m_outfile << m_dataList[2];
  } else if (type_p=="light")
  {
    m_outfile << m_dataList[3];
  }

  m_outfile.close();
}

void Server::consolWriter(std::string type_p)
{
  // Select the according data type
  // switch (type_p)
  // {
  //   case e_temperature:
  //   {
  //     std::cout << "\r" << "Temperature : " << std::setw(3) << std::setfill('0') << m_temperatureBuffer << "°C" << std::flush;
  //   }
  //   break;

  //   case e_humidity:
  //   {
  //     std::cout << "\r" << "Humidity : " << std::setw(3) << std::setfill('0') << m_humidityBuffer << "%" << std::flush;
  //   }
  //   break;

  //   case e_pressure:
  //   {
  //     std::cout << "\r" << "Pressure : " << std::setw(3) << std::setfill('0') << m_pressureBuffer << "bar" << std::flush;
  //   }
  //   break;

  //   case e_light:
  //   {
  //     std::cout << "\r" << "Light : " << std::setw(3) << std::setfill('0') << m_lightBuffer << "L" << std::flush;
  //   }
  //   break;
  
  //   default:
  //   break;
  // }

  // Print the datas in the console
  std::cout << m_dataList[0] << "| " << m_dataList[1] << "| " << m_dataList[2] << "| " << m_dataList[3] << std::flush;

}

void Server::receiveData(std::string type_p, int data_p)
{
  // Select the according data type
  // switch (type_p)
  // {
  //   case e_temperature:
  //   {
  //     m_temperatureBuffer = data_p;
  //   }
  //   break;

  //   case e_humidity:
  //   {
  //     m_humidityBuffer = data_p;
  //   }
  //   break;

  //   case e_pressure:
  //   {
  //     m_pressureBuffer = data_p;
  //   }
  //   break;

  //   case e_light:
  //   {
  //     m_lightBuffer = data_p;
  //   }
  //   break;
  
  //   default:
  //   break;
  // }

  // Assign the incomming data to the correct data object
  if (type_p=="temperature")
  {
    (m_dataList[0]).m_value=data_p;
  } else if (type_p=="humidity")
  {
    (m_dataList[1]).m_value=data_p;
  } else if (type_p=="pressure")
  {
    (m_dataList[2]).m_value=data_p;
  } else if (type_p=="light")
  {
    (m_dataList[3]).m_value=data_p;
  }
}

void Server::operator>>(std::string type_p)
{
  if (m_settingLog)
  {
    fileWriter(type_p);
  }
  if (m_settingDisplay)
  {
    consolWriter(type_p);
  }  
}