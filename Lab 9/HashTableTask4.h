#pragma once
#include <string>
#include <iostream>

using namespace std;

#ifndef HASH_TABLE // Include guards
#define HASH_TABLE

class Student { // Student class
private:
public:
	string name; // Name of student
	int mNumber; // M-Number of student
	Student* next; // Pointer to next student (for chained hash table implementation)
	Student() {
		name = "x";
		mNumber = 0;
		next == nullptr; // Initialized to null pointer
	};
	Student(string val, int id) {
		name = val;
		mNumber = id;
		next = nullptr; // Initialized to null pointer
	};
};

class HashTable {
private:
	int key; // Stores the hash key
	int tableSize; // Stores the table size
	Student* data; // Pointer to an array of student objects
	int count; // Stores the number of students in the hash table
	int Hash(int* item) { // Hash function
		return (*item) % tableSize;
	}
public:
	HashTable() { // Constructor
		key = 0;
		tableSize = 50;
		count = 0;
		data = new Student[50]; // Sets array size for hash table to be 50
	};
	HashTable(int* size) { // Overloaded constructor
		key = 0;
		count = 0;
		int newSize = *size; // Dereferences pointer parameter
		tableSize = newSize;
		data = new Student[newSize]; // Sets array size for hash table to be newSize
	};
	bool IsFull() { // Function for checking if the hash table is full
		if (count == tableSize) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsEmpty() { // Function for checking if the hash table is full
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	~HashTable() { // Destructor
		delete[] data; // Deletes array pointed to by data
	};
	void AddItem(int* number, string* input) { // Function for adding a student to the hash table
		if (IsFull() == true) {
			cout << "The hash table is full.  No student can be added" << endl;
		}
		else {
			key = Hash(number);
			string val = *input;
			int idNumber = *number;
			Student* itemPointer = new Student(val, idNumber); // Creates new student object
			while (data[key].mNumber != 0) { // Iterates through until open spot is found
				key = (key + 1) % tableSize; // iterates the key if there is a collision
				cout << "COLLISION!" << endl;
			}
			data[key] = *itemPointer; // Sets the student object in the array at the proper index
			count = count + 1; // Increments count
		}
	};
	Student* RemoveItem(int* input) { // Function for removing a student from the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  No student can be removed" << endl;
			return nullptr;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // Iterates through the entire table
				if (data[i].mNumber != 0) {
					if ((data[i].mNumber) == (*input)) { // Checks if the value at the index matches the item to be removed
						Student* retVal = new Student(data[i].name, data[i].mNumber); // Creates new student object
						count = count - 1; // Decrements count
						data[i].mNumber = 0; // Removes student
						data[i].name = "x"; // from the hash table
						return retVal;
					}
				}
			}
			cout << "Student not found in the hash table" << endl;
			return nullptr;
		}
	};
	Student* GetItem(int* input) { // Function for getting a student from the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  The student is not in the table" << endl;
			return nullptr;
		}
		else {
			for (int i = 0; i < tableSize; i++) { // Iterates through the entire table
				if (data[i].mNumber != 0) {
					if ((data[i].mNumber) == (*input)) { // Checks if the value at the index matches the item to be found
						Student* retVal = &data[i];
						return retVal; // Returns found student
					}
				}
			}
			cout << "Student not found in the hash table" << endl;
			return nullptr;
		}
	};
	int* GetLength() { // Function for getting the number of students in the hash table
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
			for (int i = 0; i < tableSize; i++) { // iterates through the entire table
				if (data[i].mNumber == 0) {
					cout << "NULL" << endl;
				}
				else {
					cout << endl << "Name: " << data[i].name << endl; // Outputs student name
					cout << "MNumber: " << data[i].mNumber << endl << endl; // Outputs student M-Number
				}
			}
		}
	};
};

