/**
 * @file Server.hpp
 * @author Flavian THEUREL
 * @brief The server receives data from captors and displays/saves them
 * @version 0.2
 * @date 2022-10-22
 */


#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <map>
#include <mutex>
#include "../Package/Package.hpp"

/**
 * @class Server
 * @brief Server receives data from captors and displays/saves them
 */
class Server
{
private:
  std::map<std::string, int> m_typeMap{{"temperature", 0}, {"humidity", 1}, {"pressure", 2}, {"light",3}}; // Map a data type to an integer
  bool m_settingLog, m_settingDisplay; // Status of the displaying / logging methods
  std::mutex m_coutMutex; // Mutex used to synchronize the cout

  /**
   * @brief Write in a file the data provided by the sensor
   * 
   * @param type_p Data type
   * @param unit_p Unit of the measure
   * @param value_p Value measured from the sensor
   * @tparam T Type of the variable value
   */
  template <typename T> void fileWrite(const std::string& type_p, const std::string& unit_p, const T& value_p)
  {
    std::ofstream m_outfile;

    // Generate the file path
    std::string path = "logs/"+type_p+"_log.txt";
    // Open the corresponding log file
    m_outfile.open(path, std::ios::app | std::ios::out);
    if (m_outfile.is_open())
    {
      // Get the current time
      time_t time = std::time(0);
      std::string currTime = std::asctime(std::gmtime(&time));
      currTime.pop_back(); // Delete \n from the string

      // Print the data from the corresponding sensor
      m_outfile << currTime << "\t" << type_p << "\t" << value_p << "\t" << unit_p << std::endl;
      m_outfile.close();
    }
  };

  /**
   * @brief Write in the console the data provided by a sensor
   * 
   * @param type_p Data type
   * @param unit_p Unit of the measure
   * @param value_p Value measured from the sensor
   * @tparam T Type of the variable value
   */
  template <typename T> void consoleWrite(const std::string& type_p, const std::string& unit_p, const T& value_p)
  {
    // Get the current time
    time_t time = std::time(0);
    std::string currTime = std::asctime(std::gmtime(&time));
    currTime.pop_back(); // Delete \n from the string

    // Permit the access to the cout to only 1 thread at a time
    m_coutMutex.lock();

    // Print the data in the console
    // Indent the printing depending on the data type
    switch (m_typeMap[type_p])
    {
      case 0: // Temperature case
      {
        std::cout << std::left << std::setw(33) << std::setfill(' ') << currTime << std::left << std::setw(7) << std::setfill(' ') << value_p
                  << " " << unit_p << std::endl;
      }
      break;

      case 1: // Humidity case
      {
        std::cout << std::left << std::setw(33) << std::setfill(' ') << currTime << std::right << std::setw(24)
                  << std::setfill(' ') << " " <<  value_p << " " << unit_p << std::endl;
      }
      break;

      case 2: // Pressure case
      {
        std::cout << std::left << std::setw(33) << std::setfill(' ') << currTime << std::right << std::setw(48)
                  << std::setfill(' ') << " " << value_p << " " << unit_p << std::endl;
      }
      break;

      case 3: // Light case
      {
        if (value_p) // Replace 1 by true in the printing
        {
          std::cout << std::left << std::setw(33) << std::setfill(' ') << currTime << std::right << std::setw(72)
                    << std::setfill(' ') << " " << "True" << std::endl;
        }
        else // Replace 0 by false in the printing
        {
          std::cout << std::left << std::setw(33) << std::setfill(' ') << currTime << std::right << std::setw(72)
                    << std::setfill(' ') << " " << "False" << std::endl;
        }

      }
      break;

      default: // Err case
        std::cout << std::left << std::setw(33) << std::setfill(' ') << currTime << "No value transferred.";
    }
    m_coutMutex.unlock();
  };

  /**
   * @brief Take the data from the package
   * 
   * @param package_p Package sent by the scheduler
   * @tparam T Type of the value extracted
   */
  template <typename T> void treatment2Package(const Package<T>& package_p)
  {
    T pValue = package_p.m_value;
    std::string pType = package_p.m_type;
    std::string pUnit = package_p.m_unit;

    if (m_settingDisplay)
    {
      consoleWrite<T>(pType, pUnit, pValue);
    }
    if (m_settingLog)
    {
      fileWrite<T>(pType, pUnit, pValue);
    }
  };

public:
  Server();
  Server(const Server& serv_p);
  ~Server();
  Server& operator=(const Server& serv_p);

  /**
   * @brief Retrieve the data and log them
   * 
   * @param package_p Package containing the data from the sensor
   * @tparam T Data value type (float, int, ...)
   */
  template <typename T> void receiveData(const Package<T>& package_p)
  {
    treatment2Package<T>(package_p);
  };

  /**
   * @brief Ask the user to enter the parameter of the logging and printing
   * 
   */
  void askParameters();
};

#endif