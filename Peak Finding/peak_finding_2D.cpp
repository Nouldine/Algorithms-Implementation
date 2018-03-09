
// Author: Abdoul-Nourou Yigo

#include "peak_find.h"

/* This function is used to find a peak in a 2D array
 * @param1: A 2D vector vec 
 * @param2: num_row is the number of rows in the container 
 * @param3: number of colums in the container
 *
 */
int Peak::peak_finding_2D( std::vector< std::vector<int> > & vec, int num_row, int num_col ) {

	
	int global_max = 0; // variable for the global maximum
		
 	int middle = num_col ; // since we divide in the recursive call middle = num_col / 2

	 std::cout << "Middle: " << middle << "\n" << std::endl;

	int i = 0; // define the global max  index

	// this for loop is used to find the global maximum
	
	for( int it = 0; it < num_row; ++it ) 
	{
		// the the number of the is greater than 
		// that the global maximum exchange them
		if( vec[ it ][ middle ] > global_max ) {
		
			global_max = vec[ it ][ middle ];

			i = it; // get the global maximum index

			std::cout << " Global maximum location: (" << i << "," << middle << ") \n" << std::endl;	
		}
	} 	

	// if we got only one column 
	// we are done
	if( middle == 0 || middle == num_col - 1 ) 

		return global_max;

	// if the number in the middle is greater than its neighbor return global maximum 
	else if ( vec[ i ][ middle - 1 ] <=  global_max && global_max >= vec[ i ][ middle + 1 ] )
 		
	 	return global_max;

	// if the number at the left is greater 
	// recurse to the left side
	else if( vec[ i ][ middle ] <= vec[ i ][ middle - 1 ] ) {

		std::cout << "GOing to the Left side \n" << std::endl;

		return peak_finding_2D( vec, num_row, middle - 1 );

	}

	
	else { // else recurse to  the right of the vector

		std::cout << " Going to the Right side \n" << std::endl;

		return peak_finding_2D( vec, num_row, middle + 1 );

		std::cout << " Global maximum index: (" << i << "," << middle << ") \n"
				  << std::endl;
	}


	
}	


/* This function is used as driver
 *
 */

int Peak::peak_2D( std::vector< std::vector<int> > & vec, int row, int col) {

	//std::cout << "calling peak_2D" << std::endl;
	
	return peak_finding_2D( vec, row, col / 2 );	
	
}






