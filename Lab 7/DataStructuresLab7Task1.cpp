#include <iostream>
#include <string>
#include "DataStructuresLab7Task1.h"
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
	PriorityQueue queue;
	bool exit = false; // if true exits the program
	string strChoice; // which function to test
	int choice, retVal; // retval for remove and choice for which function
	string input, strPriority; // input for insert and strpriority for priority
	int val,priority; // for converting input and strPriority to int
	while (!exit) {
		cout << "Priority Queue Functions:" << endl << "1.Insert" << endl << "2.Remove" << endl << "3.PrintQueue";
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
		case 1: // case to test insert into priority queue
			cout << "Value to insert into queue: ";
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
			cout << endl << "Priority of the value (higher value = higher priority): ";
			getline(cin >> ws, strPriority);
			if (isNum(strPriority)) { // if strPriority is a number than it is converted to int
				priority = stoi(strPriority);
			}
			else { // strPriority is not a number
				while (isNum(strPriority) == false) { // loops till number is input
					cout << "Enter a integer value for priority: ";
					getline(cin >> ws, strPriority); // gets user input					
				}
				priority = stoi(strPriority); // converts strChoice to integer
			}
			cout << endl;
			queue.Insert(val, priority); // calls insert and passes val and the priority
			cout << "Printing queue to check if value added" << endl;
			queue.PrintQueue(); // prints the queue
			break;
		case 2: // case to test remove from the priority queue
			cout << "Removing highest priority item" << endl;
			try { // handles exception
				retVal = queue.Remove();
				cout << "Value removed: " << retVal << endl;
				cout << "Printing queue to check if removed" << endl;
				queue.PrintQueue();
			}
			catch (string msg) { // catches the exception
				cout << msg << endl << endl;
			}
			break;
		case 3: // case to test the print queue function
			queue.PrintQueue();
			break;
		case 4: // case to exit main
			exit = true;
			break;
		default: // if the input is invalid
			cout << "Invalid input. Choose again" << endl << endl;
			break;
		}
	}
	return 0;
}