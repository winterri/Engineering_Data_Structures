#include "DataStructuresLab4.h" // Includes the header file for linked list implementation
#include <iostream>

using namespace std;

int main() {

	LinkedList list; // Creates an instance of a linked list for us to use to test the member functions
	int choice; // Used to allow the user to choose what function they would like to test
	bool exit = false; // Used to allow the user to continue to test member functions until they would like to exit the menu
	Node* retPointer; // Used for holding pointers to nodes returned from member functions
	int* locationPointer; // Used for holding pointers to integers returned from member functions
	int location; // Used for holding the integer value of the pointer to pass to member functions
	string* stringPointer; // Used for holding string pointers to pass to member functions
	string input; // Used for holding the string value of the pointer returned from the member functions

	while (exit == false) { // Stays in while loop until user decides to exit the menu
		cout << "1) AddItemFront" << endl;
		cout << "2) AddItemEnd" << endl;
		cout << "3) GetItem" << endl;
		cout << "4) GetItemFront" << endl;
		cout << "5) IsInList" << endl;
		cout << "6) IsEmpty" << endl;
		cout << "7) Size" << endl;
		cout << "8) SeeNext" << endl;
		cout << "9) SeeAt" << endl;
		cout << "10) Reset" << endl;
		cout << "11) Print" << endl;
		cout << "12) Exit Menu" << endl;
		cout << "Please insert the number of the function you would like to test: ";
		cin >> choice; // User inputs what function they would like to test
		cout << endl;

		switch (choice) {
		case 1:
			cout << "What string would you like to add to the beginning of the list: ";
			getline(cin >> ws, input); // User inputs the string they would like to add to the front of the list
			cout << endl;
			stringPointer = &input; // Sets string pointer to pass to member function
			cout << "Original List:" << endl;
			list.Print();
			cout << endl;
			list.AddItemFront(stringPointer); // Adds item to the front of the list
			cout << "New List:" << endl;
			list.Print(); // Prints lists for verification
			cout << endl;
			break;
		case 2:
			cout << "What string would you like to add to the end of the list: ";
			getline(cin >> ws, input); // User inputs the string they would like to add to the end of the list
			cout << endl;
			stringPointer = &input; // Sets the string pointer to pass to member function
			cout << "Original List:" << endl;
			list.Print();
			list.AddItemEnd(stringPointer); // Adds item to the end of the list
			cout << "New List:" << endl;
			list.Print(); // Prints lists for verification
			break;
		case 3:
			cout << "What string value would you like to return from the list: ";
			getline(cin >> ws, input); // User inputs the string they would like to remove from the list
			cout << endl;
			stringPointer = &input; // Sets the string pointer to pass to member function
			if (list.IsInList(stringPointer) == true) { // Checks if the item is in the list
				retPointer = list.GetItem(stringPointer); // Gets the item from the list
				if (retPointer != nullptr) { // Checks if list is not empty
					cout << "Item retrieved: ";
					cout << retPointer->data << endl; // Outputs retrieved data
				}
			}
			else {
				cout << "Item is not in the list" << endl;
			}
			break;
		case 4:
			retPointer = list.GetItemFront(); // Gets the first item in the list
			if (retPointer != nullptr) { // Checks if list is not empty
				cout << "Front item: ";
				cout << retPointer->data << endl; // Outputs data removed from list (front item)
			}
			break;
		case 5:
			cout << "Input the string you would like to find in the list: ";
			getline(cin >> ws, input); // User inputs the string they would like to find in the list
			cout << endl;
			stringPointer = &input; // Sets the string pointer to pass to the member function
			cout << endl << *stringPointer << endl;
			if (list.IsInList(stringPointer) == true) { // Checks if the string is in the list
				cout << "The string you input is in the list" << endl;
			}
			else {
				cout << "The string you input is not in the list" << endl;
			}
			break;
		case 6:
			if (list.IsEmpty() == true) { // Checks if list is empty
				cout << "The list is empty" << endl;
				list.Print();
			}
			else {
				cout << "The list is not empty" << endl;
				list.Print(); // Prints list for verification
			}
			break;
		case 7:
			cout << "Size of the linked list: ";
			cout << list.Size() << endl; // Prints the size of the linked list
			break;
		case 8:
			cout << "First SeeNext value: ";
			try { // Try catch statement needed because SeeNext may throw an exception
				retPointer = list.SeeNext(); // Sees the "next" item in the list
				if (retPointer != nullptr) {
					cout << retPointer->data << endl;
				}
				else {
					cout << "Nothing to output" << endl;
				}
			}
			catch (string std) {
				cout << endl;
			}
			cout << "Second SeeNext value (for verification): ";
			try {
				retPointer = list.SeeNext(); // Sees the "next" item in the list again (for functionality verification)
				if (retPointer != nullptr) {
					cout << retPointer->data << endl;
				}
				else {
					cout << "No item in list" << endl;
				}
			}
			catch (string std) {
				cout << endl;
			}
			break;
		case 9:
			cout << "What location of the list would you like to see: ";
			cin >> location; // User inputs the location they would like to see
			cout << endl;
			locationPointer = &location; // Sets the integer pointer to pass to the member function
			try { // Try catch statement needed because SeeAt may throw an exception
				cout << "SeeAt value at desired location: ";
				retPointer = list.SeeAt(locationPointer); // Finds the item at the desired location
				cout << retPointer->data << endl;
			}
			catch (string std) {
				cout << endl;
			}
			break;
		case 10:
			list.Print(); // Prints the list for verification
			cout << "Original SeeNext value: ";
			try {
				retPointer = list.SeeNext(); // Sees the "next" value of the list
				cout << retPointer->data << endl;
			}
			catch (string std) {
				cout << endl;
			}
			cout << "Reseting the SeeNext pointer to the front of the list" << endl;
			list.Reset(); // Resets the "next" value to the front of the list
			cout << "SeeNext value (for verification): ";
			try {
				retPointer = list.SeeNext(); // Sees the "next" item in the list
				cout << retPointer->data << endl;
			}
			catch(string std) {
				cout << endl;
			}
			list.Reset(); // Resets the "next" value to the front of the list
			break;
		case 11:
			cout << "Printing list:" << endl;
			list.Print(); // Prints the list
			break;
		case 12:
			exit = true; // Sets exit to true to exit the while loop
			break;
		default:
			cout << "Invalid input entered.  Please enter a number 1 through 12" << endl;
			cout << endl;
			break;
		}
	}



	return 0;
}