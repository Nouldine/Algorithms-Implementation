

#include <random> 
#include "peak_find.cpp"
#include "peak_finding_2D.cpp"
#include "peak_find.h"


int main() {

	
	Peak P;

	int rand_size; // Variable to generate random numbers for 1D vector
	
	std::vector<int> vec; //{ 12, 14, 9, 7, -5, 3, 18, 2 };

	//std::vector<std::vector<int>> vec2;
	
	
					/*{{ 10, 8,  10, 10},
					    {  14, 13, 12, 11 },
					    {  15, 9,  11, 21 },
					    {  16, 17, 19, 20}}; */

	// fill the container with random numbers


	//std::vector< std::vector<int> > vec3;

	// Get the range of random number from the user
	std::cout << " Enter the size for one dimensional vector " << std::endl;

	std::cin >> rand_size;
	
	// push random number in the container
	for( int i = 0; i < rand_size; ++i ) 

		vec.push_back( rand() % rand_size + 1 );

	
	int vec_size = vec.size();    // size of the container

	std::cout << "***************** 1D PEAK ****************************" << std::endl;

	std::cout << "Vector contain \n" << std::endl; 
 
	// Display index for the container
	for( int i = 0; i < vec.size(); ++i ) 

		std::cout << i << "\t";

	std::cout << std::endl;

	// Display the vector contain
	for( int i = 0; i < vec.size(); ++i )

		std::cout << vec[ i ] << "\t";

	 std::cout << std::endl;	
	

	std::cout << "\n" << std::endl;

	int find = P.peak( vec, vec_size ); // call the driver function for  the 1D peak
	
	std::cout<< "Peak location: " << find  << "\n" << std::endl;
	

	std::cout<< "******************* 2D PEAK **************************" << std::endl;

	int  row; // row of the 2D vector 
	int col; // column of the 2D vector
    int ran_num; // range of the random number

	// 2D vector
	std::vector< std::vector<int> > main_vec;	

	std::cout << " Enter row and column " << std::endl; 

	std::cin >> row >> col;

	std::cout << " Enter random number range: " << std::endl;	

	std::cin >> ran_num;

	// These loops are used to fill the 2D vector with random number

	for( int i = 0; i < row; ++i ) {
			
		std::vector<int> tmp_vec; // this vector is used to create rows in the main vector
	
	  	for( int i = 0; i < col; ++i)

	  		tmp_vec.push_back( rand() % ran_num + 1 );
	
		main_vec.push_back( tmp_vec ); // push row of number in the main vector

	}

	std::cout << " Matrix Content " << std::endl;

	// Display the matrix content with rows and column indexes
	for( int k = 0; k < main_vec.size(); ++k )
		
		std::cout << " " << " " << k << "\t"; // display column indexes
	
	std::cout << std::endl;

	for( int i = 0; i < main_vec.size() ; ++i ) {

		std::cout << i; // display the matrix row indexs
		for( int j = 0; j < main_vec[i].size(); ++j ) 

			std::cout << " " << " " << main_vec[ i ][ j ] << "\t" ; // Display the container content
		
		std::cout << std::endl;

	}
	
	std::cout << '\n';

	// calling the peak_finding_2D function driver, since
	// here the row = the container size  and since the main_vec is fill with vectors at each row 
	// the size of the first vector is the number of columns for all the 
	// vectors in the main_vec 
	int peak = P.peak_2D( main_vec, main_vec.size(), main_vec[0].size() );

	std::cout << " 2D Peak : " << peak  << std::endl;
}

