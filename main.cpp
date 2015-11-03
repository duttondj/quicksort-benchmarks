#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <future>
#include <iostream>
#include <cstdio>
#include <cmath>
#include "fill_normal.h"
#include "myqsort.h"

#ifndef _ARRAYTYPE
#define _ARRAYTYPE
typedef std::vector<double> ArrayType;
#endif

int main()
{
	double min, max, sum;

	std::vector<double> sorttimes;
	std::vector<double> mintimes;
	std::vector<double> maxtimes;
	std::vector<double> avgtimes;

	std::cout << "Running quick sort benchmarks, please wait" << std::endl;
	// Run sequential quick sort (would be better to put this in own thread)
	for (long N = 1; N <= 1000000; N = 10*N)
	{
		for (int i = 0; i < 10; i++)
		{
			// Create vector of doubles and a fill_normal object		
			ArrayType data(N);
			fill_normal d;

			// Fill every element of vector with random numbers
			for_each(data.begin(), data.end(), d);	

			// Start and end times of thread
			std::chrono::time_point<std::chrono::system_clock> start, end;
			// Total time running thread
			std::chrono::duration<double> elapsed_seconds;

			// Record start time, run sort, record stop time
			start = std::chrono::system_clock::now();
			myqsort(data, 0, data.size()-1, false);
			end = std::chrono::system_clock::now();
			
			// Save and display sort time for array size
			elapsed_seconds = end-start;
			sorttimes.push_back(elapsed_seconds.count());
			//std::cout << N <<  "\t" << elapsed_seconds.count() << std::endl;
		}
	}

	std::cout << "Finished sequential sorts" << std::endl;

	// Concurrent Quick Sort
	for (long N = 1; N <= 1000000; N = 10*N)
	{
		for (int i = 0; i < 10; i++)
		{
			// Create vector of doubles and a fill_normal object		
			ArrayType data(N);
			fill_normal d;
			
			// Fill every element of vector with random numbers
			for_each(data.begin(), data.end(), d);

			// Start and end times of thread
			std::chrono::time_point<std::chrono::system_clock> start, end;
			// Total time running thread
			std::chrono::duration<double> elapsed_seconds;

			// Record start time, run sort, record stop time
			start = std::chrono::system_clock::now();
			myqsort(data, 0, data.size()-1, true);
			end = std::chrono::system_clock::now();
			
			// Save and display sort time for array size
			elapsed_seconds = end-start;
			sorttimes.push_back(elapsed_seconds.count());
			if(elapsed_seconds.count() < 0)
				std::cout << N <<  "\t" << elapsed_seconds.count() << std::endl;
		}
	}

	std::cout << "Finished concurrent sorts" << std::endl;
	std::cout << "Done" << std::endl;

	// There are 14 sets of data
	for (int i = 0; i < 14; i++)
	{
		// Set min and max to first time for a new data set
		min = sorttimes[i*10];
		max = sorttimes[i*10];
		sum = 0;
		
		// Ten repeated trials per data set
		for (int j = 0; j < 10; j++)
		{
			// Check if time is less than the current min
			if (sorttimes[i*j] < min)
				min = sorttimes[i*j];
			
			// Check if time is more than the current max
			if (sorttimes[i*j] > max)
				max = sorttimes[i*j];
			
			// Add time to running total
			sum += sorttimes[i*j];
		}

		// Save min, max, and computed mean
		mintimes.push_back(min);
		maxtimes.push_back(max);
		avgtimes.push_back(sum/10.0);
	}

	std::cout << "List Size    Sequential Sort Time (s)                           Concurrent Sort Time (s)" << std::endl;
	std::cout << "             min              max              average          min              max              average" << std::endl;
	std::cout << "---------    -------------    -------------    -------------    -------------    -------------    -------------" << std::endl;
	
	for (int i = 0; i < 7; i++)
	{
		printf("%-12d %-8e     %-8e     %-8e     %-8e     %-8e     %-8e\n", (int)pow(10,i), mintimes[i], maxtimes[i], avgtimes[i], mintimes[i+7], maxtimes[i+7], avgtimes[i+7]);
	}
	
	return 0;
}