class ChainedHashTable :public HashTable { // Derived class "ChainedHashTable" from "HashTable"
private:
	int key; // Stores the hash key
	int tableSize; // Stores the array size
	Student* data; // Pointer to an array
	int count; // Stores the number of items in the hash table
	int Hash(int* item) { // Hash function
		return (*item) % tableSize;
	}
public:
	ChainedHashTable() { // Constructor
		key = 0;
		tableSize = 50;
		count = 0;
		data = new Student[50]; // Creates a new pointer to an array of students of size 50
	};
	ChainedHashTable(int* size) { // Overloaded constructor
		key = 0;
		count = 0;
		int newSize = *size; // Dereferences pointer parameter
		tableSize = newSize;
		data = new Student[newSize]; // Creates a new pointer to an array of students of size newSize
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
	~ChainedHashTable() { // Destructor
		delete[] data; // Deletes the array pointed to by data
	};
	void AddItem(int* number, string* input) { // Function for adding a student to the hash table
		if (IsFull() == true) {
			cout << "The chained hash table is full.  No student can be added" << endl;
		}
		else {
			key = Hash(number); // Generates hash key
			string val = *input;
			int idNumber = *number;
			Student* itemPointer = new Student(val, idNumber); // Creates new student object
			if (data[key].mNumber != 0) { // Collision
				Student* temp = &data[key];
				while (temp->next != nullptr) { // Iterates through until end of linked list is found
					temp = temp->next;
				}
				temp->next = itemPointer; // Adds collided student to end of linked list at its index
			}
			else {
				data[key] = *itemPointer;
			}
			count = count + 1; // Increments count
		}
	};
	Student* GetItem(int* input) { // Function for getting a student from the hash table
		if (IsEmpty() == true) {
			cout << "The hash table is empty.  The student is not in the chianed hash table" << endl;
			return nullptr;
		}
		else {
			key = Hash(input); // Generates the hash key of what we are trying to find
			Student* temp = &data[key]; // Starts at the first student in the index's linked list
			if (temp->next == nullptr) {
				if (temp->mNumber == *input) { // Checks if the first student in the index is the one to be found
					return temp;
				}
				else {
					cout << "Student not found in the chained hash table" << endl;
				}
			}
			else {
				while (temp->next != nullptr) { // Iterates through until temp points at the last student
					if (temp->mNumber == *input) {
						return temp; // Returns temp if student is found
					}
					else {
						temp = temp->next;
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
	Student* RemoveItem(int* input) { // Function for removing a student from the hash table
		if (IsEmpty() == true) {
			cout << "The chained hash table is empty.  No student can be removed" << endl;
			return nullptr;
		}
		else {
			if (GetItem(input) != nullptr) { // Found item in the list
				key = Hash(input); // Generates the hash key of what we are trying to remove
				if (data[key].next == nullptr) { // Checks if student to be removed is only student in index
					Student* retVal = new Student(data[key].name, data[key].mNumber); // Creates new student object to be removed and returned
					count = count - 1; // Decrements count
					data[key].mNumber = 0; // Removes student
					data[key].name = "x"; // from the hash table
					return retVal;
				}
				else {
					Student* temp = &data[key];
					Student* temp2 = temp->next;
					if (data[key].mNumber == *input) { // First student in index's linked list is one to be removed
						Student* retVal = new Student(data[key].name, data[key].mNumber); // Creates new student object to be removed and returned
						count = count - 1; // Decrements count
						data[key] = *temp2; // Sets new first student to be the previous second student in the linked list
						delete temp; // Prevents memory leaks
						return retVal;
					}
					else {
						while (temp2->mNumber != *input && temp2->next != nullptr) { // Will iterate through table until end
							temp = temp2;
							temp2 = temp2->next;
						}
						Student* retVal = new Student(temp2->name, temp2->mNumber); // Creates new student object to be removed and returned when found
						count = count - 1; // Decrements count
						temp->next = temp2->next; // Reconnects the linked list
						delete temp2; // Deletes item to be removed
						return retVal;
					}
				}
			}
			else { // Not found in the hash table
				cout << "Student not found in the chained hash table" << endl;
				return nullptr;
			}
		}
	};
	void PrintTable() { // Function for printing the hash table
		if (IsEmpty() == true) {
			cout << "The chained hash table is empty" << endl;
		}
		else {
			cout << "Hash Table:" << endl;
			for (int i = 0; i < tableSize; i++) { // Iterates through the entire hash table
				if (data[i].mNumber == 0) { // Checks if index is empty
					cout << "NULL" << endl << endl;
				}
				else {
					if (data[i].next == nullptr) { // If student at index i is only student at that index (no linked list)
						cout << "Name: " << data[i].name << endl;
						cout << "MNumber: " << data[i].mNumber << endl << endl;
					}
					else { // Linked list found at index
						Student* temp = &data[i]; 
						cout << "Chain at this index:" << endl;
						while (temp->next != nullptr) { // Iterates through the entire linked list
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
