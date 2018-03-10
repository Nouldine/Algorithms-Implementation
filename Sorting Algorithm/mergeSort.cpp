
// Author: Abdoul-Nourou Yigo


#include "Sorting.h" 


/* This function is supposed to merge the subvectors left_vec and right_vec to the main vector ( main_vec ) 
 *  
 *  left_vec is the left subvector
 *  right_vec is the right subvector 
 *  main_vec is the main vector that is supposed to to be sorted
 *  
 */


void Sorting::Merge( std::vector<int> & left_vec, std::vector<int> & right_vec, std::vector<int> & main_vec ) 
{

	int left_vec_size = left_vec.size(); // left vector size  
	int right_vec_size = right_vec.size();  // right vector size
       	
	int i = 0; // the index to left_vec 
	int j = 0; // the index of th right_vec 
	int k = 0; // the index to the main_vec 

	// While to the indexes to the left and right subarrays are
	// less than the sizes of the those vectors respectively
	// keep looping 
	
	while( i < left_vec_size && j < right_vec_size ) 
	{
		// if the element in the left_vec 
		// is inferior to the element '
		// in the right righ_vec insert this 
		// element first in main_vec 
		// else  insert the element of right_vec in 
		// the main_vec
		if( left_vec[ i ]  <= right_vec[ j ] ) 
		{
			main_vec[ k ]  = left_vec[ i ]; 

			++i;	// go to the next item in left_vec 
		}

		else 
		{
			main_vec[ k ] = right_vec[ j ]; 

			++j; // to the next item in right_vec
		}

		++k;  // go the next index in main_vec
	}

	// Copy the rest of items in left_vec 
	// in the main_vec
	while ( i < left_vec_size ) 
	{
	 	main_vec[ k ] = left_vec[ i ];

		++i;
		++k;
	}	

	// copy the rest of the items in right_vec 
	// i the the main_vec
	while( j < right_vec_size ) 
	{
		main_vec[ k ] = right_vec[ j ]; 

		++j;
		++k;

	}

 
}


/*
 * This function  is used to  divide the main vector ( main_vec ) in 
 *  two subarray left_vec ( left container ) and rigth_vec ( right container ) 
 *  
 * And then the Merge() is called recursively to sort the containers
 *
 */

void Sorting::MergeSort( std::vector<int> & main_vec ) 
{
	// size of the main vector
	auto main_vec_size = main_vec.size(); 
	
	// if the main vector size  is less than 2 
	// there is not sorting to be done
	if( main_vec_size < 2 )

		return;// main_vec_size; 

	// the middle of the main_vec 
	auto mid = main_vec_size / 2;

	auto left_vec_size = mid; // left container size 

	auto right_vec_size = main_vec_size - mid; // right container size

	std::vector<int> left_vec(left_vec_size);  // left container of size left_vec_size 

	std::vector<int> right_vec(right_vec_size); // right container of size right_vec _size 

	// Put the elements to the left vector  
	for( int i = 0; i <  mid; ++i)
		
		left_vec[ i ] = main_vec[ i ];

	// Put the elements to the right vector
	for( int i = mid; i < main_vec_size; ++i) 

		right_vec[ i - mid ] = main_vec[ i ]; 
	
	// the MergeSort() function called itself recursively 
	// to divide the array in subarrays  to be sorted 
	MergeSort( left_vec );

	MergeSort( right_vec );
	
	// Called the Merge() function to sort 
	// the elements appropriately
	Merge( left_vec, right_vec, main_vec );

	
}
 
