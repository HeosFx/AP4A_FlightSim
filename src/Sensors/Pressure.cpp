/**
 * @file Pressure.cpp
 * @author Flavian THEUREL
 * @brief Pressure sensor
 * @version 0.1
 * @date 2022-10-05
 */

#include "Pressure.hpp"
#include <random>
#include <chrono>

// Parameters of the normal distribution
#define C_MEAN 79289 // Real value in Pa : 79289.71
#define C_DISP 3447 // Real value in Pa : 3447.3785

Pressure::~Pressure()
{
}

int Pressure::aleaGenVal()
{
  // Initialize the random device
  std::random_device rd;

  // seed value is designed specifically to make initialization
  // parameters of std::mt19937 (instance of std::mersenne_twister_engine<>)
  // different across executions of application
  std::mt19937::result_type seed = rd() ^ (
    (std::mt19937::result_type)
    std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::system_clock::now().time_since_epoch()
        ).count() +
    (std::mt19937::result_type)
    std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::high_resolution_clock::now().time_since_epoch()
        ).count() );
  
  // Instantiate a Mersenne Twister pseudo-random generator of 32-bit numbers with a state size of 19937 bits
  std::mt19937 gen(seed);

  // Setup the normal distribution
  std::normal_distribution<float> normal_dist(C_MEAN, C_DISP); // Normal distribution
  return (int)normal_dist(gen);
}