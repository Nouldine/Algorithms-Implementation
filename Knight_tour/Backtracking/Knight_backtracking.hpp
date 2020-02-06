
#include <iostream> 
#include <vector> 
#include <map>
#include <queue>
#include <algorithm>

#define num_moves 8

struct KnightBacktracking { 

	KnightBacktracking() = default; 
	KnightBacktracking( int _x, int _y) : x{_x}, y{_y}
	{
		std::cout <<"Constructor in Action"<< std::endl;
	}

	bool knight_backtrack(std::vector<std::vector<int>> &, KnightBacktracking &, 
			KnightBacktracking &, int, int);
	bool valid_coordinate(std::vector<std::vector<int>> &, KnightBacktracking &, int); 
	void print_path(std::vector<KnightBacktracking> &);
	void knight_moves(KnightBacktracking &, KnightBacktracking &, int);

	std::vector< int > row    {-2, -1, 1, 2, 2, 1, -1, -2 };
        std::vector< int > column { 1, 2, 2, 1, -1, -2, -2, -1 };
	int x, y;

	~KnightBacktracking() {}
};
