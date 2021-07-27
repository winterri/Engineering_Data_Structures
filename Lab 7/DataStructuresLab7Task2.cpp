#include <iostream>
#include <string>
#include "DataStructuresLab7Task2.h"
using namespace std;

bool isNum(string val) { // checks if input is a number
	for (int i = 0; i < val.length(); i++) { // loops through the string to check if number
		if (isdigit(val[i]) == false) {
			return false;
		}
	}
	return true;
}

int main() {
	MaxHeap heap;
	bool exit = false; // if true exits the program
	string strChoice; // which function to test
	int choice, retVal;
	string input;
	int val;
	while (!exit) {
		cout << "Heap Functions:" << endl << "1.Insert" << endl << "2.Remove" << endl << "3.PrintHeap";
		cout << endl << "4.Exit" << endl << "Enter choice: ";
		getline(cin >> ws, strChoice); // allows spaces
		if (isNum(strChoice)) { // if strChoice is a number than it is converted to in
			choice = stoi(strChoice);
		}
		else { // strChoice is not a number
			while (isNum(strChoice) == false) { // loops till number is input
				cout << "Enter a valid choice 1-4: ";
				getline(cin >> ws, strChoice); // gets user input					
			}
			choice = stoi(strChoice); // converts strChoice to integer
		}
		switch (choice) {
		case 1: // case to insert
			cout << "Value to insert into heap: ";
			getline(cin >> ws, input);
			if (isNum(input)) { // if input is a number than it is converted to int
				val = stoi(input);
			}
			else { // input is not a number
				while (isNum(input) == false) { // loops till number is input
					cout << "Enter a integer value: ";
					getline(cin >> ws, input); // gets user input					
				}
				val = stoi(input); // converts strChoice to integer
			}
			heap.Insert(val); // inserts the value
			cout << "Printing heap to check if value added" << endl;
			heap.PrintHeap();
			break;
		case 2: // case to remove
			cout << "Removing highest priority item" << endl;
			try { // to catch the exception
				retVal = heap.Remove(); // removes max item
				cout << "Value removed: " << retVal << endl;
				cout << "Printing heap to check if removed" << endl;
				heap.PrintHeap(); // print to check
			}
			catch (string msg) { // catches exception
				cout << msg << endl << endl;
			}
			break;
		case 3: // case to print heap
			heap.PrintHeap(); // print heap
			break;
		case 4: // case to exit main
			exit = true;
			break;
		default: // if invalid input
			cout << "Invalid input. Choose again" << endl << endl;
			break;
		}
	}
	return 0;
}