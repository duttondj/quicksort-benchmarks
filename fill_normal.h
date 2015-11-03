#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <future>
#include <iostream>

#ifndef _FILL_NORMAL
#define _FILL_NORMAL


// Functor number generator using normal distribution
class fill_normal
{
public:

  // Create random device and seed
  fill_normal();
  
  // Override operator to put random value in x
  void operator()(double & x);

private:
  // Mersenne Twister engine
  std::mt19937 gen;
  // Use normal distribution
  std::normal_distribution<double> p; 
};

#endif