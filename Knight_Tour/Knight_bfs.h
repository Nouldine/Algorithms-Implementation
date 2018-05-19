
#ifndef GRAPH_H
#define GRAPH_H

#include <vector> 
#include <string> 
#include <iostream>
#include <iterator>
#include <memory>
#include <array>
#include <limits>
#include <map>


#define Num_move 8 
/*
enum 
{
	INFINITY = std::numeric_limits< int >::max()

};
*/

/*
enum Color 
{
 
 	WHITE, 
	GRAY, 
	BLACK

}; 


struct Vertex 
{

	Vertex() = default;

	Vertex( const int  vertex ) : id { vertex } { }

	int id; 
	
	Color color; 

	int frontiers;

	std::shared_ptr< Vertex > parent ;


	~Vertex() { } 

};	



class Graph {
	
	
	public: 
		
		Graph() = default;
		
		//Graph( int size ) :  vertices{ size }, adj{ size } { }



		//std::vector< std::shared_ptr< Vertex > > get_vertices() { return vertices; }

		~Graph() { }


	private:
	
		std::vector< std::shared_ptr< Node >> starting ;

		std::vector< std::shared_ptr< Node > >  destination;

};

*/


struct Node_B {

	
	Node_B() = default; 	

	Node_B( int _x, int _y, int dist = 0, std::vector< std::pair< int, int >> p = { { 0, 0 } } ):  
		
		x_coordinate{ _x }, y_coordinate{ _y }, distance { dist }, path_node { p } { }


	std::vector< int > row    {-2, -1, 1, 2, 2, 1, -1, -2 };
	
	std::vector< int > column { 1, 2, 2, 1, -1, -2, -2, -1 };	
		
	std::vector< std::pair< int, int >> path_node;

	int BFS( Node_B, Node_B , int );

	bool valid_coordinate( int, int, int );
	

	void printPath( std::vector< std::pair< int, int > > ); 	
	
	int x_coordinate, y_coordinate;

	int distance; 


	bool  operator < ( const Node_B& pair  ) const 
	{
		return  x_coordinate < pair.x_coordinate  ||  ( x_coordinate == pair.x_coordinate &&  pair.y_coordinate );

	}


	~Node_B() 
	{
	       //std::cout << "Destruction " << std::endl;	
       
	}
	

};


#endif 
