Danny Dutton
11/03/15

# Quick Sort with Concurrency #

The quick sort I implemented is based on the Hoare partition scheme[0]. 
The algorithm looks are the first and last indicies of the vector and then 
move towards the pivot point. When it detects an element (i) below the pivot 
and one above the pivot (j) that are out of order (corrent order: i < 
pivotValue < j), it swaps the two values and keeps going in toward the pivot. 
When the pivot is reached, the partition function exits and returns the pivot 
index.

This pivot index is then used recursivly by the caller function, myqsort, 
to call itself but this time using the array's first element as the first and 
the pivot as the last element in the range to be sorted. After the bottom of 
this recursion is reached, when the first and last elements of the selected 
range of the array overlap, the algoritm then focuses on the next smallest 
chunk. The entire recursion tree resembles a binary tree.

The pivot point is chosen using median-of-three: first index, middle 
index, and last index. The middle is simply integer average of the first and 
last. This median allows the best pick of a pivot point without taking any 
further steps. A better pivot would be dividing the array up into three 
sections and doing median-of-three on each and finding the median of the 
medians. This could go further but the benefits are neglible.

I adapted my sequential quick sort for concurrency by having a input 
boolean and an if statement to direct to which calls to myqsort would be 
wanted. If a concurrent sort is wanted, 'bool con' should be set to true. If 
false, then myqsort will only run a sequential sort on the array.

As long as the distance between the first and last indices is greater than 
10K, then two concurrent threads will be created that will spawn more 
concurrent threads as long as the distance remains greater than 10K. As soon 
as the distance is past this threshold, myqsort will switch over to using 
sequential sorts. This is because at a certain size of a list, the time it 
takes to spawn threads and kill them costs more in time than you benefit from 
the concurrency.

For example, when sorting the 1M item list, the depth of the threads will 
approach seven. This means there are (2^7)-1 threads currently running on 
average because this is assuming the pivot is always in the middle of the 
array selection. At the seventh layer of threads, the threshold for array size 
is passed and myqsort resorts to using sequential sorts. This number of 
threads was determined by adjusting the threshold value until the peak average 
times were reached for a 1M item list sort. This number could be better tuned 
but for now, this gave me good results.

	My results were not strong contenders for either concurrent or sequential. 
Most of the time concurrent results were faster but not by much. The magnitude 
of the exponentials were always near identical with just the coefficient being 
slighly better. If this sort was to be used on much larger data sets, the 
difference in time would actually matter. At this level, modern computers can 
handle data sets as large as our testing ones very easily. In the Hoare paper, 
there is a time for a quick sort on 1960s hardware that is over 3 minutes for 
a 1K data set. My hardware does that in 67 microseconds.

I found that having more thread depth actually led to very slow sort times. I tested this all the way down to array sizes of three. The times became massive and sometimes would just segfault instead. Additionally, low thread depth led to times that were near identical to the slower sequential sort. I did not run this code in the reference VM so I do not know how it runs on a single core. Simply, more cores would allow for a greater number of threads.

[0]: http://comjnl.oxfordjournals.org/content/5/1/10