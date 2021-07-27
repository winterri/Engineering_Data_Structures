#include <iostream>
#include <chrono>
#include "Lab6DataStructures.h"


using namespace std;

int main() {
	/* 
	change i < 50 to test 500, 5000, 50000 random numbers
	change rand() % 1000 + 1; to rand() % 10000000 + 1 to test
	1 to 10000000 random numbers for first part of task three
	*/
	Tree tree; // creates tree class
	int val; // value to be insert
	auto t1 = chrono::high_resolution_clock::now(); // time inserting starts
	
	for (int i = 0; i < 50; i++) { // for loop to add random values
		val = rand() % 1000 + 1; // random integer 1-1000
		tree.Insert(val); // insterting the value
	}
	auto t2 = chrono::high_resolution_clock::now(); // time the inserting ends
	auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // total time insert ran in microseconds
	tree.PrintTree(); // printing the tree
	cout << "Duration: " << duration << " microseconds" << endl;
	return 0;
}