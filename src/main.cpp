/**
 * @file main.cpp
 * @author Flavian THEUREL
 * @brief Class that launch the program
 * @version 0.1
 * @date 2022-10-09
 */

#include "Scheduler/Scheduler.hpp"

int main()
{
  Scheduler scheduler;
  scheduler.StartSimul(15, 3);
}