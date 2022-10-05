/**
 * @file DataClass.cpp
 * @author Flavian THEUREL
 * @brief Class that regroup a value, data type and unit from a data
 * @version 0.1
 * @date 2022-10-02
 */

#include "DataClass.hpp"
#include <iomanip>

DataClass::DataClass(): m_value(), m_unit()
{
  m_type = "No Type";
}

DataClass::DataClass(const DataClass& dc_p): m_value(dc_p.m_value), m_unit(dc_p.m_unit)
{
  m_type = dc_p.m_type;
}

DataClass::DataClass(std::string type_p, std::string unit_p): m_value(), m_unit(unit_p)
{
  m_type = type_p;
}

DataClass::~DataClass()
{
}

DataClass& DataClass::operator=(const DataClass& dc_p)
{
  m_type = dc_p.m_type;
  m_unit = dc_p.m_unit;
  m_value = dc_p.m_value;
  return *this;
}

std::ostream& operator<<(std::ostream& os_p, const DataClass& dc_p)
{
  return os_p << dc_p.m_type << ": " << dc_p.m_value << dc_p.m_unit << "\t";
}