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

int pivot(ArrayType& theArray, int first, int mid, int last);

void myqsort(ArrayType& theArray, int first, int mid, int last, bool con);

#endif