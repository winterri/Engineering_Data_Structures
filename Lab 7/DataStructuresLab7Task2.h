#include <iostream>
#include <string>

using namespace std;

#ifndef MAX_HEAP
#define MAX_HEAP // Include guards

class MaxHeap {
private:
	int data[25000]; // Array to hold data in heap
	int next; // Variable that holds the index where the next item to the heap would be inserted
public:
	MaxHeap() { // Constructor
		for (int i = 0; i < 25000; i++) {
			data[i] = NULL; // Initializes every value in the heap array to be null
		}
		next = 1; // Initializes next variable to 1
	};
	bool IsEmpty() { // Function for determining if the heap is empty
		if (next <= 1) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsFull() { // Function for determining if the heap is full
		if (next >= 25000) {
			return true;
		}
		else {
			return false;
		}
	};
	int ParentOf(int index) {
		if (index == 1) {
			return 1;
		}
		else {
			return floor(index / 2); // Returns the index of the parent of the index passed in
		}
	};
	int LChild(int index) {
		if (index == 1) {
			return 2;
		}
		else {
			return index * 2; // Returns the index of the left child of the index passed in
		}
	};
	int RChild(int index) {
		if (index == 1) {
			return 3;
		}
		else {
			return (index * 2) + 1; // Returns the index of the right child of the index passed in
		}
	};
	void Insert(int val) { // Function for inserting an item into the heap
		if (IsFull() == true) { // Checks if the heap is full
			cout << "The heap is full.  Nothing can be added" << endl;
		}
		else {
			int newItem = next;
			data[next] = val;
			int parent;
			if (next == 1) {
				parent = 1;
			}
			else {
				parent = newItem / 2; // Finds the parent index of newItem
			}
			while (data[parent] < data[newItem]) { // Will continue until parent is larger than child (max heap)
				swap(data[parent], data[newItem]); // Swaps the two items in the heap array
				newItem = ParentOf(newItem); // Sets newItem to its new location
				parent = ParentOf(newItem); // Finds the parent location of newItem's new location
			}
			next = next + 1; // Increments next
		}
	};
	int Remove() { // Function for removing the top item from a heap
		if (IsEmpty() == true) { // Checks if the heap is empty
			throw string("The heap is empty.  Nothing can be removed"); // Throws error if no integer can be returned from the function
		}
		else {
			int retVal;
			retVal = data[1];
			int flipIndex = 1;
			data[flipIndex] = data[next - 1]; // Sets the data at the top to be equal to the left most, bottom most item in the heap
			data[next - 1] = NULL; // Removes left most, bottom most item in the heap
			while (data[flipIndex] < data[LChild(flipIndex)] || data[flipIndex] < data[RChild(flipIndex)]) { // Operates as long as one of the children of the item has a greater value
				if (data[RChild(flipIndex)] > data[LChild(flipIndex)]) { // Checks if swap with right child is needed
					swap(data[flipIndex], data[RChild(flipIndex)]); // Swaps parent and its right child
					flipIndex = RChild(flipIndex); // Resets flipIndex to its new location
				}
				else { // Operates if swap with left child is needed
					swap(data[flipIndex], data[LChild(flipIndex)]); // Swaps parent and its left child
					flipIndex = LChild(flipIndex); // Resets flipIndex to its new location
				}
			}
			next = next - 1; // Decrements next
			return retVal; // Returns retVal from the function
		}
	};
	void PrintHeap() { // Function for printing all of the items in the heap in order of priority
		if (IsEmpty() == true) {
			cout << "The heap is empty.  Nothing can be printed" << endl;
		}
		else {
			for (int i = 0; i < 50; i++) { // Iterates through the entire heap array
				if (data[i] != NULL) {
					if (data[LChild(i)] != NULL && data[RChild(i)] != NULL) { // prints when both children are there
						cout << data[i] << "(" << data[LChild(i)] << "," << data[RChild(i)] << ")" << endl;
					}
					else if (data[LChild(i)] == NULL && data[RChild(i)] != NULL) { // prints null for left child being null
						cout << data[i] << "(NULL," << data[RChild(i)] << ")" << endl;
					}
					else if (data[LChild(i)] != NULL && data[RChild(i)] == NULL) { // prints null for right child being null
						cout << data[i] << "(" << data[LChild(i)] << ",NULL)" << endl;
					}
					else if (data[LChild(i)] == NULL && data[RChild(i)] == NULL) { // prints null for both children being null
						cout << data[i] << "(NULL,NULL)" << endl;
					}
				}
			}
			cout << endl;
		}
	};
};

#endif
