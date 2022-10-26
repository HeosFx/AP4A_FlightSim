/**
 * @file Server.cpp
 * @author Flavian THEUREL
 * @brief The server receives data from captors and displays/saves them
 * @version 0.2
 * @date 2022-10-22
 */

#include "Server.hpp"

Server::Server(): m_settingDisplay(true), m_settingLog(true){}

Server::Server(const Server& serv_p): m_settingDisplay(serv_p.m_settingDisplay), m_settingLog(serv_p.m_settingLog){}

Server::~Server(){}

Server& Server::operator=(const Server& serv_p)
{
  m_settingDisplay = serv_p.m_settingDisplay;
  m_settingLog = serv_p.m_settingLog;
  return *this;
}

void Server::askParameters()
{
  std::string input;
  // Ask the user if he wants to log the data
  std::cout << "Do you want to log the data? (y/n)" << std::endl;
  std::cin >> input;
  // Loop until the user enters a correct answer
  while (input != "y" && input != "n")
  {
    std::cout << "You entered a wrong answer. Do you want to log the data? (y/n)" << std::endl;
    std::cin >> input;
  }
  m_settingLog=(input=="y");
  
  // Ask the user if he wants to print the data in the console
  std::cout << "Do you want to print the data? (y/n)" << std::endl;
  std::cin >> input;
  // Loop until the user enters a correct answer
  while (input != "y" && input != "n")
  {
    std::cout << "You entered a wrong answer. Do you want to print the data? (y/n)" << std::endl;
    std::cin >> input;
  }
  m_settingDisplay=(input=="y");

  if (m_settingDisplay)
  {
    // Print the header of the console print
    std::cout << "Time \t\t\t\t Temperature \t\t Humidity \t\t Pressure \t\t Light\n"
              << std::left << std::setw(117) << std::setfill('_') << "_" << std::endl;
  }
}