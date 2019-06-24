
#include "Knight_backtracking.hpp"

/* This function is used to verify boundaries
 * of the user input. If the user enters a wrong
 * coordinate the function will invalidate the process
 *
 *@param1: board is 2D vector
 *@param2: myCoordinate represents a set of point x and y
 *@param3: vec_size that is the size 
 *
 */
bool KnightBacktracking::valid_coordinate(std::vector<std::vector<int>> & board, KnightBacktracking & myCoordinate, int vec_size) {

	//std::cout <<"Calling KnightBacktracking::valid_coordinate(KnightBacktracking & start, std::vector<std::vector>> board, int vec_size)" << std::endl;	
	int theX = myCoordinate.x; 
	int theY = myCoordinate.y; 

	if((theX >= 1 && theX< vec_size) && (theY >= 1 && theY < vec_size) && (board[theX][theY] == 0) && vec_size >= 3)
		return true; 
	else
		return false;
}

void KnightBacktracking::print_path(std::vector<KnightBacktracking> & path ) {

	//std::cout <<"Calling KnightBacktracking::print_path(std::vector<KnightBacktracking> & path)" << std::endl; 
	
	for(auto & route : path)
	{
		std::cout <<"(" << route.x <<"," << route.y <<")" <<" ";
	}
}

/* This function is used to find the path from the source to 
 * the destinations using the depth first search approach
 *
 * @param1: board that is a 2D vector representing the chess board
 * @param2: start is the location of the knight with x and y coordinates 
 * @param3: destination is the location of the gold
 * @param4: vec_size is the size of the 2D vector 
 * @param5: moves that is the number of possible moves
 */
bool KnightBacktracking::knight_backtrack(std::vector<std::vector<int>> & board, KnightBacktracking & start, KnightBacktracking & destination, int vec_size, int moves) {

	//std::cout <<"KnightBacktracking::knight_backtrack(std::vector<std::vector<int>> & board, KnightBacktracking & start, KnightBacktracking & destination, int vec_size, int moves)"<< std::endl; 
	KnightBacktracking next;
	std::vector<KnightBacktracking> path;

	if(start.x == destination.x && start.y == destination.y)
	{
		std::cout <<"Number of moves: " << moves;
		std::cout << std::endl; 
		std::cout <<"Path: "; 
		return true;
	}

	for(int i = 0; i < num_moves; ++i)
	{
		// get the next move
		next.x = start.x + row[i];
		next.y = start.y + column[i];

		if(valid_coordinate(board, next, vec_size) && valid_coordinate(board, destination, vec_size)) {
			board[next.x][next.y] = moves + 1;

			if(knight_backtrack(board, next, destination, vec_size, moves + 1) == true)
			{
				path.push_back(next);
				print_path(path);
				return true;
			}
			else
			{
				board[next.x][next.y] = 0;
			}
		}
	}
	
	return false;
}

/* This function is used as driver. It would create the 2D vector that would
 * the board.
 * @param1: start represents the starting point
 * @param2: destination represents the start
 * @param3: vec_size represents the 2D vector size
 */
void KnightBacktracking::knight_moves(KnightBacktracking & start, KnightBacktracking & destination, int vec_size) {
	
	//std::cout <<"KnightBacktracking::knight_moves(KnightBacktracking & start, KnightBacktracking & destination, int vec_size)" << std::endl;
	std::vector<std::vector<int>> board;
	int i, j;

	for(i = 1; i <= vec_size; ++i)
	{
		std::vector<int> tmp; 
		for(j = 1; j <= vec_size; ++j)
			
			tmp.push_back(0);
		
		board.push_back(tmp);
	}
	
	if(knight_backtrack(board, start, destination, vec_size, 0 ) == false)
		
		std::cout <<"Move is not possible" << std::endl;
	else
		return;
}

