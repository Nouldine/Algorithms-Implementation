
#include<iterator> 

#include "Sorting.h" 


// Implementation of inverse insertion sort 

void Sorting::InverseInsertion_sort( std::vector<int> & vec, int n ) 
{

	// The Loop is going backward throughout the 
	// the container vec using iterator it 	
	for( auto it = vec.end() - 1; it >= vec.begin() ; --it )
	{
		
		value = *it; 

		std::vector<int>::iterator index = it; 

		// This loop is going forward to insert number at 
		// appropriated in the container 

		while( index < vec.end() && *( index + 1) > value ) 
		{
			*index = *( index + 1 );

			index = index + 1;
		
		}

		*index = value; 

	}



}




