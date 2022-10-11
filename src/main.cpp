/**
 * @file main.cpp
 * @author Flavian THEUREL
 * @brief Class that launch the program
 * @version 0.1
 * @date 2022-10-09
 */

#include "Scheduler/Scheduler.hpp"
#include <iostream>

int main()
{
  int time_sim;
  std::cout << "Enter the duration of the simulation in seconds:" << std::endl;
  std::cin >> time_sim;

  int measurement_period;
  std::cout << "Enter the measurement period in seconds:" << std::endl;
  std::cin >> measurement_period;

  Scheduler scheduler;
  scheduler.StartSimul(time_sim, measurement_period);
}