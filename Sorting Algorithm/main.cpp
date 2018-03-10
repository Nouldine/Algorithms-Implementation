
#include<random> 
#include<algorithm>
#include<ctime> 
#include<chrono>
#include<functional>

#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "insertionSort_inverse.cpp"


int main() {

	
	//  variable to the start measure the programs executions 
	clock_t begin = clock();

	Sorting S; 

	
	int maxsize;  // size of random numbers that needs to be  generated

	std::vector<int> vec; // container 

	std::cout<< "Enter a random numbers range " << std::endl;

	std::cin >> maxsize;

	// push random numbers that need to be sorted in the vector 
	for( int i = 1; i < maxsize; ++i )
		 
		vec.push_back( rand() % maxsize + 1 ); 
	
	
	auto n = vec.size();
	
	
	std::cout << " Unsorted vector: " << std::endl;

	for( auto c : vec ) 
		
		std::cout << c << " ";

	std::cout << std::endl;
	
	// Call insertion sort function 	
	//S.InsertionSort( vec, n );
	
	S.InverseInsertion_sort( vec, n );
		
	// Call mergeSort function
 	//S.MergeSort(vec);


		
	// Printout a sorted container 
	std::cout << " Sorted vector: " << std::endl; 

	for( auto c : vec ) {	

		
			std::cout << c << " ";

	}
	std::cout << std::endl;
	

	
	clock_t  end = clock();

	double duration = double( end - begin ) / CLOCKS_PER_SEC;

	// print out the duration 
	std::cout << "Duration: " << duration << "s" << std::endl;
	

	return 0;
}
