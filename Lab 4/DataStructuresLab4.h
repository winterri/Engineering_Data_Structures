#include <string>
#include <iostream>

using namespace std;

#ifndef LINKED_LIST // Include guards
#define LINKED_LIST

class Node { // Defines the nodes that will go in our linked list
public:
	string data; // Data in the node is a string
	Node* next; // Pointer to a node to link nodes together
private:

};

class LinkedList { // Defines our linked list
private:
	Node* head; // Points at the first item in the linked list
	int count; // Holds number of items in the linked list
	Node* nextNode; // Holds the "next" location in the linked list
	int seeCounter; // Used for implementation of SeeNext and SeeAt functions
public:
	LinkedList() { // Constructor
		head = nullptr;
		count = 0;
		nextNode = nullptr;
		seeCounter = 0;
	}
	~LinkedList() { // Destructor
		while (head != nullptr) { // Iterates through list and deletes nodes in the list, preventing memory leaks
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
	bool IsEmpty() { // Function testing to see if the list is empty
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	void AddItemFront(string* pointerParameter) { // Function adding item to the front of the linked list
		Node* item = new Node;
		item->data = *pointerParameter; // Sets new item's data equal to the desired string
		item->next = head; // Item points at the old first item in the list
		head = item; // The new head points at the new first item in the list
		if (IsEmpty() == true) {
			nextNode = head;
		}
		count = count + 1;
	};
	void AddItemEnd(string* pointerParameter) { // Function adding item to the end of the linked list
		if (IsEmpty() == true) {
			Node* item = new Node;
			item->data = *pointerParameter; // Sets new item's data equal to the desired string
			item->next = head; // Item points at the old first item in the list
			head = item; // The new head points at the new first item in the list
			nextNode = head;
			count = count + 1;
		}
		else {
			Node* item = new Node;
			item->data = *pointerParameter;
			Node* temp = head;
			while (temp->next != nullptr) { // Cycles through the list until the end of the list is found
				temp = temp->next;
			}
			temp->next = item; // Sets location of the last item's pointer to point at the new item to be added
			count = count + 1;
		}
	};
	Node* GetItem(string* pointerParameter) { // Function for removing an item with a desired string from the list
		if (IsEmpty() == true) {
			cout << "The list is empty" << endl;
			return nullptr;
		}
		else {
			if (head->data == *pointerParameter) { // Checks if the first node is the item to be removed
				Node* item = head; // Sets item to point at the first item in the list, the item to be removed
				head = head->next; // Removes the first item from the list
				item->next = nullptr; 
				count = count - 1;
				if (IsEmpty() == true) {
					nextNode = head;
				}
				else if (nextNode == item) {
					nextNode = head;
				}
				return item;
			}
			Node* item;
			Node* temp = head;
			while ((temp->next->data != *pointerParameter) && (temp != nullptr)) { // While loop looks until end of the list is reached or until the string is found
				temp = temp->next;
			}
			if (temp == nullptr) { // If temp is null pointer, item was not ever found in the list
				cout << "Item is not in the list" << endl;
				return nullptr;
			}
			else {
				item = temp->next; // Temp points at the item before the item with the desired string
				temp->next = item->next; // Links the list together properly after removing the item
				if (item == nextNode) {
					nextNode = item->next;
				}
				count = count - 1;
				item->next = nullptr;
				return item;
			}
		}
	};
	Node* GetItemFront() { // Function that removes the first item from the linked list
		if (IsEmpty() == true) {
			cout << "The list is empty" << endl;
			return nullptr;
		}
		else {
			Node* item = head; // Sets item to point at the first item in the list, the item to be removed
			head = head->next; // Removes the first item from the list
			if (item == nextNode) {
				nextNode = head;
			}
			item->next = nullptr;
			count = count - 1;
			return item;
		}
	};
	bool IsInList(string* pointerParameter) { // Function to see if a desired string is in a list
		if (IsEmpty() == true) {
			return false;
		}
		else {
			Node* temp = head;
			while (temp != nullptr) { // Goes through the entire list
				if (temp->data == *pointerParameter) { // Checks if the desired string is in the individual items
					return true;
				}
				else {
					temp = temp->next;
				}
			}
			return false;
		}
	};
	int Size() { // Function that returns the number of items in the list
		return count;
	};
	Node* SeeNext() { // Function that sees the "next" item in the list
		if (IsEmpty() == true) {
			cout << "The list is empty" << endl;
			throw string("error"); // Error thrown if list is empty
		}
		else {
			if (seeCounter == 0) {
				nextNode = head; // Initializes nextNode to the front of the list if this is the first time SeeNext or SeeAt is called
			}
			if (nextNode == nullptr) {
				return nullptr;
			}
			else {
				Node* item;
				item = nextNode; // Grabs item nextNode is pointing at
				nextNode = nextNode->next; // Iterates nextNode to point at the next item in the list
				seeCounter = seeCounter + 1;
				return item;
			}
		}
	};
	Node* SeeAt(int* integerPointer) { // Function to see an item at a desired location in the list
		if (*integerPointer > count) {
			cout << "Location is not in the list" << endl;
			throw string("error"); // Throws error if location is not in the list
		}
		else {
			Node* temp = head;
			int i = 1;
			while (i != *integerPointer) { // Finds the item in the list to be viewed
				temp = temp->next;
				i = i + 1;
			}
			nextNode = temp->next; // Iterates nextNode to the next item in the list
			seeCounter = seeCounter + 1;
			return temp;
		}
	};
	void Reset() { // Function to reset the "next" item in the list back to the front of the list
		nextNode = head;
		seeCounter = 0;
	};
	void Print() { // Function that prints all of the items in a list
		if (IsEmpty() == true) {
			cout << "The list is empty" << endl;
		}
		else {
			Node* temp = head;
			cout << "List:" << endl;
			while (temp != nullptr) { // Iterates through the whole list 
				cout << temp->data << endl; // Prints individual data item
				temp = temp->next;
			}
		}
		cout << endl;
	};
};

#endif