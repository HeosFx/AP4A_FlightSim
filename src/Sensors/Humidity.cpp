/**
 * @file Humidity.cpp
 * @author Flavian THEUREL
 * @brief Temperature sensor
 * @version 0.1
 * @date 2022-10-05
 */

#include "Humidity.hpp"
#include <random>

int Humidity::aleaGenVal()
{
  std::random_device rand_dev; // Initialize the random device
  std::mt19937 rng(rand_dev()); // A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits
  std::normal_distribution<std::mt19937::result_type> normal_dist(20, 8); // Normal distribution - Mean=20, dispertion=8
  return normal_dist(rng);
}