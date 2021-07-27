#pragma once
#pragma once
#include <string>
#include <iostream>
#ifndef linked_list
#define linked_list
using namespace std;

class Node {
public:
	string data; // data in the node
	Node* next; // pointer to next node
};

class LinkedList {
private:
	Node* head; // top of list
	Node* nextNode; // points to next node
	Node* retNode; // return node
	int count; // tracks size of list
	int seeCounter; // if seeNext or seeAt has been called before
public:
	LinkedList() { // initializes variables
		head = nullptr;
		nextNode = head;
		count = 0;
		seeCounter = 0;
	}

	~LinkedList() { // deletes list
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp; // delete the value
		}
	}
	void addItemFront(string* val) { // add item to front of list
		Node* item = new Node();
		item->data = *val; // points node at value input
		item->next = head; // adds to list
		head = item;
		if (isEmpty()) { // sets nextNode to head for seeNext
			nextNode = head;
		}
		count = count + 1; // increases size
	}

	void addItemEnd(string* val) { // add item to end of list
		if (isEmpty() == true) {
			Node* item = new Node();
			item->data = *val; // put the val into new node
			item->next = head; // set the next
			head = item; // set to head
			count = count + 1; // increase the size of list
			nextNode = head;
		}
		else {
			Node* item = new Node(); // new node
			item->data = *val; // set data in new node to the val
			Node* temp = head;
			while (temp->next != NULL) { // find end of list
				temp = temp->next;
			}
			temp->next = item; // set end of list to the val
			count = count + 1; // increase size of list
		}
	}

	bool isEmpty() { // if the list is empty
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	Node* getItem(string* x) { // returns and removes the item input to the function
		if (isEmpty()) {
			cout << "List is empty" << endl << endl;
			return nullptr;
		}
		else {
			Node* temp = head;
			Node* item = head;
			if (head->data == *x) { // if the head is equal to data
				head = head->next;
				count = count - 1; // reduce the size
				if (isEmpty()) {
					nextNode = head; // sets nextNode to head since empty
				}
				else if (item == nextNode) { // sets nextNode to look at correct item
					nextNode = item->next;
				}
				item->next = nullptr;

				return item; // return the node
			}
			while (temp->next->data != *x && temp != NULL) { // searches for the item
				temp = temp->next;
			}
			if (temp == NULL) { // if temp is null item doesn't exits
				cout << "Item is not in the list" << endl << endl;
				return nullptr;
			}
			else {
				item = temp->next; // item set to temp since temp is the x value
				temp->next = item->next;
				if (item == nextNode) { // correcting nextNode
					nextNode = item->next;
				}
				item->next = nullptr; // remove from list
				count = count - 1; // reduce size
				return item; // return the node
			}
		}
	}

	Node* getItemFront() { // returns and removes first item in the list
		if (isEmpty()) { // if empty
			cout << "List is empty" << endl << endl;
			return nullptr;
		}
		else {
			Node* item = head; // set item to begining
			head = head->next;
			if (item == nextNode) { // item is nextNode reset the nextNode
				nextNode = head;
			}
			item->next = nullptr; // remove from list
			count = count - 1; // reduce size
			return item; // return the node
		}
	}

	bool IsInList(string* x) { // if string input is in list
		if (isEmpty()) {
			cout << "List Empty" << endl << endl;
			return false;
		}
		else {
			Node* temp = head;
			while (temp != NULL) { // searches for the item
				if (temp->data == *x) {
					return true; // if found in list
				}
				temp = temp->next;
			}
			return false;
		}
	}

	int size() { // size of list
		return count;
	}

	Node* seeNext() { // looks at the node at current position starting at first
		if (isEmpty()) {
			cout << "The list is empty" << endl;
			throw string("error"); // exception if list is empty
		}
		else {
			if (seeCounter == 0) { // sets nextNode to head if first time called
				nextNode = head;
			}

			if (nextNode == nullptr) { // if end of list
				cout << "end of list" << endl;
				return nullptr;
			}
			else { // if in the list
				retNode = nextNode; // sets node to be returned
				nextNode = nextNode->next; // points next node to the next node in list
				seeCounter = seeCounter + 1; // increases counter
				return retNode; // returns node
			}
		}
	}

	Node* seeAt(int* location) { // looks at the location passed to it
		if (*location > count) { // if location isnt in the list
			cout << "Location not in list" << endl;
			throw string("error"); // error if not in list
		}
		else {
			int i = 1;
			Node* temp = head;
			while (i != *location) { // searches for the item
				temp = temp->next;
				i = i + 1;
			}
			nextNode = temp->next; // sets nextNode to look at the next node
			seeCounter = seeCounter + 1; // increases counter
			return temp; // returns the node at the location
		}
	}

	void reset() { // resets the nextNode to head for seeNext
		nextNode = head;
		seeCounter = 0; // resets counter
	}

	void print() { // prints the linked list
		if (isEmpty()) {
			cout << "List is empty" << endl << endl;
		}
		else {
			Node* temp = head;
			while (temp != NULL) {
				cout << temp->data << endl;
				temp = temp->next;
			}
			cout << endl;
		}
	}
};

