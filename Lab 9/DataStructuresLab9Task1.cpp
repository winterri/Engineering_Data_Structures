#include <iostream>
#include "HashTableTask1.h"

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
	string sizeOption; // Size option input as a string from user
	int sizeOpt; // Holds the size option that the user chooses
	int size; // Array size to be set
	string sizeInput; // Size input as a string from user
	cout << "What size would you like the table to be?" << endl;
	cout << "1: Default Size (100)" << endl;
	cout << "2: Insert Own Size" << endl;
	getline(cin >> ws, sizeOption);
	if (isNum(sizeOption)) { // if sizeOption is a number than it is converted to in
		sizeOpt = stoi(sizeOption);
	}
	else { // strChoice is not a number
		while (isNum(sizeOption) == false) { // loops till number is input
			cout << "Enter a valid choice 1 or 2: ";
			getline(cin >> ws, sizeOption); // gets user input					
		}
		sizeOpt = stoi(sizeOption); // converts sizeOption to integer
	}
	if (sizeOpt == 1) {
		size = 100; // Default size
		return size;
	}
	else if (sizeOpt == 2) {
		cout << "What size would you like the hash table to be: ";
		getline(cin >> ws, sizeInput);
		if (isNum(sizeInput)) {
			size = stoi(sizeInput); // Converts user input for size into an integer
		}
		else {
			while (isNum(sizeOption) == false) { // Checks if the input is not a number
				cout << "Please enter a number for the size: ";
				getline(cin >> ws, sizeOption);
			}
			size = stoi(sizeOption); // Converts user input for size into an integer
		}
		return size;
	}
}

int main() {
		int testTableSize = getTableSize(); // Gets the size for the array for the hash table
		int* testTableSizePtr = &testTableSize;
		HashTable hashTable1(testTableSizePtr); // Declares hash table of proper size
		bool exit = false; // if true exits the program
		string strChoice; // which function to test
		int choice;
		string* ptrInput;
		string* retPointer;
		string retVal; // retVal for RemoveItem and GetItem
		string input; // input for AddItem
		while (!exit) {
			cout << "Hash Table Functions:" << endl << "1.AddItem" << endl << "2.RemoveItem" << endl << "3.GetItem";
			cout << endl << "4.GetLength" << endl << "5.PrintTable" << endl << "6.Exit" << endl << "Enter choice: ";
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
				cout << "Value to insert into hash table: ";
				getline(cin >> ws, input);
				cout << endl;
				ptrInput = &input;
				hashTable1.AddItem(ptrInput); // adds an item to the hash table
				cout << "Printing hash table to check if value was added" << endl;
				hashTable1.PrintTable(); // prints the hash table
				break;
			case 2: // case to test remove from the hash table
				cout << "Value to remove from hash table: ";
				getline(cin >> ws, input);
				cout << endl;
				ptrInput = &input;
				retPointer = hashTable1.RemoveItem(ptrInput); // Removes items from the hash table
				if (retPointer != nullptr) {
					retVal = *retPointer; // Stores value for output
					cout << "Value removed from the hash table: ";
					cout << retVal << endl << endl;
					cout << "Printing hash table to check if the value was removed" << endl;
					hashTable1.PrintTable();
					delete retPointer; // Clears memory leaks
				}
				break;
			case 3: // case to test the getItem functionality of the hash table
				cout << "Value to find in the hash table: ";
				getline(cin >> ws, input);
				cout << endl;
				ptrInput = &input;
				retPointer = hashTable1.GetItem(ptrInput); // Gets the item from the hash table
				if (retPointer != nullptr) {
					retVal = *retPointer; // Stores value for output
					cout << "Value found in the hash table: ";
					cout << retVal << endl << endl;
					cout << "Printing hash table to check that value is still in table" << endl;
					hashTable1.PrintTable();
				}
				break;
			case 4:
				if (*hashTable1.GetLength() == 0) {

				}
				else if (*hashTable1.GetLength() == 1) {
					cout << "There is 1 item in the hash table" << endl;
				}
				else if (*hashTable1.GetLength() > 1) {
					cout << "There are " << *hashTable1.GetLength() << " items in the hash table" << endl;
				}
				break;
			case 5:
				cout << "Printing Table" << endl << endl;
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