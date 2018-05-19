#include <iostream> 
#include <vector> 
#include <map> 
#include <algorithm>

#define Num_moves 8


struct Node_D 
{

	Node_D() = default; 

	Node_D( int _x, int _y) : x{ _x }, y { _y } { } 

	bool knight_backTrack( std::vector< std::vector< int >>, Node_D, Node_D, int, int);

	bool valid_coordinates( Node_D, std::vector< std::vector< int > >, int );

	void printPath( std::vector< Node_D > &  );

	void KnightMoves( Node_D, Node_D, int );

	
	std::vector< int > row    {-2, -1, 1, 2, 2, 1, -1, -2 };

        std::vector< int > column { 1, 2, 2, 1, -1, -2, -2, -1 };

	int x, y;


};


