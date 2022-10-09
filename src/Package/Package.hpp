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
   * @brief Construct a new Package object
   * 
   * @param type_p Data type
   * @param unit_p Unit of the value
   * @param value_p Value from the sensor
   */
  Package(std::string type_p, std::string unit_p, int value_p);

  /**
   * @brief Initialize the packagewith given values
   * 
   * @param type_p Data type
   * @param unit_p Unit of the value
   * @param value_p Value from the sensor
   */
  void initializeValue(std::string type_p, std::string unit_p, int value_p);
};

#endif