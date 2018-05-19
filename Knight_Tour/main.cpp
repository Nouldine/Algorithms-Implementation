
#include "recurseKnight.cpp"
#include "bfs_knight.cpp"


int main() 
{	


	std::cout << "************************************** BFS TOUR **********************************************"<< std::endl;

	std::cout << "\n";
	
	Node_B B;

	int n;
	
    	std::cout << "Enter N:  " << std::endl;

    	std::cin >> n;

    	std::cout << "\n";

    	int knight_x, knight_y;

    	int  target_x, target_y;

    	std::cout << "Enter Knight coordinates: " << std::endl;

    	std::cout << "\n";

    	std::cin >> knight_x >> knight_y;

    	std::cout << "\n";

    	Node_B knigh_pos = { knight_x, knight_y };

    	std::cout << "Enter Gold coordinates: " << std::endl;

    	std::cout << "\n";

    	std::cin >> target_x >> target_y;

    	std::cout << "\n";

    	Node_B gold_pos = { target_x, target_y };


    	int distance =  B.BFS( knigh_pos, gold_pos, n );

    	std::cout << "Number of Moves: " <<  distance  << std::endl;

	std::cout << "\n";
	
	

    	std::cout << "************************************** BACKTRACKING TOUR **********************************************"<< std::endl;

	std::cout << "\n";
	
    	Node_D D;

    	int N;

    	std::cout << "Enter N:  " << std::endl;

    	std::cin >> N;

    	std::cout << "\n";

    	int knight_x2, knight_y2;

    	int  target_x2, target_y2;

    	std::cout << "Enter Knight coordinates: " << std::endl;

    	std::cout << "\n";

    	std::cin >> knight_x2 >> knight_y2;

    	std::cout << "\n";

    	Node_D start = { knight_x2, knight_y2 };

    	std::cout << "Enter Gold coordinates: " << std::endl;

    	std::cout << "\n";

    	std::cin >> target_x2 >> target_y2;

    	std::cout << "\n";

    	Node_D destination = { target_x2, target_y2 };

    	D.KnightMoves( start, destination, N );
	
	std::cout << "\n\n";
	

	return 0;

	
}
