#include <iostream>
#include <chrono>
#include "Lab6DataStructures.h"


using namespace std;

int main() {
	/*
	This is for task 3 testing the time find takes for lab 5 and lab 6
	header files.
	*/
	Tree tree; // creates tree class
	int val; // value to be insert
	int data[50]; // array to hold values to find	

	for (int i = 0; i < 50000; i++) { // for loop to add random values
		val = rand() % 10000000 + 1; // random integer 1-1000
		if (i < 25) {
			data[i] = val; // adds val to array so can find values in the tree
		}
		tree.Insert(val); // insterting the value
	}
	
	// adds values not in the tree
	for (int k = 25; k < 50; k++) {
		data[k] = 0;
	}

	auto t1 = chrono::high_resolution_clock::now(); // time Find starts
	for (int j = 0; j < 50; j++) { // trying to find the 50 values
		try {
			cout << tree.Find(data[j]) << endl; // trying to find data[i] -1 is if not found
		}
		catch (string std) { // catch exception if no values

		}
	}
	auto t2 = chrono::high_resolution_clock::now(); // time the Find ends
	auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // total time find ran in microseconds
	tree.PrintTree(); // printing the tree
	cout << "Duration: " << duration << " microseconds" << endl;
	return 0;
	}
