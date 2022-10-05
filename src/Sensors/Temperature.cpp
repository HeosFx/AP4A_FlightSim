/**
 * @file Temperature.cpp
 * @author Flavian THEUREL
 * @brief Temperature sensor
 * @version 0.1
 * @date 2022-10-02
 */

#include "Temperature.hpp"
#include <random>

int Temperature::aleaGenVal()
{
  std::random_device rand_dev; // Initialize the random device
  std::mt19937 rng(rand_dev()); // A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits
  std::normal_distribution<std::mt19937::result_type> normal_dist(23, 3); // Normal distribution - Mean=23, dispertion=3
  return normal_dist(rng);
}

int Temperature::getData()
{
  int value = aleaGenVal();
  return value;
}