class Stack: public LinkedList {
private:
	int location; // location
	int* locationPointer; // pointer to the location
	string* stringPointer; // pointer to string
	Node* retVal; // returned node
	string retString; // returned string from functions
public:
	Stack() {
		LinkedList(); // calls linked list constructor
	}

	bool IsEmpty() { // whether stack is empty
		return isEmpty();
	}

	void MakeEmpty() { // makes stack empty
		while (!IsEmpty()) {
			retVal = getItemFront(); // gets item from front
			delete retVal; // deletes the returned item
		}
	}

	void Push(string* parameterValue) { // adds new character to the stack
		addItemFront(parameterValue); // adds item to front(top) of stack
	}

	string Pop() { // removes and returns top value from stack
		if (IsEmpty()) {
			cout << "The stack is empty" << endl;
			throw string("error");
		}
		retVal = getItemFront(); // gets item from front(top) of stack
		return retVal->data; // returns data from the node
	}

	string Top() { // returns top value without removing it
		if (IsEmpty() == true) {
			cout << "The stack is empty.  There is no top value" << endl;
			throw string("error"); // Return statement would go here exception instead to state empty
		}
		else {
			location = 1; // location to look at
			locationPointer = &location; // pointer to location
			try { // handles seeAt exception
				retVal = seeAt(locationPointer); // looks at first value using seeAt
				return retVal->data; // returns data in the node
			}
			catch (string std) {
				cout << endl;
			}			
		}
	}

	int Length() { // returns length of stack
		return size();
	}

	void PrintStack() { // prints out the values of the stack
		if (IsEmpty() == true) {
			cout << "The stack is empty." << endl;
		}
		else {
			cout << "Stack:" << endl;
			print();
		}
	}
};

class Queue: public LinkedList {
private:
	Node* retVal; // return node
	int* locationPointer; // points to location in queue
	int location; // location in the queue
public:
	Queue() {
		LinkedList(); // calls linked list constructor
	}

	bool IsEmpty() { // whether queue is empty is returned
		return isEmpty();
	}

	void MakeEmpty() { // makes queue empty
		while (!IsEmpty()) {
			retVal = getItemFront(); // removes from list
			delete retVal; // deletes returned node
		}
	}

	void Enqueue(string* parameterValue) { // adds value to the queue
		addItemEnd(parameterValue);
	}

	string Dequeue() { // removes and returns value at start of queue
		if (IsEmpty() == true) {
			cout << "The queue is empty.  Nothing can be removed." << endl;
			throw string("error"); // Return statement would go here exception instead to state full
		}
		else {
			retVal = getItemFront(); // gets item from front
			return retVal->data; // returns the string
		}
	}

	string Peek() { // returns value at start of queue without removing
		if (IsEmpty() == true) {
			cout << "The queue is empty.  There is no first value." << endl;
			throw string("error"); // Return statement would go here execption instead for empty
		}
		else {
			location = 1; // sets locaiton
			locationPointer = &location; // pointer at the location
			try { // handle seeAt exception
				retVal = seeAt(locationPointer); // looks at front value
				return retVal->data; // returns the string
			}
			catch (string std) {
				cout << endl;
			}
		}
	}

	int Length() { // returns length of queue
		return size();
	}

	void PrintQueue() { // prints queue out
		if (IsEmpty() == true) {
			cout << "The queue is empty." << endl;
		}
		else {
			cout << "Queue:" << endl;
			print();
		}
	}
};
#endif