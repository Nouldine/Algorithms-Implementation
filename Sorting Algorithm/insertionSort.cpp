// Author: Abdoul-Nourou Yigo

#include<iterator>
#include "Sorting.h" 

/* This function is basically doing the insertion sort 
 * Using  vector iterator
 * vec is the container that contains integers that need 
 * to be sorted 
 * n is the size of the container 
 *
 */

void Sorting::InsertionSort( std::vector<int> & vec, int n ) 
{
	// loop through the container to do the sorting 
	// using the iterator library function begin() 
	// that is the first position in  vector and 
	// end() the position of the last element in the vector  	
	for( auto it = vec.begin() + 1; it != vec.end(); ++it ) 
	{	
		value = *it; // value takes the element that is at position (it)

		std::vector<int>::iterator index = it;  // declare a vector iterator index 

		// while the sorting part of the container is greater than 
		// the element index by index  swap the elements until the 
		// we got a fully sorted container
		while( index > vec.begin() &&  *( index - 1 ) > value ) 
		{

		 	*index = *( index - 1 ); 
			index = index - 1; 
		}		
	
		 *index  = value; // or insert the element directly at position index

	}


}
