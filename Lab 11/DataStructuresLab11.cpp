#include <iostream>
#include <chrono>
#include "DataStructuresLab11.h"

using namespace std;

int main() {
	int size = 10; // change value to test different sizes
	int data[10]; // change value in [] to test different sizes
	

	for (int i = 0; i < size; i++) { // iterates throught the array
		data[i] = rand() % (2 * size); // adds random value from 0 to 2*size to data array
	}

	/*
	Change the bubblesort function to the different sorting functions in DataStructursLab11.h
	to test the time of the different sorting algorithms.
	The time for duration_cast can be changed to microseconds for the larger array sizes.
	*/
	auto t1 = chrono::high_resolution_clock::now(); // starts clock to time the sorting
	BubbleSort(data, size); // calls the sorting function
	auto t2 = chrono::high_resolution_clock::now(); // ends clock for timing the sorting
	auto duration = chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count(); // calculates the duration of the sorting algorithm
	cout << "Duration: " << duration << " nanoseconds" << endl; // prints the duration

	return 0;
}