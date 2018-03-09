
// Author: Abdoul-Nourou Yigo

#include "peak_find.h"


/* This function is used to find a peak in a sequential container 
 * @param1: vec is the sequential container to hold integers 
 * @param2: left is the index to the left side of the container 
 * @param3: right is the index to right side of the container
 *
 * @return: recursive calls to return a peak 
 *
 */

int Peak::peak_finding( std::vector<int> & vec, int left, int right ) {

	
	// find the the middle of the container 
	int middle = ( left + right ) / 2;
	
	// if the middle is left or right index
	// right it
	if( middle == left  || middle == right )

		return middle;
	
	// Compare the middle element to the left element vec[ middle - 1 ] and 
	// right element vec[ middle + 1 ] if  the condition is true return the peak
	else if( vec[ middle ] >= vec[ middle - 1 ]  && vec[ middle ] >= vec[ middle + 1 ]) 
		
		return middle;

	// In case if the bigger number  found is from the left side 
	// of the container go through this side recursively
	else if( vec[ middle - 1 ] > vec[ middle ] ) 

		return peak_finding( vec, left, middle - 1); 


	else  // if the above condition is false go through the 
		// right side of the container recursively

		return peak_finding( vec, middle + 1, right );
		

}

/* Driver for divide-and-conquer for the 
 * peak_finding function 
 * @param1: vec is a sequential container 
 * @param2: vec_size is the size of the vector of integers
 * @Return: Recursive call to the peak_finding function
 *
 */
int Peak::peak( std::vector<int> & vec, int vec_size )
{
 	return peak_finding( vec, 0, vec_size - 1 );

}	
