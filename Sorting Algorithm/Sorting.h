
#ifndef SORTING_H
#define SORTING_H 

#include<iostream> 
#include<string> 
#include<vector> 
#include<iterator>


struct Sorting {
 

	void InsertionSort( std::vector<int> &, int );
	
	void InverseInsertion_sort( std::vector<int> &, int );

	int value; //  the element to be repositioned 
	
	//int index; // the index of the element of the element to be repositioned
	
	void Merge( std::vector<int> &, std::vector<int> &, std::vector<int> &); // function to merge the subArrays 

	void MergeSort( std::vector<int> & ); // function to reconstruct the main container with sorted elements 

	~Sorting(){}

};

#endif
