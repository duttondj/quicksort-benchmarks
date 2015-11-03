#include "fill_normal.h"

	// Create random device and seed
fill_normal::fill_normal()
{
	std::random_device rd;
	gen.seed(rd());
}
  
// Override operator to put random value in x
void fill_normal::operator()(double & x)
{
	x = p(gen);
}