#include <iostream>
#include <string>
#include <chrono>
#include "DataStructuresLab7Task1.h" // Includes both header files
#include "DataStructuresLab7Task2.h"

using namespace std;

int main() {
	MaxHeap maxHeap; // Initializes max heap
	PriorityQueue pQueue;
	int val, retVal, priority;
	int values[20000];
	auto t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) { // Can change the value in the for loop
		val = rand() % 10000000 + 1;
		for (int i = 0; i < 20000; i++) {
			if (values[i] == val) {
				values[i] = 253472; // Ensures no replication values (random value)
			}
		}
		maxHeap.Insert(val); // Inserts values into the heap
	}
	auto t2 = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Adding Duration for Max Heap: " << duration << endl;
	t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) { // Can change the value in the for loop
		val = rand() % 10000000 + 1;
		priority = rand() % 100 + 1;
		pQueue.Insert(val, priority); // Inserts values into the priority queue
	}
	t2 = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Adding duration for Priority Queue: " << duration << endl;
	t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) { // Can change the value in the for loop
		retVal = maxHeap.Remove(); // Removes values from the heap
	}
	t2 = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count();
	cout << "Removal Time for Max Heap: " << duration << endl;
	t1 = chrono::high_resolution_clock::now();
	for (int i = 0; i < 500; i++) { // Can change the value in the for loop
		retVal = pQueue.Remove(); // Removes values from the priority queue
	}
	t2 = chrono::high_resolution_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // Gets the duration information
	cout << "Removal Time for Priority Queue: " << duration << endl; // Outputs duration
	return 0;
}