#include <iostream>
#include "DataStructuresLab3.h"

using namespace std;

int main() {
	Stack stack; // stack class
	Queue queue; // queue class
	int choice = 0; // which function to test
	int type = 0; // queue or stack
	char add; // add value
	bool exit = false; // exit main

	cout << "1. Stack" << endl << "2. Queue" << endl << "Enter type: ";
	cin >> type;
	cout << endl;

	switch (type) {
	case 1: // stack testing 
		while (!exit) {
			cout << "1. Add item to stack" << endl << "2. Remove item from stack" << endl << "3. Exit" << endl;
			cout << "Enter choice: ";
			cin >> choice;
			cout << endl;
			switch (choice) {
			case 1: // case to test Push function
				cout << "Enter character to be added: ";
				cin >> add;
				stack.Push(add); // calls the push function
				cout << endl;
				break;
			case 2: // case to test the Pop function
				try { // try catch to handle the exception thrown if stack empty
					cout << "Item removed: " << stack.Pop() << endl << endl;
				}
				catch (string std) {
					cout << endl;
				}
				break;
			case 3: // case to exit testing
				exit = true;
				break;
			default: // if invalid choice is made
				cout << "Invalid choice" << endl << "Enter another choice: ";
				cin >> choice;
				cout << endl;
				break;
			}
		}
	case 2: // queue testing 
		while (!exit) {
			cout << "1. Add item to queue" << endl << "2. Remove item from queue" << endl << "3. Exit" << endl;
			cout << "Enter choice: ";
			cin >> choice;
			cout << endl;
			switch (choice) {
			case 1: // testing Enqueue
				cout << "Enter character to be added: ";
				cin >> add; // value to be added to queue
				queue.Enqueue(add); // calls enqueue function
				cout << endl;
				break;
			case 2: // case to test Dequeue
				try { // try catch to handle exception if queue is empty
					cout << "Item removed: " << queue.Dequeue() << endl << endl;
				}
				catch (string std) {
					cout << endl;
				}
				break;
			case 3: // case to exit testing
				exit = true;
				break;
			default: // if invalid choice made
				cout << "Invalid choice" << endl << "Enter another choice: ";
				cin >> choice;
				cout << endl;
				break;
			}
		}
	}
	return 0;
}
