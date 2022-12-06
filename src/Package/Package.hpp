/**
 * @file Package.hpp
 * @author Flavian THEUREL
 * @brief Class that regroup a value, data type and unit from a data
 * @version 0.2
 * @date 2022-10-19
 */

#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <iomanip>

/**
 * @class Package
 * @brief Class that regroup a value, data type and unit from a data
 *
 * @tparam T Data type of the value
 */
template <typename T> class Package
{
public:
  T m_value; // Value from the sensor
  std::string m_type; // Data type
  std::string m_unit; // Data unit


  Package<T>(): m_value(), m_unit(), m_type("No Type"){};
  Package<T>(const Package<T>& dc_p): m_value(dc_p.m_value), m_unit(dc_p.m_unit), m_type(dc_p.m_type){};
  virtual ~Package<T>(){};
  Package<T>& operator=(const Package<T>& dc_p)
  {
    m_type = dc_p.m_type;
    m_unit = dc_p.m_unit;
    m_value = dc_p.m_value;
    return *this;
  };
  
  /**
   * @brief Construct a new Package object
   * 
   * @param type_p Data type
   * @param unit_p Unit of the value
   * @param value_p Value from the sensor
   */
  Package<T>(std::string type_p, std::string unit_p, T value_p): m_value(value_p), m_unit(unit_p), m_type(type_p){};

  /**
   * @brief Initialize the package with given values
   * 
   * @param type_p Data type
   * @param unit_p Unit of the value
   * @param value_p Value from the sensor
   */
  void initializeValue(std::string type_p, std::string unit_p, T value_p)
  {
    m_type = type_p;
    m_unit = unit_p;
    m_value = value_p;
  };
};

#endif