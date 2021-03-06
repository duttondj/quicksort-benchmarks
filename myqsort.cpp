////////////////////////////////////////////////////////////////////////////////
//
//  Title:  myqsort.cpp
//  Author: Danny Dutton
//  Date:   11/03/15
//  Desc:   Functions to manage a sequential and concurrent quick sort
//
////////////////////////////////////////////////////////////////////////////////

#include "myqsort.h"

const long SWITCH_SIZE = 10000; 

long partition(ArrayType& theArray, long first, long mid, long last)
{
    // Long pivot index since first and long could be outside the int16 range
    long pivotIndex;

    // Find the pivot index
    // Check if first element is more than middle element
    if (theArray[first] > theArray[mid])
    {
        // Median is either first or last
        pivotIndex = first;
    }
    else
    {
        // Median is either mid or last
        pivotIndex = mid;
    }

    // Check if pivot (either first or mid) is greater than last
    if (theArray[pivotIndex] > theArray[last])
    {
        // median is last since either first or mid is more than last
        pivotIndex = last;
    }

    auto pivotVal = theArray[pivotIndex];
    long i = first;
    long j = last;

    while(true)
    {
        // Find the last value below the pivot value
        while(theArray[j] > pivotVal)
        {
            j--;
        }

        // Find the first value above the pivot value
        while(theArray[i] < pivotVal)
        {
            i++;
        }

        // Check if the first above is less than the last below
        if (i < j)
        {
            // Swap the two values
            std::swap(theArray[i], theArray[j]);
        }
        //
        else
            return j;
    }
}

void myqsort(ArrayType& theArray, long first, long last, bool con)
{
    if(first < last)
    {
        // Find mid index
        long mid = (first + last)/2;

        // Get pivot index (median of three)
        long pivotIndex = partition(theArray, first, mid, last);

        // Run concurrent threads
        if(con && ((last-first) > SWITCH_SIZE))
        {
            std::future<void> fut0 = std::async(std::launch::async, &myqsort, std::ref(theArray), first, pivotIndex, con);
            std::future<void> fut1 = std::async(std::launch::async, &myqsort, std::ref(theArray), pivotIndex + 1, last, con);
            
            fut0.get();
            fut1.get();
        }
        // Run sequential
        else
        {
            myqsort(theArray, first, pivotIndex, con);
            myqsort(theArray, pivotIndex+1, last, con);
        }
    }
}