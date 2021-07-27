#include <iostream>
#include "DataStructuresLab4_Task3.h"
using namespace std;

int main() {
	LinkedList list; // linked list class
	Stack stack; // stack class
	Queue queue; // queue class
	Node* retNode; // return node for function calls
	bool exit = false, exitMain = false; // exit functions
	int choice, type, location; // choice for functions, type, and location input
	int* locationPointer; // points to location value
	string input, retVal; // input for putting in list and return from pop functions
	string* stringPointer; // points to input value
	while (!exitMain) {
		exit = false;
		cout << "Type:" << endl << "1. Linked List" << endl << "2. Stack" << endl << "3. Queue" << endl << "Enter Type: ";
		cin >> type;
		cout << endl;
		switch (type) {
		case 1: // linked list testing
			while (exit == false) {
				cout << "Linked List Functions:" << endl << "1.AddItemFront" << endl << "2.AddItemEnd" << endl << "3.GetItem" << endl;
				cout << "4.GetItemFront" << endl << "5.IsInlist" << endl << "6.IsEmpty" << endl << "7.Size" << endl << "8.SeeNext";
				cout  << endl << "9.SeeAt" << endl << "10.Reset" << endl << "11.Print" << endl << "12.Back to types" << endl << "13.Exit" << endl;
				cout << "Input choice: ";
				cin >> choice; // function to test
				cout << endl;
				switch (choice) {
				case 1: // tests adding to front
					cout << "Input string to be added to front: ";
					getline(cin >> ws, input); // able to get spaces
					cout << endl;
					stringPointer = &input; // creates pointer to the string
					list.addItemFront(stringPointer); // calls additemfront
					cout << "List:" << endl;
					list.print();// print the list
					cout << endl;
					break;
				case 2: // test adding to end
					cout << "Input string to be added to end: ";
					getline(cin >> ws, input); // allows spaces
					cout << endl;
					stringPointer = &input; // pointer to string input
					list.addItemEnd(stringPointer); // calls additemend
					cout << "List:" << endl;
					list.print();
					cout << endl;
					break;
				case 3:// get item input
					cout << "Input item to get: ";
					getline(cin >> ws, input); // gets spaces
					cout << endl;
					stringPointer = &input; // pointer to the input
					if (list.IsInList(stringPointer)) { // searches only if it exists in the list
						retNode = list.getItem(stringPointer); // calls getitem function
						if (retNode != nullptr) {
							cout << "Value from the list: " << retNode->data << endl << endl;
						}
					}
					else { // if item isn't in the list
						cout << "Item is not in the list" << endl << endl;
					}
					break;
				case 4: // test getitemfromfront
					cout << "Getting item from front:" << endl;
					retNode = list.getItemFront(); // calls getitemfront function
					if (retNode != nullptr) { // if return exits print it
						cout << "Value in the list: " << retNode->data << endl << endl;
					}
					break;
				case 5: // tests isinlist
					cout << "Input string to find in list: ";
					getline(cin >> ws, input);
					stringPointer = &input; // pointer to string
					cout << endl; 
					if (list.IsInList(stringPointer)) { // if it exits print it
						cout << "String is in list" << endl << endl;
					}
					else { // if not in list
						cout << "String is not in list" << endl << endl;
					}
					break;
				case 6: // tests if list is empty
					if (list.isEmpty()) {
						cout << "List is empty" << endl << endl;
					}
					else {
						cout << "List is not empty" << endl << endl;
					}
					break;
				case 7:// tests the size function
					cout << "size of list: " << list.size() << endl << endl;
					break;
				case 8: // tests seeNext function
					try { // handles exception thrown
						cout << "Calling seeNext function" << endl;
						retNode = list.seeNext(); // calls seeNext
						if (retNode != nullptr) { // prints it if it isn't nullptr
							cout << "Data: " << retNode->data << endl << endl;
						}
						else {
							cout << "Data: No item in the list" << endl << endl;
						}
					}
					catch (string std) { // if list is empty
						cout << endl;
					}

					try { // handles exception thrown
						cout << "Second seeNext call for verification" << endl;
						retNode = list.seeNext(); // calls seeNext
						if (retNode != nullptr) { // prints if it isnt nullptr
							cout << "Data: " << retNode->data << endl << endl;
						}
						else { // if data isn't in the list
							cout << "Data: No item in the list" << endl << endl;
						}
					}
					catch (string std) {
						cout << endl;
					}
					break;
				case 9: // case to test seeAt function
					cout << "Enter location to see: ";
					cin >> location; // location in the list
					locationPointer = &location; // pointer to the location value
					cout << endl;
					try { // handles exception thrown
						cout << "Value at location: " << endl;
						retNode = list.seeAt(locationPointer); // calls seeAt function
						cout << "Data: " << retNode->data << endl << endl; // prints the data
					}
					catch (string std) {
						cout << endl;
					}
					break;
				case 10: // tests the reset function
					cout << "List:" << endl;
					list.print(); 
					cout << endl;
					try { // calls seeNext before reseting
						cout << "Calling seeNext function" << endl;
						retNode = list.seeNext();
						if (retNode != nullptr) {
							cout << "Data: " << retNode->data << endl << endl;
						}
					}
					catch (string std) {
						cout << "Data: No item in the list" << endl << endl;
					}
					cout << "reseting nextNode" << endl;
					list.reset(); // calls reset
					try { // calls seeNext again to show it is reset
						cout << "calling seeNext function for verification" << endl;
						retNode = list.seeNext();
						if (retNode != nullptr) {
							cout << "Data: " << retNode->data << endl << endl;
						}
					}
					catch (string std) {
						cout << "Data: No item in the list" << endl << endl;
					}
					list.reset(); // final reset call
					break;
				case 11: // tests printing the list
					cout << "Printing list" << endl;
					cout << "List: " << endl;
					list.print();
					break;
				case 12: // exits back to type of lists
					exit = true;
					break;
				case 13: // exits the whole program
					exitMain = true;
					exit = true;
					break;
				default: // if invalid input selected
					cout << "Invalid input. Please input another choice";
					cout << endl;
					break;
				}
			}
		case 2: // tests stack class functions
			while (!exit) {
				cout << "Stack Functions:" << endl << "1.Push" << endl << "2.Pop" << endl << "3.Top" << endl << "4.isEmpty";
				cout << endl << "5.MakeEmpty" << endl << "6.Length" << endl << "7.PrintStack" << endl << "8.Back to types" << endl << "9.Exit" << endl;
				cout << "Enter choice: ";
				cin >> choice;
				cout << endl;
				switch (choice) {
				case 1: // test the push function
					cout << "String to be added to stack: ";
					getline(cin >> ws, input); // able to get spaces
					cout << endl;
					stringPointer = &input; // pointer to input
					stack.Push(stringPointer); // adds item to the stack
					stack.PrintStack(); // print to verify
					break;
				case 2: // test the pop function
					try { // handles exception if empty
						retVal = stack.Pop(); // calls pop function
						cout << "Value from start of stack: " << retVal << endl << endl;
					}
					catch (string std) {
						cout << endl;
					}
					break;
				case 3: // test the top function
					try { // handles exception if empty
						cout << "Value at start of stack: " << stack.Top() << endl << endl;
					}
					catch (string std) {
						cout << endl;
					}
					break;
				case 4: // tests isEmpty function
					stack.IsEmpty();
					if (stack.isEmpty()) { // if empty
						cout << "Stack is empty" << endl << endl;
					}
					else { // if not empty
						cout << "Stack is not empty" << endl << endl;
					}
					break;
				case 5: // tests MakeEmpty function
					cout << "Emptying stack" << endl;
					stack.MakeEmpty(); // calls make empty function
					cout << "Checking if empty" << endl;
					cout << "Stack length: " << stack.Length() << endl << endl; // verifies it is empty
					break;
				case 6: // tests length function
					cout << "Stack Length: " << stack.Length() << endl << endl;
					break;
				case 7: // tests print function
					stack.PrintStack();
					cout << endl;
					break;
				case 8: // returns to type selection
					exit = true; // exits stack testing
					stack.MakeEmpty();
					break;
				case 9: // exits the program
					exitMain = true; // exits types
					exit = true; // exits queue testing
					break;
				default: // if invalid input selected
					cout << "Invalid input. Please input another choice";
					cout << endl;
					break;
				}
			}
		case 3: // tests Queue functions
			while (!exit) { 
				cout << "Queue Functions:" << endl << "1.Enqueue" << endl << "2.Dequeue" << endl << "3.Peek" << endl << "4.IsEmpty";
				cout << endl << "5.MakeEmpty" << endl << "6.Length" << endl << "7.PrintQueue" << endl << "8.Back to types" << endl << "9.Exit" << endl;
				cout << "Enter choice: ";
				cin >> choice; // which function
				cout << endl;
				switch (choice) {
				case 1: // tests enqueue function
					cout << "String to be added to queue: ";
					getline(cin >> ws, input); // allows spaces in the input
					cout << endl;
					stringPointer = &input; // pointer to the input
					queue.Enqueue(stringPointer); // calls the enqueue function
					queue.PrintQueue(); // print for verification
					break;
				case 2: // test dequeue function
					try { // handles expception if empty
						retVal = queue.Dequeue(); // calls dequeue
						cout << "Value from start of queue: " << retVal << endl << endl;
					}
					catch (string std) {
						cout << endl;
					}
					break;
				case 3: // tests the peek function
					try { // handles exception if empty
						cout << "Value at start of queue: " << queue.Peek() << endl << endl;
					}
					catch (string std) {
						cout << endl;
					}
					break;
				case 4: // tests IsEmpty function
					queue.IsEmpty(); // calls isempty function
					if (queue.isEmpty()) { // if empty
						cout << "Queue is empty" << endl << endl;
					}
					else { // if not empty
						cout << "Queue is not empty" << endl << endl;
					}
					break;
				case 5: // tests MakeEmpty function
					cout << "Emptying queue" << endl;
					queue.MakeEmpty(); // calls Makeenmpty
					cout << "Checking if empty" << endl;
					cout << "Queue length: " << queue.Length() << endl << endl; // length for verification
					break;
				case 6: // test length function
					cout << "Queue length: " << queue.Length() << endl << endl;
					break;
				case 7: // test print function
					queue.PrintQueue();
					cout << endl;
					break;
				case 8: // returns to type selection
					exit = true; // exits queue testing
					queue.MakeEmpty();
					break;
				case 9: // exits program
					exitMain = true; // exits types
					exit = true; // exits queue testing					
					break;
				default: // if invalid input is entered
					cout << "Invalid input. Please input another choice";
					cout << endl;
					break;
				}
			}
		}
	}
	return 0;
}