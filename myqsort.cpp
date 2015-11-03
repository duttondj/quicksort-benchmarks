#include "myqsort.h"

int pivot(ArrayType& theArray, int first, int mid, int last)
{

    double first_val = theArray[first];
    double mid_val = theArray[mid];
    double last_val = theArray[last];
    double pivotIndex;
    double pivotVal;


    // Median-of-three
    // First check if any values are equal to eachother
    if ((first_val != mid_val) || (first_val != last_val) || (mid_val != last_val))
    {
        // pick median value
        pivotVal = std::max(std::min(first_val, last_val), std::min(std::max(first_val, last_val), mid_val));
        
        // Find the index that goes with that value
        if(pivotVal == first_val)
            pivotIndex = first_val;
        if(pivotVal == mid_val)
            pivotIndex = mid_val;
        if(pivotVal == last_val)
            pivotIndex = last_val;
    }
    // Hoare partition scheme
    // At least two values are identical so just pick first element as pivot
    else
    {
        pivotIndex = first;
        pivotVal = first_val;
    }

    // Actually do the quick sort
    for(int i = first + 1; i < last; i++)
    {
        if (theArray[i] <= pivotVal)
        {
            pivotIndex = pivotIndex + 1;
            std::swap(theArray[pivotIndex],theArray[i]);
        }

    }

    std::swap(theArray[pivotIndex],theArray[first]);
    return pivotIndex;
}

void myqsort(ArrayType& theArray, int first, int mid, int last, bool con)
{
    if(first < last)
    {
        int pivotIndex = pivot(theArray, first, mid, last);
        
        if(con)
        {
        	auto fut0 = std::async(std::launch::async, &myqsort, std::ref(theArray), first, (pivotIndex-first)/2, pivotIndex, con);
      		auto fut1 = std::async(std::launch::async, &myqsort, std::ref(theArray), pivotIndex + 1, (last-pivotIndex-1)/2, last, con);

            fut0.get();
            fut1.get();
        }
        else
        {
        	myqsort(theArray, first, (pivotIndex-first)/2, pivotIndex, con);
        	myqsort(theArray, pivotIndex + 1, (last-pivotIndex-1)/2, last, con);	
        }
        
    }
}