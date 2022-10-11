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

void Server::fileWrite(std::string type_p, std::string unit_p, int value_p)
{
  std::ofstream m_outfile;

  std::string path = "logs/"+type_p+"_log.txt";
  // Open the corresponding log file
  m_outfile.open(path, std::ios::out | std::ios::app);
  // Print the data from the corresponding sensor
  m_outfile << type_p << "\t" << value_p << unit_p << std::endl;

  m_outfile.close();
}

void Server::consolWrite(std::string type_p, std::string unit_p, int value_p)
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
    consolWrite(pType, pUnit, pValue);
  }
  if (m_settingLog == true)
  {
    fileWrite(pType, pUnit, pValue);
  }
}

void Server::receiveData(const Package& package_p)
{
  treatment2Package(package_p);
}

void Server::askParameters()
{
  
  std::string input;
  // Ask the user if he want to log the datas
  std::cout << "Do you want to log the datas? (Y/N)" << std::endl;
  std::cin >> input;
  while (input != "Y" && input != "N")
  {
    std::cout << "You entered a wrong answer. Do you want to log the datas? (Y/N)" << std::endl;
    std::cin >> input;
  }
  m_settingLog=(input=="Y");
  
  // Ask the user if he want to print the datas in the console
  std::cout << "Do you want to print the datas? (Y/N)" << std::endl;
  std::cin >> input;
  while (input != "Y" && input != "N")
  {
    std::cout << "You entered a wrong answer. Do you want to print the datas? (Y/N)" << std::endl;
    std::cin >> input;
  }
  m_settingDisplay=(input=="Y");
}