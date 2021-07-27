#pragma once
#include <string>
#include <iostream>

using namespace std;

#ifndef HASH_TABLE // include guards
#define HASH_TABLE

class Student { // student class
private:
public:
	string name; // name of student
	int mNumber; // M-number of student
	Student* next; // Pointer to next student(for chained hash table implementation)
	Student() {
		name = "x";
		mNumber = 0;
		next == nullptr; // initialized to nullptr
	};
	Student(string val, int id) {
		name = val;
		mNumber = id;
		next = nullptr; // initialized to nullptr
	};
};

class HashTable {
private:
	int key; // stores the hash key
	int tableSize; // stores the table size
	Student* data; // pointer to an array of student objects
	int count; // stores the number of students in hash table
	int Hash(int* item) { // hash function
		return (*item) % tableSize;
	}
public:
	int numCollisions; // collisons in add
	int numChecks; // number of checks for getitem
	HashTable() { // constructor
		key = 0;
		tableSize = 250;
		count = 0;
		numCollisions = 0;
		numChecks = 0;
		data = new Student[250]; // sets array size for hash table change for testing each size
	};
	HashTable(int* size) { // overloaded constructor
		key = 0;
		count = 0;
		numCollisions = 0;
		numChecks = 0;
		int newSize = *size; // dereferences pointer parameter
		tableSize = newSize;
		data = new Student[newSize]; // sets array size for hash table to newSize
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
	~HashTable() { //Destructor
		delete[] data; // deletes array pointed to by data
	};
	void AddItem(int* number, string* input) { // add a student to hashtable
		if (IsFull() == true) {
			cout << "The hash table is full.  No student can be added" << endl;
		}
		else {
			key = Hash(number);
			string val = *input;
			int idNumber = *number;
			Student* itemPointer = new Student(val, idNumber); // creates a new student object
			while (data[key].mNumber != 0) { // iterates until open spot is found
				key = (key + 1) % tableSize; // iterates key till no collisions
				cout << "COLLISION!" << endl;
				numCollisions = numCollisions + 1; // increments number of collisions when adding students
			}
			data[key] = *itemPointer; // sets the student object in the array at the proper index
			count = count + 1; // increments count
		}
	};
	Student* RemoveItem(int* input) { // removing a student from the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  No student can be removed" << endl;
			return nullptr;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // iterates through the entire table
				if (data[i].mNumber != 0) {
					if ((data[i].mNumber) == (*input)) { // if the value at the index is item to be removed
						Student* retVal = new Student(data[i].name, data[i].mNumber); // creates new student object
						count = count - 1; // decrements count
						data[i].mNumber = 0; // removes student from the table
						data[i].name = "x";
						return retVal;
					}
				}
			}
			cout << "Student not found in the hash table" << endl;
			return nullptr;
		}
	};
	Student* GetItem(int* input) { // function for getting a student from the table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  The student is not in the table" << endl;
			return nullptr;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // iterates through the table
				if (data[i].mNumber != 0) {
					if ((data[i].mNumber) == (*input)) { // if the value at the index is the item being searched for
						Student* retVal = &data[i];
						return retVal; // returns found student
					}
				}
				numChecks = numChecks + 1; // increments number of checks when searching for student
			}
			cout << "Student not found in the hash table" << endl;
			return nullptr;
		}
	};
	int* GetLength() { // returns length of the table
		int* countPointer;
		countPointer = &count;
		return countPointer;
	};
	void PrintTable() { // function for printing the table
		if (IsEmpty() == true) {
			cout << "The hash table is empty" << endl;
		}
		else {
			cout << "Hash Table:" << endl;
			for (int i = 0; i < tableSize; i++) { // iterates through the table
				if (data[i].mNumber == 0) {
					cout << "NULL" << endl;
				}
				else {
					cout << endl << "Name: " << data[i].name << endl;
					cout << "MNumber: " << data[i].mNumber << endl << endl;
				}
			}
		}
	};
};

