#include "myqsort.h"

int pivot(ArrayType& theArray, int first, int mid, int last)
{

    double first_val = theArray[first];
    double mid_val = theArray[mid];
    double last_val = theArray[last];
    double pivotIndex;
    double pivotVal;

    // // Median-of-three
    // // First check if any values are equal to eachother
    // if ((first_val != mid_val) && (first_val != last_val) && (mid_val != last_val) && false)
    // {
    //     // pick median value
    //     pivotVal = std::max(std::min(first_val, last_val), std::min(std::max(first_val, last_val), mid_val));
        
    //     // Find the index that goes with that value
    //     if(pivotVal == first_val)
    //         pivotIndex = first-1;
    //     if(pivotVal == mid_val)
    //         pivotIndex = mid-1;
    //     if(pivotVal == last_val)
    //         pivotIndex = last-1;
    // }
    // // Hoare partition scheme
    // // At least two values are identical so just pick first element as pivot
    // else
    // {
        pivotIndex = first-1;
        pivotVal = first_val;
    // }


    // Actually do the quick sort
    for(int i = first; i <= last-1; i++)
    {
        if (theArray[i] <= pivotVal)
        {
            pivotIndex++;
            std::swap(theArray[pivotIndex],theArray[i]);
        }

    }

    std::swap(theArray[pivotIndex+1],theArray[first]);
    return (pivotIndex+1);
}

void myqsort(ArrayType& theArray, int first, int last, bool con)
{
    if(first < last)
    {
        int mid = (first + last) >> 1;
        int pivotIndex = pivot(theArray, first, mid, last);
        
        myqsort(theArray, first, pivotIndex - 1, con);
        myqsort(theArray, pivotIndex + 1, last, con);
    }
}