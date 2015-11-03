#include "myqsort.h"

int partition(ArrayType& theArray, int first, int mid, int last)
{

    int pivotIndex;

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

    // Swap the pivot and the first elements
    std::swap(theArray[pivotIndex], theArray[first]);
    pivotIndex = first;

    // Actually do the quick sort
    for ( int i = first; i < last; i++)
    {
        if (theArray[i] <= theArray[last])
        {
            pivotIndex++;
            std::swap(theArray[pivotIndex],theArray[i]);
        }
    }

    std::swap(theArray[pivotIndex],theArray[last]);
    return pivotIndex;
}

void myqsort(ArrayType& theArray, int first, int last, bool con)
{
    if(first < last)
    {
        //std::cout << "." << std::endl;
        int mid = (first + last) / 2;
        int pivotIndex = partition(theArray, first, mid, last);
        
        
        myqsort(theArray, first, pivotIndex -1, con);
        myqsort(theArray, pivotIndex + 1, last, con);
    }
}