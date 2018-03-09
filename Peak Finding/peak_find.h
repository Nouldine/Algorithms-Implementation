

#ifndef PEAK_H 
#define PEAK_H

#include<iostream> 
#include<string> 
#include<vector>
#include<iterator>


struct Peak {

	

	// function used to get 1D peak	
	int peak_finding( std::vector<int> & , int, int );

	// driver function for 1D for peak_finding function
	int peak( std::vector<int> &, int );

	// function used to find global vec in 2D vector
	int peak_finding_2D( std::vector< std::vector<int> > &, int, int );

	//  driver function for peak_2D
        int peak_2D( std::vector< std::vector<int> > &, int, int );

	~Peak(){}

};

#endif
