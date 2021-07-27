#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "HashTableTask5.h"

using namespace std;

int main() {
	HashTable hTable; // creating instance of class
	ChainedHashTable chainedHTable; // creating instance of class 
	string name, number; // variables to get the name and mnumber from text file
	int mNumber; // integer for mnumber
	ifstream inFile; // file variable
	inFile.open("StudentsTask5.txt"); // opening the file
	auto t1 = chrono::high_resolution_clock::now(); // time Find starts
	while (!inFile.eof()) { // runs till end of file
		getline(inFile, name); // gets name
		getline(inFile, number); // gets mnumber from file
		mNumber = stoi(number); // converts mnumber to int
		hTable.AddItem(&mNumber, &name); // passes to additem function
	}
	auto t2 = chrono::high_resolution_clock::now(); // time the add ends
	auto duration1 = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // total time find ran in microseconds
	inFile.close(); // closes file
	inFile.open("StudentsTask5.txt"); // opens file
	t1 = chrono::high_resolution_clock::now(); // time the get begings
	while (!inFile.eof()) { // runs till end of file
		getline(inFile, name); // gets name
		getline(inFile, number); // gets mnumber from file
		mNumber = stoi(number); // converts mnumber
		hTable.GetItem(&mNumber); // gets the mnumber from the table
	}
	t2 = chrono::high_resolution_clock::now(); // time GetItem ends
	auto duration2 = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // duration
	inFile.close(); // closes file
	inFile.open("StudentsTask5.txt"); // opens file
	t1 = chrono::high_resolution_clock::now(); // time AddItem starts
	while (!inFile.eof()) { // runs till end of file
		getline(inFile, name); // gets name
		getline(inFile, number); // gets mnumber from file
		mNumber = stoi(number); // converts mnumber
		chainedHTable.AddItem(&mNumber, &name); // passes to addItem function
	}
	t2 = chrono::high_resolution_clock::now(); // time GetItem ends
	auto duration3 = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // duration
	inFile.close(); // closes file
	inFile.open("StudentsTask5.txt"); // opens file
	t1 = chrono::high_resolution_clock::now(); // time GetItem starts
	while (!inFile.eof()) { // runs till end of file
		getline(inFile, name); // gets name
		getline(inFile, number); // gets mnumber from file
		mNumber = stoi(number); // converts mnumber
		chainedHTable.GetItem(&mNumber); // gets mnumber from table
	}
	t2 = chrono::high_resolution_clock::now(); // time GetItem ends
	auto duration4 = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // duration
	inFile.close(); // closes file
	hTable.PrintTable(); // prints table for verification
	cout << "Add Time for Probing Hash Table: " << duration1 << " microseconds" << endl; // duration of adding for probing hash table
	cout << "Get Time for Probing Hash Table: " << duration2 << " microseconds" << endl; // duration of getting for probing hash table
	cout << "Number of Collisions for Probing Hash Table: " << hTable.numCollisions << endl; // number of collisions for probing hash table
	cout << "Number of Checks for Probing Hash Table: " << hTable.numChecks << endl << endl; // number of checks for probing hash table
	cout << "Add Time for Chained Hash Table: " << duration3 << " microseconds" << endl; // duration of adding for chained hash table
	cout << "Get Time for Chained Hash Table: " << duration4 << " microseconds" << endl; // duration of getting for chained hash table
	cout << "Number of Collisions for Chained Hash Table: " << chainedHTable.numCollisions << endl; // number of collisions for chained hash table
	cout << "Number of Checks for Chained Hash Table: " << chainedHTable.numChecks << endl; // number of checks for chained hash table
	return 0;
}