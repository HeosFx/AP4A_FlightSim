/**
 * @file Package.hpp
 * @author Flavian THEUREL
 * @brief Class that regroup a value, data type and unit from a data
 * @version 0.1
 * @date 2022-10-02
 */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <ostream>

/**
 * @class Package
 * @brief Class that regroup a value, data type and unit from a data
 */
class Package
{
public:
  int m_value; // Value from the sensor
  std::string m_type; // Data type
  std::string m_unit; // Data unit


  Package();
  Package(const Package& dc_p);
  ~Package();
  Package& operator=(const Package& dc_p);
  

  /**
   * @brief Construct a new Package object that will be use while initializing it for the first time
   * 
   * @param type_p 
   * @param unit_p 
   */
  Package(std::string type_p, std::string unit_p);
  

  // Friend declaration


  // A bouger dans le serveur
  /**
   * @brief Organize the datas and informations to print them properly
   * 
   * @param os_p Output stream
   * @param dc_p Data class
   * @return std::ostream& Output that will be printed
   */
  friend std::ostream& operator<<(std::ostream& os_p, const Package& dc_p);
};

#endif