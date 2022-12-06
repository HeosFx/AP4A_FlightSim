/**
 * @file Light.cpp
 * @author Flavian THEUREL
 * @brief Light sensor
 * @version 0.2
 * @date 2022-10-19
 */

#include "Light.hpp"
#include <random>
#include <chrono>

// Parameters of the normal distribution
// Classic day : Full daylight : 10000 Lux -> We suppose that the flight takes place during a classic day
#define C_MIN 0
#define C_MAX 1

Light::Light(){}

Light::Light(const Light& sensor_p){}

Light::~Light(){}

Light& Light::operator=(const Light& sensor_p)
{
  return *this;
}

bool Light::aleaGenVal()
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

  // Set up the normal distribution
  std::uniform_int_distribution<int> uni_dist(C_MIN, C_MAX); // Normal distribution
  return uni_dist(gen);
}