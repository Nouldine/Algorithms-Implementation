
#include "Recurse_knight.h"
#include <queue> 
#include <iostream> 
#include <map>
#include <list>
#include <limits>
//#include <algorithm>
		 


/* This function is used to verify bounderies  
 * of the user input in case if the user user 
 * a wrong coordinate the function will invalidate 
 * the process
 * @param1: x coordinate that could be the row in the chess board
 * @param2: y coordinate that the column in the chess board
 * @param2: n the  size
 *
 */

bool Node_D::valid_coordinates( Node_D start, std::vector< std::vector< int > > board, int vec_size ) 
{

	//std::cout << "Calling  valid_coordinates " << std::endl;

	int _x = start.x; 
	int _y = start.y; 

		
	// Verify the if we have good coordinate
	if( ( _x >= 1 && _x  < vec_size ) && ( _y >= 1 && _y < vec_size ) && ( board[_x][_y] == 0 )  && vec_size >= 3 )

		return true;

	return false;


}

/* This  function is used to print the coordinate from 
 * the source to the destination using a vector of pair
 * @param: path that is a vector of pair to store the coordinate x and y 
 *
 */

void Node_D::printPath( std::vector< Node_D > & path ) {


	//std::cout << "Calling printPath() " << std::endl; 

	//std::cout << "Trajectory path: " ;


	for( auto & route : path ) {
		
		std::reverse( path.begin(), path.end() );
		std::cout << "(" << route.x << "," << route.y << ")" << ' ';
	}

	//std::cout << std::endl;


	//std::cout << "\n";
}

/* This is the main function to find the path from the 
 * source to the destinattion using the breath first search
 * approach.
 * @param1: start  is the location of the knight with x and y  coordinate 
 * @param2: destination is the location of the gold  
 * @param3: vec_size that is the vector size that needs to be allocated
 * @param4: is the number of Moves to the destination
 *
 */

bool Node_D::knight_backTrack( std::vector< std::vector< int >> board, Node_D start, Node_D destination, int vec_size, int moves )
{
	//std::cout << "Calling knight_DFS() " << std::endl;
	
	Node_D next;

	/*	
	for( int i = 0; i < board.size(); ++i ) {

		for( int j = 0; j < board[i].size(); ++j ) 

			std::cout << board[ i ][ j ] << "\t";

        	std::cout << std::endl;

	}

	*/

	std::vector< Node_D > path; 
	
	if( start.x == destination.x && start.y == destination.y ) 
	{
		std::cout << "Number of Moves: " << moves ;
	
		std::cout << std::endl;

	 	std::cout << "Path: " ;	

		 return true; 

	}


	for( int i = 0; i < Num_moves; ++i )
	 {
		 // get the next move 	
		 next.x = start.x + row[i]; 

		 next.y = start.y + column[i]; 
		 
		 if( valid_coordinates( next, board, vec_size ) && valid_coordinates( destination, board, vec_size ) ) 
		 {
				board[ next.x ][ next.y ] = moves + 1;

				if( knight_backTrack( board, next, destination, vec_size, moves + 1 ) == true ) 
				{

					path.push_back( next );
				
					printPath( path );
			
					return true; 
				}

				else

				board[ next.y ][ next.y ] = 0; 
		 }

	 }

	 return false; 

}

/*
 * This function is used as driver for the knight_backrack()
 * @param1: start is the coordinate for the destination 
 * @param2: destination is the set of coordinate for the destination'
 * @param3: size is the size of the container 
 *
 */

void Node_D::KnightMoves( Node_D start, Node_D destination, int size )	
{

	std::vector< std::vector< int > > board;
	
	int i, j;

	for( i = 1; i <= size; ++i ) 
	{
		std::vector< int > tmp;

		for( j = 1; j <= size;  ++j )

			 tmp.push_back( 0 );

		board.push_back( tmp );

	}


	if( knight_backTrack( board, start, destination, size, 0 ) == false )

		std::cout << "Move is not possible " << std::endl;

	else 
		return;
		
	
}	


