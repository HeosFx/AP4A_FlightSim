/**
 * @file Package.cpp
 * @author Flavian THEUREL
 * @brief Class that regroup a value, data type and unit from a data
 * @version 0.1
 * @date 2022-10-02
 */

#include "Package.hpp"
#include <iomanip>

Package::Package(): m_value(), m_unit()
{
  m_type = "No Type";
}

Package::Package(const Package& dc_p): m_value(dc_p.m_value), m_unit(dc_p.m_unit)
{
  m_type = dc_p.m_type;
}

Package::Package(std::string type_p, std::string unit_p, int value_p): m_value(value_p), m_unit(unit_p)
{
  m_type = type_p;
}

Package::~Package()
{
}

Package& Package::operator=(const Package& dc_p)
{
  m_type = dc_p.m_type;
  m_unit = dc_p.m_unit;
  m_value = dc_p.m_value;
  return *this;
}

void Package::initializeValue(std::string type_p, std::string unit_p, int value_p)
{
  m_type = type_p;
  m_unit = unit_p;
  m_value = value_p;
}