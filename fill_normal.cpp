#include "fill_normal.h"

	// Create random device and seed
fill_normal()
{
	std::random_device rd;
	gen.seed(rd());
}
  
// Override operator to put random value in x
void operator()(double & x)
{
	x = p(gen);
}