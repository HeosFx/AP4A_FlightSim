/**
 * @file Server.hpp
 * @author Flavian THEUREL
 * @brief The server receives datas from captors and displays/saves them
 * @version 0.2
 * @date 2022-10-02
 */


#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <map>
#include "../DataClass/DataClass.hpp"


/**
 * @brief Enumeration that's used to switch data types in fileWriter and consolWriter
 * 
 */
enum EType
{
  e_temperature,
  e_humidity,
  e_pressure,
  e_light
};


/**
 * @class Server
 * @brief Server receives datas from captors and displays/saves them
 */
class Server
{
private:
  std::vector<DataClass> m_dataList;  // List of the sensors last data sent
                                      // 0 - Temperature data
                                      // 1 - Humidity data
                                      // 2 - Pressure data
                                      // 3 - Light data
  bool m_settingLog, m_settingDisplay; // Status of the diplaying / logging methods


   /**
   * @brief Write in a file the data provided by the sensor
   * 
   * @param type Data type
   * @param data_p Data from the sensor
   */
  void fileWriter(std::string type_p);

  /**
   * @brief Write in the console the data provided by a sensor
   * 
   * @param type Data type
   * @param data_p Data from the sensor
   */
  void consolWriter(std::string type_p);

public:
  Server();
  Server(const Server& serv_p);
  ~Server();
  Server& operator=(const Server& serv_p);

  /**
   * @brief Do the display / log of the data corresponding to its type (take in account the settings)
   * 
   * @param type Data type
   */
  void operator>>(std::string type_p);

  /**
   * @brief Get the data from a sensor
   * 
   * @param type_p Data type
   * @param data_p Data from the sensor
   * @return true if the data has been correctly sent
   */
  void receiveData(std::string type_p, int data_p);
};

#endif