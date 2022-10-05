/**
 * @file Light.cpp
 * @author Flavian THEUREL
 * @brief Light sensor
 * @version 0.1
 * @date 2022-10-05
 */

#include "Light.hpp"
#include <random>

// Parameters of the normal distribution
// Classic day : Full daylight : 10000 Lux -> We suppose that the flight takes place during a classic day
#define C_MEAN 10000
#define C_DISP 1000

int Light::aleaGenVal()
{
  std::random_device rand_dev; // Initialize the random device
  std::mt19937 rng(rand_dev()); // A Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits
  std::normal_distribution<std::mt19937::result_type> normal_dist(C_MEAN, C_DISP);  // Normal distribution
  return normal_dist(rng);
}