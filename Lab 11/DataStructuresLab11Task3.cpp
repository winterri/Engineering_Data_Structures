#include <iostream>
#include <fstream>
#include "DataStructuresLab11Task3.h"

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
	LinkedList list;
	bool exit = false; // if true exits the program
	string strChoice; // which function to test
	int choice; // int variable for case structure
	ifstream inFile;
	string first, last, mNum;
	int mNumber;
	while (!exit) {
		cout << "Sorting Methods:" << endl << "1.BubbleSortAscending" << endl << "2.BubbleSortDescending" << endl << "3.InsertionSortAscending";
		cout << endl << "4.InsertionSortDescending" << endl << "5.MergeSortAscending" << endl << "6.MergeSortDescending" << endl;
		cout << "7.Exit" << endl << "Enter Choice: ";
		getline(cin >> ws, strChoice); // allows spaces
		if (isNum(strChoice)) { // if strChoice is a number than it is converted to in
			choice = stoi(strChoice);
		}
		else { // strChoice is not a number
			while (isNum(strChoice) == false) { // loops till number is input
				cout << "Enter a valid choice 1-7: ";
				getline(cin >> ws, strChoice); // gets user input					
			}
			choice = stoi(strChoice); // converts strChoice to integer
		}
		cout << endl;
		switch (choice) {
		case 1: // case to test bubble sort in ascending order
			list.MakeEmpty(); // empty the list
			inFile.open("Students.txt"); // open file of students
			while (!inFile.eof()) { // runs until end of file
				getline(inFile, first); // gets first name
				getline(inFile, last); // gets students last name
				getline(inFile, mNum); // gets students mnumber
				mNumber = stoi(mNum); // converts mnumber to integer
				list.AddItemEnd(first, last, mNumber); // inserts student at end of the list
			}
			inFile.close(); // close the file
			list.Print();
			list.BubbleSortAscending(); // sorts by First name in Ascending order
			cout << "Sorted List:" << endl << endl;
			list.Print();
			cout << "List Sorted by first name" << endl << endl;
			break;
		case 2: // case to test bubble sort in descending order
			list.MakeEmpty();
			inFile.open("Students.txt"); // open file of students
			while (!inFile.eof()) { // runs until end of file
				getline(inFile, first); // gets first name
				getline(inFile, last); // gets students last name
				getline(inFile, mNum); // gets students mnumber
				mNumber = stoi(mNum); // converts mnumber to integer
				list.AddItemEnd(first, last, mNumber); // inserts student at end of the list
			}
			inFile.close(); // close the file
			list.Print();
			list.BubbleSortDescending(); // sorts by First name in descending order
			cout << "Sorted List:" << endl << endl;
			list.Print();
			cout << "List Sorted by first name" << endl << endl;
			break;
		case 3: // case to test insertion sort in descending order
			list.MakeEmpty();
			inFile.open("Students.txt"); // open file of students
			while (!inFile.eof()) { // runs until end of file
				getline(inFile, first); // gets first name
				getline(inFile, last); // gets students last name
				getline(inFile, mNum); // gets students mnumber
				mNumber = stoi(mNum); // converts mnumber to integer
				list.AddItemEnd(first, last, mNumber); // inserts student at end of the list
			}
			inFile.close(); // close the file
			list.Print();
			list.InsertionSortAscending(); // sorts by Mnumber in Ascending order
			cout << "Sorted List:" << endl << endl;
			list.Print();
			cout << "List sorted by Mnumber" << endl << endl;
			break;
		case 4: // case to test insertion sort in descending order
			list.MakeEmpty();
			inFile.open("Students.txt"); // open file of students
			while (!inFile.eof()) { // runs until end of file
				getline(inFile, first); // gets first name
				getline(inFile, last); // gets students last name
				getline(inFile, mNum); // gets students mnumber
				mNumber = stoi(mNum); // converts mnumber to integer
				list.AddItemEnd(first, last, mNumber); // inserts student at end of the list
			}
			inFile.close(); // close the file
			list.Print();
			list.InsertionSortDescending(); // sorts by Mnumber in descending order
			cout << "Sorted List:" << endl << endl;
			list.Print();
			cout << "List sorted by Mnumber" << endl << endl;
			break;
		case 5: // case to test merge sort in ascending order
			list.MakeEmpty();
			inFile.open("Students.txt"); // open file of students
			while (!inFile.eof()) { // runs until end of file
				getline(inFile, first); // gets first name
				getline(inFile, last); // gets students last name
				getline(inFile, mNum); // gets students mnumber
				mNumber = stoi(mNum); // converts mnumber to integer
				list.AddItemEnd(first, last, mNumber); // inserts student at end of the list
			}
			inFile.close(); // close the file
			list.Print();
			list.MergeSortAscending(); // sorts by last name in Ascending order
			cout << "Sorted List:" << endl << endl;
			list.Print();
			cout << "List sorted by last Name" << endl << endl;
			break;
		case 6: // case to test merge sort in descending order
			list.MakeEmpty();
			inFile.open("Students.txt"); // open file of students
			while (!inFile.eof()) { // runs until end of file
				getline(inFile, first); // gets first name
				getline(inFile, last); // gets students last name
				getline(inFile, mNum); // gets students mnumber
				mNumber = stoi(mNum); // converts mnumber to integer
				list.AddItemEnd(first, last, mNumber); // inserts student at end of the list
			}
			inFile.close(); // close the file
			list.Print();
			list.MergeSortDescending(); // sorts by last name in descending order
			cout << "Sorted List:" << endl << endl;
			list.Print();
			cout << "List sorted by last name" << endl << endl;
			break;
		case 7: // case to exit main
			exit = true;
			break;
		default: // if choice is invalid
			cout << "Invalid input. Choose Again" << endl;
			break;
		}
	}
	return 0;
}