#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <future>
#include <iostream>

typedef std::vector<double> ArrayType;

int pivot(ArrayType& theArray, int first, int mid, int last)
{

    double first_val = theArray[first];
    double pivotIndex = first;

    for(int i = first + 1; i < last; i++)
    {
        if (theArray[i] <= first_val)
        {
            pivotIndex = first1 + 1;
            std::swap(theArray[pivotIndex],theArray[i]);
        }

    }

    std::swap(theArray[pivotIndex],theArray[first]);
    return pivotIndex;
}

void qsort(ArrayType& theArray, int first, int mid, int last, bool con)
{
    if(first < last)
    {
        pivotIndex = pivot(theArray, first, mid last);
        
        if(con)
        {
        	auto fut0 = std::async(std::launch::async, &qsort, std::ref(theArray), first, pivotIndex, con);
      		auto fut1 = std::async(std::launch::async, &qsort, std::ref(theArray), pivotIndex + 1, last, con);

            fut0.get();
            fut1.get();
        }
        else
        {
        	qsort(theArray, first, pivotIndex, con);
        	qsort(theArray, pivotIndex + 1, last, con);	
        }
        
    }
}