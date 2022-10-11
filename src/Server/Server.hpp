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
#include "../Package/Package.hpp"

// Faire une FIFO avec la liste


/**
 * @class Server
 * @brief Server receives datas from captors and displays/saves them
 */
class Server
{
private:
  bool m_settingLog, m_settingDisplay; // Status of the diplaying / logging methods

  /**
   * @brief Write in a file the data provided by the sensor
   * 
   * @param type Data type
   * @param data_p Data from the sensor
   */
  void fileWrite(std::string type_p, std::string unit_p, int value_p);

  /**
   * @brief Write in the console the data provided by a sensor
   * 
   * @param type Data type
   * @param data_p Data from the sensor
   */
  void consolWrite(std::string type_p, std::string unit_p, int value_p);

  /**
   * @brief Take the datas from the package
   * 
   * @param package_p Package sent by the scheduler
   */
  void treatment2Package(const Package& package_p);

public:
  Server();
  Server(const Server& serv_p);
  ~Server();
  Server& operator=(const Server& serv_p);

  // /**
  //  * @brief Do the display / log of the data corresponding to its type (take in account the settings)
  //  * 
  //  * @param type Data type
  //  */
  // void operator>>(std::string type_p);

  /**
   * @brief Retrieve the data and log them
   * 
   * @param package_p Package containing the datas from the sensor
   */
  void receiveData(const Package& package_p);

  /**
   * @brief Ask the user to enter the parameter of the logging and printing
   * 
   */
  void askParameters();
};

#endif