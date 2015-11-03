#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <future>
#include <iostream>

typedef std::vector<double> ArrayType;

int partition(ArrayType& theArray, int first, int mid, int last)
{

    double first_val = theArray[first];
    double first1 = first;

    for(int i = first + 1; i < last; i++)
    {
        if (theArray[i] <= first_val)
        {
            first1 = first1 + 1;
            std::swap(theArray[first1],theArray[i]);
        }

    }

    std::swap(theArray[first1],theArray[first]);
    return first1;
}

void qsort(ArrayType& theArray, int last, int first, bool con)
{
    int first1;
    if(first < last)
    {
        first1 = pivot(theArray, first, last);
        
        if(con)
        {
        	auto fut0 = std::async(&qsort, std::ref(theArray), first, first1, con);
      		auto fut1 = std::async(&qsort, std::ref(theArray), first1 + 1, last, con);
        }
        else
        {
        	qsort(theArray, first, first1, con);
        	qsort(theArray, first1 + 1, last, con);	
        }
        
    }
}