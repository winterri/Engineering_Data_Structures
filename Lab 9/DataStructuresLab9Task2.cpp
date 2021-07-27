#include <iostream>
#include "HashTableTask2.h"

using namespace std;

bool isNum(string val) { // checks if input is a number
	for (int i = 0; i < val.length(); i++) { // loops through the string to check if number
		if (isdigit(val[i]) == false) {
			return false;
		}
	}
	return true;
}

int getTableSize() {
	string sizeOption; // size option input string from user
	int sizeOpt; // holds size option choosen
	int size; // array size to be set
	string sizeInput; // size input as string from user
	cout << "What size would you like the table to be?" << endl;
	cout << "1: Default Size (32)" << endl;
	cout << "2: Insert Own Size" << endl;
	getline(cin >> ws, sizeOption);
	if (isNum(sizeOption)) { // if strChoice is a number than it is converted to in
		sizeOpt = stoi(sizeOption);
	}
	else { // strChoice is not a number
		while (isNum(sizeOption) == false) { // loops till number is input
			cout << "Enter a valid choice 1 or 2: ";
			getline(cin >> ws, sizeOption); // gets user input					
		}
		sizeOpt = stoi(sizeOption); // converts strChoice to integer
	}
	if (sizeOpt == 1) {
		size = 100; // Default size
		return size;
	}
	else if (sizeOpt == 2) {
		cout << "What size would you like the hash table to be: ";
		getline(cin >> ws, sizeInput);
		if (isNum(sizeInput)) {
			size = stoi(sizeInput); // converts user input for size into an integer
		}
		else { 
			while (isNum(sizeOption) == false) { // checks if input not a number
				cout << "Please enter a number for the size: ";
				getline(cin >> ws, sizeOption);
			}
			size = stoi(sizeOption); // converts user input size into an integer
		}
		return size;
	}
}

int main() {
	int testTableSize = getTableSize(); // calls function to determine size of table
	int* testTableSizePtr = &testTableSize; // transfers table size to a pointer
	HashTable hashTable1(testTableSizePtr); // makes class instance of whatever size is choosen
	bool exit = false; // if true exits the program
	string strChoice; // which function to test
	int choice, mNum;
	string* ptrInput;
	int* ptrNumber;
	Student* retPointer;
	string retVal; // retVal for RemoveItem and GetItem
	string input1, input2; // inputs for insert
	while (!exit) {
		cout << "Hash Table Functions:" << endl << "1.Add Student" << endl << "2.Remove Student" << endl << "3.Get Student";
		cout << endl << "4.Get Class Size" << endl << "5.Print Class List" << endl << "6.Exit" << endl << "Enter choice: ";
		getline(cin >> ws, strChoice); // allows spaces
		if (isNum(strChoice)) { // if strChoice is a number than it is converted to in
			choice = stoi(strChoice);
		}
		else { // strChoice is not a number
			while (isNum(strChoice) == false) { // loops till number is input
				cout << "Enter a valid choice 1-6: ";
				getline(cin >> ws, strChoice); // gets user input					
			}
			choice = stoi(strChoice); // converts strChoice to integer
		}
		switch (choice) {
		case 1: // case to test insert into hash table
			cout << "Student Name: ";
			getline(cin >> ws, input1);
			cout << endl;
			ptrInput = &input1; // pointer to the name input
			cout << "Student MNumber: M";
			getline(cin >> ws, input2);
			if (isNum(input2)) { // if input2 is a number than it is converted to in
				mNum = stoi(input2);
			}
			else { // strChoice is not a number
				while (isNum(input2) == false) { // loops till number is input
					cout << "Enter a valid 8-digit M-number: M";
					getline(cin >> ws, input2); // gets user input					
				}
				mNum = stoi(input2); // converts strChoice to integer
			}
			ptrNumber = &mNum; // pointer to the M-number
			hashTable1.AddItem(ptrNumber, ptrInput); // adds a student to the hash table
			cout << "Printing hash table to check if value was added" << endl;
			hashTable1.PrintTable(); // prints the hash table
			break;
		case 2: // case to test remove from the hash table
			cout << "MNumber of student to remove from hash table: M";
			getline(cin >> ws, input1);
			if (isNum(input1)) { // if input2 is a number than it is converted to in
				mNum = stoi(input1);
			}
			else { // strChoice is not a number
				while (isNum(input1) == false) { // loops till number is input
					cout << "Enter a valid 8-digit M-number: M";
					getline(cin >> ws, input1); // gets user input					
				}
				mNum = stoi(input1); // converts strChoice to integer
			}
			cout << endl;
			ptrNumber = &mNum; // pointer to the M-number
			retPointer = hashTable1.RemoveItem(ptrNumber); // calling the remove function
			if (retPointer != nullptr) {
				cout << "Value removed from the table: " << endl;
				cout << "Name: " << retPointer->name << endl;
				cout << "M-Number: " << retPointer->mNumber << endl << endl;
				cout << "Printing hash table to check if the value was removed" << endl;
				hashTable1.PrintTable();
				delete retPointer;
			}
			break;
		case 3: // case to test the getItem functionality of the hash table
			cout << "MNumber of student to find in the hash table: ";
			getline(cin >> ws, input1);
			if (isNum(input1)) { // if input1 is a number than it is converted to in
				mNum = stoi(input1);
			}
			else { // input1 is not a number
				while (isNum(input1) == false) { // loops till number is input
					cout << "Enter a valid 8-digit M-number: M";
					getline(cin >> ws, input1); // gets user input					
				}
				mNum = stoi(input1); // converts strChoice to integer
			}
			cout << endl;
			ptrNumber = &mNum;
			retPointer = hashTable1.GetItem(ptrNumber);
			if (retPointer != nullptr) {
				cout << "Value found in the table: " << endl;
				cout << "Name: " << retPointer->name << endl;
				cout << "M-Number: " << retPointer->mNumber << endl << endl;
				cout << "Printing hash table to check that student is still in table" << endl;
				hashTable1.PrintTable();
			}
			break;
		case 4: // test get length of table
			if (*hashTable1.GetLength() == 0) { // if no students
				cout << "There are no students in the hash table" << endl;
			}
			else if (*hashTable1.GetLength() == 1) { // if one student
				cout << "There is 1 student in the hash table" << endl;
			}
			else if (*hashTable1.GetLength() > 1) { // if there is more than one student
				cout << "There are " << *hashTable1.GetLength() << " students in the hash table" << endl;
			}
			break;
		case 5: // case to print out the table
			cout << "Printing Class List" << endl << endl;
			hashTable1.PrintTable();
			break;
		case 6: // case to exit main
			exit = true;
			break;
		default: // if the input is invalid
			cout << "Invalid input. Choose again" << endl << endl;
			break;
		}
	}
	return 0;
}
