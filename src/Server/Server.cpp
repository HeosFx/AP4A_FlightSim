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

Server::Server(): m_settingDisplay(true), m_settingLog(true)
{
}

Server::Server(const Server& serv_p): m_settingDisplay(serv_p.m_settingDisplay), m_settingLog(serv_p.m_settingLog)
{
}

Server::~Server(){}

Server& Server::operator=(const Server& serv_p)
{
  m_settingDisplay = serv_p.m_settingDisplay;
  m_settingLog = serv_p.m_settingLog;
  return *this;
}

void Server::fileWriter(std::string type_p, std::string unit_p, int value_p)
{
  std::ofstream m_outfile;

  // Open the corresponding log file
  m_outfile.open("../logs/"+type_p+"_log.txt", std::ios_base::app);
  // Print the data from the corresponding sensor
  m_outfile << type_p << "\t" << value_p << unit_p << std::endl;

  m_outfile.close();
}

void Server::consolWriter(std::string type_p, std::string unit_p, int value_p)
{
  // Print the datas in the console
  std::cout << type_p << "\t" << value_p << "\t" << unit_p << std::endl;

}


void Server::treatment2Package(const Package& package_p)
{
  int pValue = package_p.m_value;
  std::string pType = package_p.m_type;
  std::string pUnit = package_p.m_unit;

  if (m_settingDisplay == true)
  {
    consolWriter(pType, pUnit, pValue);
  }
  if (m_settingLog == true)
  {
    fileWriter(pType, pUnit, pValue);
  }
}

void Server::receiveData(const Package& package_p)
{
  treatment2Package(package_p);
}