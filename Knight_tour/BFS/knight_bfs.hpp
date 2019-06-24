
#ifndef KNIGHT_BFS_H
#define KNIGHT_BFS_H

#include <iostream> 
#include <vector> 
#include <iterator> 
#include <memory> 
#include <queue>
#include <memory>

#define num_move 8

struct NodeKnight
{
	NodeKnight() = default; 
	NodeKnight(int _x, int _y, int dist = 0, std::vector<std::pair<int,int>> path = {{0, 0}}) : 
		x_coordinate{_x}, y_coordinate{_y}, distance{dist}, path_node{path} 
	{
		//std::cout <<"Constructing NodeKnight" << std::endl; 
	}

	std::vector<int> row{-2, -1, 1, 2, 2, 1, -1, -2}; 
	std::vector<int> column{ 1, 2, 2, 1, -1, -2, -2, -1};

	std::vector<std::pair<int, int>> path_node;
	int bfs_procedure(NodeKnight, NodeKnight, int);
	bool valid_coordinate(int, int, int);
	void print_path(std::vector<std::pair<int, int>> );
	int x_coordinate, y_coordinate; 
	int distance;

	bool operator < (const NodeKnight & pair) const
	{
		//std::cout <<"Calling operator < (onst NodeKnight & pair) const" << std::endl;
		return x_coordinate < pair.x_coordinate || (x_coordinate == pair.x_coordinate && y_coordinate == pair.y_coordinate );
	}

	~NodeKnight()
	{
		//std::cout <<"Destructor in Action" << std::endl;
	}

};

#endif
