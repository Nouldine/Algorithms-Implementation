
#include <queue> 
#include <iostream> 
#include <map>
#include <limits>

#include "Knight_bfs.h"


/* This function is used to verify bounderies  
 * of the user input in case if the user user 
 * a wrong coordinate the function will invalidate 
 * the process
 * @param1: x coordinate that could be the row in the chess board
 * @param2: y coordinate that the column in the chess board
 * @param2: n the  size
 *
 */

bool Node_B::valid_coordinate( int x, int y, int n ) 
{
	// Verify the if we have good coordinate
	if( x >= 1 && x <= n && y >= 1 && y <= n && n >= 3 && n <= 300 )	

		return true;

	else

		return false;


}

/* This  function is used to print the coordinate from 
 * the source to the destination using a vector of pair
 * @param: path that is a vector of pair to store the coordinate x and y 
 *
 */

void Node_B::printPath( std::vector< std::pair< int, int >> path ) {


	std::cout << std::endl;

	std::cout << "path: " ;

	for( auto pair : path ) {
		
		std::cout << "(" << pair.first  << "," << pair.second << ")" ;
	
	}

	std::cout << std::endl;


	std::cout << "\n";
}

/* This is the main function to find the path from the 
 * source to the destinattion using the breath first search
 * approach.
 * @param1: start  is the location of the knight with x and y  coordinate 
 * @param2: destination is the location of the gold  
 * @param3: n is used to maintain the boundaries
 *
 */
int  Node_B::BFS( Node_B start, Node_B destination , int n )
{
	
	// Create a map to keep track of visited 
	// Node 
	//std::map< Node, std::pair< bool, int > > node_visited;	
	
	int moves = 0; 
	// Vector to store the visited Nodes
	std::vector< std::pair< int, int >> route;

	// stored the source Node since it is the first visited  
	route.push_back({ start.x_coordinate, start.y_coordinate } );	

	// Create a Node object for the source
	Node_B src = { start.x_coordinate, start.y_coordinate , start.distance , route };

	bool visited_node[ n + 1 ][ n + 1 ];

	// since we are using BFS approach 
	// we are using queue data structure 
	std::queue< Node_B >  Q; 

	//visited_node[src.x_coordinate][src.y_coordinate] = true;	 

	// Push the source information 
	// in the queue
	Q.push( src ); 
	
	// marked the source as visited
	//node_visited[src] = true;
	
	// as long as the queue 
	// the queue is not empty keep looping
	// until  the last Node in the queue 
	while( !Q.empty() )
	{

		// get the front element in the queue
		auto node = Q.front();

		auto  row_i = node.x_coordinate;

		auto column_j = node.y_coordinate;

		int dist = node.distance;

		route = node.path_node;
			
		Q.pop(); // Dequeue the queue


		// if we got to the destination Node  we are done 
		if( row_i == destination.x_coordinate && column_j ==  destination.y_coordinate ){
			
			printPath(route);  // print the path to the destination

			return dist; // return the numbers to get to the destination 


		 } 
	
		//  Get the right coordinates for 
		//  to effectuate correct moves to the destination
		 for( int  i = 0; i < Num_move; ++i )
		 {

			 int x = row_i + row[ i ]; // calculate the moves for the row 

			 int y = column_j + column[ i ]; // calculate the move for the column 

			 // verify if the coordinates are correct
			 if( valid_coordinate( x, y, n )  ) {
		
				 // push the correct moves to the route vector
				route.push_back( { x, y } );
				
				Node_B next = { x, y, dist + 1, route };
	

				// if there are still unvisited Nodes visit them
				if( !visited_node[x][y] )
				{

					Q.push( next );

					visited_node[x][y] = true;
					
				  }
					

				// get red of the of last elements 
				// in the path vector
				 route.pop_back();

			}// end if
		 
		 } // end for 

	} // end for loop

	
} // end function


