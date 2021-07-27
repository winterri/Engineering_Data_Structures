#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include "HashTableTask2.h"

using namespace std;

int main() {
	HashTable hTable; // creating instance of class 
	string name, number; // variables to get the name and mnumber from text file
	int mNumber; // integer for mnumber
	ifstream inFile; // file variable
	inFile.open("Students.txt"); // opening the file
	auto t1 = chrono::high_resolution_clock::now(); // time Find starts
	while (!inFile.eof()) { // runs till end of file
		getline(inFile, name); // gets name
		getline(inFile, number); // gets mnumber from file
		mNumber = stoi(number); // converts mnumber to int
		hTable.AddItem(&mNumber, &name); // passes to additem function
	}
	auto t2 = chrono::high_resolution_clock::now(); // time the Find ends
	auto duration = chrono::duration_cast<chrono::microseconds>(t2 - t1).count(); // total time find ran in microseconds
	inFile.close(); // closes file
	hTable.PrintTable();
	cout << "Duration: " << duration << " microseconds" << endl; // duration of adding
	return 0;
}
