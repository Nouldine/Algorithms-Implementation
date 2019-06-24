
#include "knight_bfs_2.hpp"

/* This function is used to verify bounderies
 * of the user input in case if the user
 * enters a wrong coordinate. The function would
 * invalidate the process. 
 * @param1: theX coordinate that is representing the row 
 * @param2: theY coordinate that is representing the column 
 * @param3: theSize that is representing the size
 */
bool NodeKnight::valid_coordinate( int theX , int theY, int theSize ) {

	//td::cout <<"Calling NodeKnight::valid_coordinate(int theX, int theY, int theSize)" << std::endl;
	int minSize = 3; 
	int maxSize = 300;
	// check coordinate validity 
	if(theX >= 1 && theX <= theSize && theY >= 1 && theY <= theSize && theSize >= minSize && theSize <= maxSize)
	{
	      return true;
	}
	else
	{
		return false;
	}
}

/* This function is used to print the coordinate from  the source
 * to the destination using a vector of pair
 * @param: path that is a vector of pair to store the trajectory coordinate
 */
void NodeKnight::print_path(std::shared_ptr<std::vector<std::pair<int, int>>> path) { 

	  std::cout <<"Calling Nodeknight::print_path(std::vector<std::pair<int, int>> path)" << std::endl;
	  std::cout <<"\n"; 
	  std::cout <<"path: "; 
	  for( auto pair : *path )
		  std::cout <<"(" << pair.first <<","<< pair.second <<")";
	  std::cout << std::endl;

	  std::cout << "\n";
}

/* This function to find the path the from the source
 * the source to the destination using the breadth first search 
 * approach 
 * @param1: start is the location of the knight with x and y coordinates
 * @param2: destination is the location of the gold
 * @param3: theSize is used to maintain the boundaries
 */
int NodeKnight::bfs_procedure(NodeKnight start, NodeKnight destination, int theSize) {

	std::cout <<"Calling NodeKnight::bfs_procedure(NodeKnight start, NodeKnight destination destination, int theSize)" << std::endl;
	//std::shared_ptr<std::vector<std::pair<int, int>>> route = std::make_shared<std::vector<std::pair<int, int>>>();
	
	std::shared_ptr<std::vector<std::pair<int,int>>> route(new std::vector<std::pair<int, int>>); 

        std::cout <<"Start: "<<"(" << start.x_coordinate <<","<< start.y_coordinate <<")"<< std::endl;	
	std::cout <<"Destination: "<<"(" << destination.x_coordinate <<","<< destination.y_coordinate <<")" << std::endl;
	// stored the source node since it is the first visited
	route->push_back({start.x_coordinate, start.y_coordinate});
	
	// Create a NodeKnight object
	NodeKnight src = {start.x_coordinate, start.y_coordinate, start.distance, route};
	bool visited_node[theSize + 1][theSize + 1]; 

	// since we are using BFS approach
	// we are going to use Queue data structure
	std::queue<NodeKnight> myQueue;

	// Push the first source
	// node in the queue
	myQueue.push(src);

	// As long as the queue is not empty keep
	// looping until the last node in the queue
	while(!myQueue.empty())
	{
		// get the front element in the queue
		std::cout <<"Inside While loop"<< std::endl;
		auto myNode = myQueue.front();
		auto row_i = myNode.x_coordinate; 
		auto column_j = myNode.y_coordinate;
		int dist = myNode.distance;
		/*	
		for( auto content : * (myQueue.front().path_node) )
			std::cout <<"Node Path: "<<"("<< content.first <<","<< content.second <<")" << std::endl;
		*/
		std::cout <<"shared_ptr count: "<< myNode.path_node.use_count() << std::endl;
		route = myNode.path_node;
		myQueue.pop(); // Dequeue the queue

		// if we get to the destination node we are done 
		if( row_i == destination.x_coordinate && column_j == destination.y_coordinate) {
			print_path(route);
			return dist;
		}

		// Make sure to get the right coordinate to effectuate
		// a correct moves to the destination
		for(int i = 0; i < num_move; ++i) {

			int theX = row_i + row[i];
			int theY = column_j + column[i];
			// Check coordinate validity
			if(valid_coordinate(theX, theY, theSize)) {

				// push the correct moves to the route vector
				route->push_back({theX, theY});
				NodeKnight next = {theX, theY, dist + 1, route};
					
				// if there are still unvisited nodes visit them
				if(!visited_node[theX][theY])
				{
					myQueue.push(next);
					visited_node[theX][theY] = true;
				} // end if

				route->pop_back();

			} // end if

		} // end for		
	} // end while 	

} // end function

