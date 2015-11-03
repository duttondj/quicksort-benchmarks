void quickSort(vector<int>& A, int p,int q)
{
    int r;
    if(p<q)
    {
        r=partition(A, p,q);
        quickSort(A,p,r);  
        quickSort(A,r+1,q);
    }
}

int partition(vector<int>& A, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
        }

    }

    swap(A[i],A[p]);
    return i;
}


// Functor number generator using normal distribution
class fill_normal
{
public:

  // Create random device and seed
  fill_normal()
  {
    std::random_device rd;
    gen.seed(rd());
  }
  
  // Override operator to put random value in x
  void operator()(double & x)
  {
    x = p(gen);
  }

private:
  // Mersenne Twister engine
  std::mt19937 gen;
  // Use normal distribution
  std::normal_distribution<double> p; 
};


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
			seqSort(data, 0, data.size()-1);
			end = std::chrono::system_clock::now();
			
			// Save and display sort time for array size
			elapsed_seconds = end-start;
			sorttimes.push_back(elapsed_seconds.count());
			std::cout << N <<  "\t" << elapsed_seconds.count() << std::endl;
		}
	}

	std::cout << "Finished sequential sorts" << end;

	// Concurrent Quick Sort
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
		conqSort(data, 0, data.size()-1);
		end = std::chrono::system_clock::now();
		
		// Save and display sort time for array size
		elapsed_seconds = end-start;
		sorttimes.push_back(elapsed_seconds.count());
		std::cout << N <<  "\t" << elapsed_seconds.count() << std::endl;
	}

	std::cout << "Finished concurrent sorts" << end;
	std::cout << "Done" << endl;
	
	return 0;
}
