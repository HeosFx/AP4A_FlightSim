/**
 * @file DataClass.hpp
 * @author Flavian THEUREL
 * @brief Class that regroup a value, data type and unit from a data
 * @version 0.1
 * @date 2022-10-02
 */

#ifndef DATACLASS_H
#define DATACLASS_H

#include "Server.hpp"
#include <string>
#include <ostream>

/**
 * @class DataClass
 * @brief Class that regroup a value, data type and unit from a data
 */
class DataClass
{
private:
  int m_value; // Value from the sensor
  std::string m_type; // Data type
  std::string m_unit; // Data unit

public:
  DataClass();
  DataClass(const DataClass& dc_p);
  ~DataClass();
  DataClass& operator=(const DataClass& dc_p);
  

  /**
   * @brief Construct a new DataClass object that will be use while initializing it for the first time
   * 
   * @param type_p 
   * @param unit_p 
   */
  DataClass(std::string type_p, std::string unit_p);
  

  // Friend declaration

  /**
   * @brief Organize the datas and informations to print them properly
   * 
   * @param os_p Output stream
   * @param dc_p Data class
   * @return std::ostream& Output that will be printed
   */
  friend std::ostream& operator<<(std::ostream& os_p, const DataClass& dc_p);

  friend void Server::receiveData(std::string type_p, int data_p);
};

#endif