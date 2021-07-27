#pragma once
#include <string>
#include <iostream>

using namespace std;

#ifndef HASH_TABLE
#define HASH_TABLE

class Student { // class to hold name and mnumber
private:
public:
	string name; // student name
	int mNumber; // student mnumber
	Student() { // default constructor
		name = "x";
		mNumber = 0;
	};
	Student(string val, int id) { // constructor to add a student
		name = val;
		mNumber = id;
	};
};

class HashTable {
private:
	int key; // index of array
	int tableSize; // size of the array
	Student* data; // pointer to the array
	int count; // number of students in the table
	int Hash(int* item) { // finds the index for the student
		return (*item) % tableSize;
	}
public:
	HashTable() { // default constructor
		key = 0;
		tableSize = 32; // defaults table size to 32
		count = 0;
		data = new Student[32]; // creates table of students
	};
	HashTable(int* size) { // changes size of the array for the table
		key = 0;
		count = 0;
		int newSize = *size;
		tableSize = newSize; // sets table size to value from user
		data = new Student[newSize]; // creates table of students of size from user
	};
	bool IsFull() { // if the table is full
		if (count == tableSize) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsEmpty() { // if the table is empty
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	~HashTable() { // destructor to delete the array
		delete[] data;
	};
	void AddItem(int* number, string* input) { // add item to the table
		if (IsFull() == true) {
			cout << "The hash table is full.  No student can be added" << endl;
		}
		else {
			key = Hash(number); // finds the index for the student
			string val = *input; // string value of pointer input
			int idNumber = *number; // integer value of pointer number
			Student* itemPointer = new Student(val, idNumber); //creates new student
			while (data[key].mNumber != 0) { // deals with collisions
				key = (key + 1) % tableSize; // increases the index till at an empty spot
				cout << "COLLISION!" << endl;
			}
			data[key] = *itemPointer; // adds the student into the array
			count = count + 1;
		}
	};
	Student* RemoveItem(int* input) { // remove an item from the list
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  No student can be removed" << endl;
			return nullptr;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // finds where the value is
				if (data[i].mNumber != 0) { // if data.mnumber exists
					if ((data[i].mNumber) == (*input)) { // if data.mnumber is the value passed into the function
						Student* retVal = new Student(data[i].name, data[i].mNumber); // creates new instance of that data
						count = count - 1;
						data[i].mNumber = 0; // remove from list
						data[i].name = "x";
						return retVal;
					}
				}
			}
			cout << "Student not found in the hash table" << endl;
			return nullptr;
		}
	};
	Student* GetItem(int* input) { // finds item and returns it
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  The student is not in the table" << endl;
			return nullptr;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // iterates through data
				if (data[i].mNumber != 0) { // if data exists
					if ((data[i].mNumber) == (*input)) { // if data is the value passed in
						Student* retVal = &data[i]; // points retval at the data
						return retVal;
					}
				}
			}
			cout << "Student not found in the hash table" << endl;
			return nullptr;
		}
	};
	int* GetLength() { // returns pointer to length of the table
		int* countPointer;
		countPointer = &count;
		return countPointer;
	};
	void PrintTable() { // prints the table
		if (IsEmpty() == true) {
			cout << "The hash table is empty" << endl;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // iterates through data array
				if (data[i].mNumber == 0) { // if data doesn't exist
					cout << "NULL" << endl;
				}
				else { // if data exists
					cout << endl << "Name: " << data[i].name << endl;
					cout << "MNumber: " << data[i].mNumber << endl << endl;
				}
			}
		}
	};
};

#endif