class ChainedHashTable :public HashTable { // derived class ChainedHashTable from HashTable
private:
	int key; // stores the hash key
	int tableSize; // stores the array size
	Student* data; // pointer to the array
	int count; // number of items in the table
	int Hash(int* item) { // hash function
		return (*item) % tableSize;
	}
public:
	int numCollisions; // number of collisions when adding item
	int numChecks; // number of checks to find item
	ChainedHashTable() { // constructor
		key = 0;
		tableSize = 250; // size of table
		count = 0;
		numCollisions = 0;
		numChecks = 0;
		data = new Student[250]; // creates pointer to an array of students, change the size for testing each size of table
	};
	ChainedHashTable(int* size) { // overloaded constructor
		key = 0;
		count = 0;
		int newSize = *size; // dereferences pointer parameter
		tableSize = newSize;
		numCollisions = 0;
		numChecks = 0;
		data = new Student[newSize]; // creates a new pointer to an array of students of newSize
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
	~ChainedHashTable() { // destructor
		delete[] data; // deletes the array pointed to by data
	};
	void AddItem(int* number, string* input) { // add an item into the table
		if (IsFull() == true) {
			cout << "The chained hash table is full.  No student can be added" << endl;
		}
		else {
			key = Hash(number); // generates the hash key
			string val = *input;
			int idNumber = *number;
			Student* itemPointer = new Student(val, idNumber); // creates the new student object
			if (data[key].mNumber != 0) { // Collision
				Student* temp = &data[key];
				while (temp->next != nullptr) { // iterates through until the end of the linked list is found
					temp = temp->next;
					numCollisions = numCollisions + 1; // tracks number of collisions until item is added into the table
				}
				temp->next = itemPointer; // adds collided student to end of the linked list at that index
			}
			else {
				data[key] = *itemPointer;
			}
			count = count + 1; // increments count
		}
	};
	Student* GetItem(int* input) { // function for getting student from the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  The student is not in the chianed hash table" << endl;
			return nullptr;
		}
		else {
			key = Hash(input); // generates the hash key of the student being looked for
			Student* temp = &data[key]; // starts at the first student in index's linked list
			if (temp->next == nullptr) {
				if (temp->mNumber == *input) { // checks if the first student in the index is the one to be found
					numChecks = numChecks + 1; // increments number of checks for the item
					return temp;
				}
				else {
					cout << "Student not found in the chained hash table" << endl;
				}
			}
			else {
				while (temp->next != nullptr) { // iterates through until the temp points at the last student
					if (temp->mNumber == *input) {
						numChecks = numChecks + 1; // icrements number of checks for the item
						return temp; // returns item if found
					}
					else {
						temp = temp->next;
						numChecks = numChecks + 1; // increments number of checks for the item
					}
				}
				if (temp->mNumber == *input) {
					return temp;
				}
				else {
					cout << "Student not found in the chained hash table" << endl;
					return nullptr;
				}
			}
		}
	};
	Student* RemoveItem(int* input) { // function for removing an item from the list
		if (IsEmpty() == true) {
			cout << "The chained hash table is empty.  No student can be removed" << endl;
			return nullptr;
		}
		else {
			if (GetItem(input) != nullptr) { // Found item in the list
				key = Hash(input); // generates the hash key for the item to be removed
				if (data[key].next == nullptr) { // checks if the student to be removed is only one in the index
					Student* retVal = new Student(data[key].name, data[key].mNumber); // creates new student object to be removed and returned
					count = count - 1; // decrements count
					data[key].mNumber = 0; // removes student
					data[key].name = "x"; // from the table
					return retVal;
				}
				else {
					Student* temp = &data[key];
					Student* temp2 = temp->next;
					if (data[key].mNumber == *input) { // First student in index's list is one to be removed
						Student* retVal = new Student(data[key].name, data[key].mNumber); // creates new student object to be removed and returned
						count = count - 1; // decrements count
						data[key] = *temp2; // sets new first student to be the previous second student in the linked list
						delete temp; // prevent memory leaks
						return retVal;
					}
					else {
						while (temp2->mNumber != *input && temp2->next != nullptr) { // will iterate through table until the end
							temp = temp2;
							temp2 = temp2->next;
						}
						Student* retVal = new Student(temp2->name, temp2->mNumber); // creates new student object to be removed and returned when found
						count = count - 1;
						temp->next = temp2->next;
						delete temp2;
						return retVal;
					}
				}
			}
			else {
				cout << "Student not found in the chained hash table" << endl;
				return nullptr;
			}
		}
	};
	void PrintTable() { // function for printing the hash table
		if (IsEmpty() == true) {
			cout << "The chained hash table is empty" << endl;
		}
		else {
			cout << "Hash Table:" << endl;
			for (int i = 0; i < tableSize; i++) { // iterates through the entire hash table
				if (data[i].mNumber == 0) { // checks if index is empty
					cout << "NULL" << endl << endl;
				}
				else {
					if (data[i].next == nullptr) { // if student at index i is only student at that index
						cout << "Name: " << data[i].name << endl;
						cout << "MNumber: " << data[i].mNumber << endl << endl;
					}
					else { // linked list is present at the index
						Student* temp = &data[i];
						cout << "Chain at this index:" << endl;
						while (temp->next != nullptr) { // iterates through the entire linked list
							cout << "Name: " << temp->name << endl;
							cout << "MNumber: " << temp->mNumber << endl;
							temp = temp->next;
						}
						cout << "Name: " << temp->name << endl;
						cout << "MNumber: " << temp->mNumber << endl << endl;
					}
				}
			}
		}
	};
};

#endif
