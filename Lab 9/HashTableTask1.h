#pragma once
#include <string>
#include <iostream>

using namespace std;

#ifndef HASH_TABLE // Include guards
#define HASH_TABLE

class HashTable {
private:
	int key; // Stores the hash key
	int tableSize; // Stores the maximum size of the hash table
	string* data; // Creates a pointer to an array of strings
	int count; // Stores the number of items in the hash table
	int Hash(string* item) { // Hash function
		int asciiCode = 0; // Initializes sum to be zero
		string val = *item;
		for (int i = 0; i < val.length(); i++) { // Iterates through entire string input
			asciiCode = asciiCode + val.at(i); // Adds Ascii value of individual characters within string to the sum of Ascii values
		}
		asciiCode = asciiCode % tableSize; // Modulus Ascii code by the maximum size of the table
		return asciiCode;
	}
public:
	HashTable() { // Default constructor
		key = 0;
		tableSize = 100; // Sets table size to be 100
		count = 0;
		data = new string[100]; // Creates new array of strings of size 100
		for (int i = 0; i < 100; i++) {
			data[i] = "x"; // Initializes all values in array to be "x"
		}
	};
	HashTable(int* size) { // Overloaded constructor
		key = 0;
		count = 0;
		int newSize = *size; // Dereferences size parameter
		tableSize = newSize;
		data = new string[newSize]; // Creates new array of strings of size newSize
		for (int i = 0; i < newSize; i++) {
			data[i] = "x"; // Initialies all values in array to be "x"
		}

	};
	bool IsFull() { // Function for checking if the hash table is full
		if (count == tableSize) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsEmpty() { // Function for checking if the hash table is empty
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	~HashTable() { // Destructor
		delete[] data; // Deletes the array being pointed at by data
	};
	void AddItem(string* input) { // Function for adding a string to the hash table
		if (IsFull() == true) {
			cout << "The hash table is full.  Nothing can be added" << endl;
		}
		else {
			key = Hash(input); // Keys the input
			string val = *input; // Dereferences pointer parameter for input
			while (data[key] != "x") { // A collision has occured
				key = (key + 1) % tableSize; // Iterates if there is a collision
				cout << "COLLISION!" << endl;
			}
			data[key] = val; // Stores new value in hash table array
			count = count + 1; // Increments count
		}
	};
	string* RemoveItem(string* input) { // Function for removing a string from the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  Nothing can be removed" << endl;
			return nullptr;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // Iterates through the entire list
				if (data[i] != "x") {
					if ((data[i]).compare(*input) == 0) { // Checks if the string at the index matches the value to be removed
						string* retVal = new string(data[i]); // Creates new string of same value to be returned from function
						data[i] = "x"; // Removes data from hash table array
						count = count - 1; // Decrements count
						return retVal;
					}
				}
			}
			cout << "Item not found in the hash table" << endl;
			return nullptr;
		}
	};
	string* GetItem(string* input) { // Function for getting a string from the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  The item is not in the table" << endl;
			return nullptr;
		}
		else {
			string* retVal;
			for (int i = 0; i < tableSize; i++) { // Iterates through the entire list
				if (data[i] != "x") {
					if ((data[i]).compare(*input) == 0) { // Checks if the string at the index matches the value to be found
						retVal = &data[i];
						return retVal; // Returns found string
					}
				}
			}
			cout << "Item not found in the hash table" << endl;
			return nullptr;
		}
	};
	int* GetLength() { // Function for returning the number of items in the hash table
		int* countPointer;
		countPointer = &count;
		return countPointer;
	};
	void PrintTable() { // Function for printing the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty" << endl;
		}
		else {
			cout << "Hash Table:" << endl;
			for (int i = 0; i < tableSize; i++) { // Iterates through the entire list
				if (data[i] == "x") {
					cout << "NULL" << endl;
				}
				else {
					cout << data[i] << endl; // Outputs string data at index
				}
			}
		}
	};
};

#endif
