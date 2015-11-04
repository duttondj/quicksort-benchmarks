////////////////////////////////////////////////////////////////////////////////
//
//  Title:  fill_normal.cpp
//  Author: Danny Dutton
//  Date:   11/03/15
//  Desc:   Functions for normal distribution filling of an array/vector
//
////////////////////////////////////////////////////////////////////////////////

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