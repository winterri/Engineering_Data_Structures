#include <iostream>
#include "Lab5DataStructures.h"

using namespace std;

// some help from stackoverflow was used for isNum
bool isNum(string val) { // checks if input is a number
	for (int i = 0; i < val.length(); i++) { // loops through the string to check if number
		if (isdigit(val[i]) == false) { 
			return false;
		}
	}
	return true;
}

int main() {
	Tree tree; // creates instance of the tree class
	bool exit = false; // if true exits the program
	Node* root; // root to call getRoot function
	string strChoice; // which function to test
	int choice;
	string input, retVal; // input is string user adds, retVal is the string returned by remove
	while (!exit) {
		cout << "Binary Tree Functions:" << endl << "1.Insert" << endl << "2.Remove" << endl << "3.Find";
		cout << endl << "4.EmptyTree" << endl << "5.Size" << endl << "6.PrintTree" << endl << "7.Constructor";
		cout << endl << "8.Destructor" << endl << "9.Exit" << endl << "Enter choice: ";
		getline(cin >> ws, strChoice); // allows spaces
		if (isNum(strChoice)) { // if strChoice is a number than it is converted to in
			 choice = stoi(strChoice);
		}
		else { // strChoice is not a number
			while (isNum(strChoice) == false) { // loops till number is input
				cout << "Enter a valid choice 1-9: ";
				getline(cin >> ws, strChoice); // gets user input					
			}		
			choice = stoi(strChoice); // converts strChoice to integer
		}
		switch (choice) {
		case 1: // case to test Insert function
			cout << "Value to insert into tree: ";
			getline(cin >> ws, input); // allows words with spaces to be input
			tree.Insert(input); // calls insert function
			cout << "Printing tree to see if value added" << endl;
			tree.PrintTree(); // prints tree to check if value was insert
			cout << endl;
			break;
		case 2: // case to test Remove function
			cout << "Value to remove from tree: ";
			getline(cin >> ws, input); // allows words with spaces to be input
			try { // try catch to handle exception from remove function
				retVal = tree.Remove(input); // calls remove
				cout << "Value removed from tree: " << retVal << endl;
				cout << "Printing tree to see if value removed" << endl;
				tree.PrintTree(); // print tree to see if successfully removed
				cout << endl;
			}
			catch (string msg) { // if tree is empty this catches exception and prints it
				cout << msg << endl << endl;
			}
			break;
		case 3: // case to test Find function
			cout << "Value to find in tree: ";
			getline(cin >> ws, input); // allows words with spaces to be input
			try { // handles exception thrown in find function
				retVal = tree.Find(input); // calls find
				if (retVal == "") { // if a blank string is returned
					cout << "Value is not in the list" << endl << endl;
				}
				else if (retVal == input) { // if input is returned
					cout << "The value was found: " << input << endl << endl;
				}
			}
			catch (string msg) { // if tree is empty catches that excpetion and prints the message
				cout << msg << endl << endl;
			}
			break;
		case 4: // case to test EmptyTree
			cout << "Calling EmptyTree" << endl;
			tree.EmptyTree(); // calls EmptyTree
			if (tree.IsEmpty()) { // checks if tree was successfully emptied
				cout << "The tree is empty" << endl << endl;
			}
			else {
				cout << "Tree isn't empty" << endl << endl;
			}
			break;
		case 5: // case to test size of tree
			cout << "Size of tree: " << tree.Size() << endl << endl;
			break;
		case 6: // case to test PrintTree function
			tree.PrintTree(); // prints the tree
			cout << endl;
			break;
		case 7: // case to test constructor
		{
			Tree testTree; // testTree instance of Tree class that ends after case is over
			cout << "Creating new class instance" << endl;
			if ((testTree.Size() == 0) && (testTree.getRoot() == NULL)) { // if count is 0 and root is NULL it worked
				cout << "constructor successful" << endl;
			}
			else {
				cout << "constructor failed" << endl << endl;
			}
			
		}
			cout << endl;
			break;
		case 8: // case to test destructor
		{
			cout << "Creates temporary Tree class to test destructor" << endl;
			Tree testTree; // testTree instance of Tree class that ends after case is over
			testTree.Insert("Test"); // inserts string so tree isn't empty
			testTree.PrintTree(); // prints tree
		} // after brace testTree ends so the destructor is called
			cout << endl;
			break;
		case 9: // case to exit while loop and the main
			exit = true;
			break;
		default: // if an invalid input is entered
			cout << "Invalid input. Try another choice." << endl << endl;
			break;
		}
	}
	return 0;
}