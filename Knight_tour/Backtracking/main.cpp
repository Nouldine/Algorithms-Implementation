
#include "Knight_backtracking.hpp"

int main() {

	std::cout <<"************************ BACKTRACKING TOUR ***********************" << std::endl;
	std::cout <<"\n";

	KnightBacktracking Knight;
	
	int vec_size;
	std::cout <<"Enter the desire board size: " << std::endl;
	std::cin >> vec_size;
	std::cout <<"\n";

	int knight_x, knight_y;
	int target_x, target_y;

	std::cout <<"Enter knight position: "<< std::endl;
	std::cout <<"\n";
	std::cin >> knight_x >> knight_y;
	std::cout <<"\n";
	KnightBacktracking start = {knight_x, knight_y};

	std::cout <<"Enter Gold position: " << std::endl;
	std::cout <<"\n";
	std::cin >> target_x >> target_y;
	std::cout <<"\n";
	KnightBacktracking destination = {target_x, target_y};

	Knight.knight_moves(start, destination, vec_size);
	std::cout <<"\n\n";

	return 0;
}
