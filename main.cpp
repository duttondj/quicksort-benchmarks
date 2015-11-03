#include <vector>
#include <algorithm>
#include <random>
#include <thread>
#include <future>
#include <iostream>

typedef std::vector<double> ArrayType;

int main()
{
	std::std::vector<double> sorttimes;

	std::cout << "Running quick sort benchmarks, please wait" << endl;
	// Run sequential quick sort (would be better to put this in own thread)
	for(int i = 0; i < 10; i++)
	{
		for(long N = 1; N <= 100000; N = 10*N){
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
			qsort(data, 0, data.size()/2, data.size()-1, 0);
			end = std::chrono::system_clock::now();
			
			// Save and display sort time for array size
			elapsed_seconds = end-start;
			sorttimes.push_back(elapsed_seconds.count());
			std::cout << N <<  "\t" << elapsed_seconds.count() << std::endl;
		}
	}

	std::cout << "Finished sequential sorts" << end;

	// Concurrent Quick Sort
	for(int i = 0; i < 10; i++)
	{
		for(long N = 1; N <= 100000; N = 10*N){
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
			qsort(data, 0, data.size()/2, data.size()-1, 1);
			end = std::chrono::system_clock::now();
			
			// Save and display sort time for array size
			elapsed_seconds = end-start;
			sorttimes.push_back(elapsed_seconds.count());
			std::cout << N <<  "\t" << elapsed_seconds.count() << std::endl;
		}
	}

	std::cout << "Finished concurrent sorts" << end;
	std::cout << "Done" << endl;
	
	return 0;
}
