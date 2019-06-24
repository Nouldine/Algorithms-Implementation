
#include "knight_bfs.hpp"

int main()
{
	std::cout <<"********************* BFS TOUR *******************************"<< std::endl;
	std::cout <<"\n";
	
	NodeKnight theNode;
	int theSize;
	
	std::cout <<"Enter the board size: " << std::endl; 
	std::cin >> theSize;
	int knight_x, knight_y;
	int target_x, target_y; 

	std::cout <<"Enter Knight coordinates: " << std::endl;
	std::cout << std::endl;
	std::cin >> knight_x >> knight_y;
	std::cout  <<"\n"; 
	NodeKnight knight_pos = {knight_x, knight_y}; 

	std::cout <<"Enter Gold coordinates: "<< std::endl;
	std::cout <<"\n";
	std::cin >> target_x >> target_y; 
	std::cout <<"\n";
	NodeKnight gold_pos = {target_x, target_y};

	int distance = theNode.bfs_procedure(knight_pos, gold_pos, theSize);
	std::cout <<"Number of Moves: " << distance << std::endl;
	std::cout << std::endl;

	return 0;
}
