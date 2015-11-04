////////////////////////////////////////////////////////////////////////////////
//
//  Title:  myqsort.cpp
//  Author: Danny Dutton
//  Date:   11/03/15
//  Desc:   Header to manage a sequential and concurrent quick sort
//
////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <future>
#include <iostream>

#ifndef _MYQSORT
#define _MYSORT

#ifndef _ARRAYTYPE
#define _ARRAYTYPE
typedef std::vector<double> ArrayType;
#endif

long partition(ArrayType& theArray, long first, long last);

void myqsort(ArrayType& theArray, long first, long last, bool con);

#endif