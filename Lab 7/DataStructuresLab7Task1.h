#include <iostream>
using namespace std;
#pragma once
#ifndef MaxPriorityQueue // Include guards
#define MaxPriorityQueue

class Node { // Class for the individual nodes in the trees
public:
	Node* next; // Pointer to the next node
	int data; // Data the node holds
	int priority; // priority of the node
	Node(int val, int p) {
		data = val;
		priority = p;
		next = NULL;
	}
};

class PriorityQueue {
private:
	Node* head; // points at first item in linked list
	int count; // number of items in the linked list
public:
	PriorityQueue() { // Constructor
		head = NULL;
		count = 0;
	}

	~PriorityQueue() { // Destructor
		while (head != NULL) { // iterates through list and deletes the nodes
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	bool isEmpty() { // checks if empty
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Insert(int val, int p) {
		if (isEmpty()) {
			Node* item = new Node(val, p); // creates new node and sets the data and priority
			item->next = head; // next points at null
			head = item; // new head points at new first item in the list
			count = count + 1; // tracks size
		}
		else {
			Node* item = new Node(val, p); // creates new node and sets data and priority
			Node* temp = head; // temp node starting at head
			Node* temp2 = head; // temp2 node starting at head
			while (temp->next != NULL && temp->priority >= item->priority) { // searches for where the priority of item is higher than temp
				temp2 = temp; // becomes parent of new temp
				temp = temp->next; // points at next node of list
			}
			if (temp2->priority == item->priority) { // if priority is same as value in list already
				if(temp->next == NULL && temp == head){ // if temp is head
					item->next = NULL;
					temp2->next = item;
					count += 1;
				}
				else { // if temp is not the head
					item->next = temp;
					temp2->next = item;
					count += 1;
				}
			}
			else if (temp->next == NULL) { // if temp->next null have to make item-> next null
				if (temp == head && item->priority > temp->priority) { // if temp is head and item priority greater than temp priority
					item->next = head;
					head = item;
					count += 1;
				}
				else {
					temp->next = item; // points at item
					item->next = NULL;
					count += 1;
				}
			}
			else if (temp == head) { // if temp is head
				item->next = head;
				head = item;
				count += 1;
			}
			
			else {
				temp2->next = item; // points at item
				item->next = temp; // item next points to temp
				count += 1;
			}
		}
	}

	int Remove() {
		if (isEmpty()) { // if queue is empty
			throw string("The queue is empty");
		}
		else { // removes item
			Node* item = head; // sets item to top
			head = head->next; // head pointing at next item
			item->next = NULL;
			count -= 1; // reduce count
			int val = item->data;
			delete item; // removes from memory
			return val; 
		}
	}

	void PrintQueue() { // prints the queue
		if (isEmpty()) { // if list empty
			cout << "The queue is empty" << endl << endl;
		}
		else {
			Node* temp = head;
			cout << "Priority Queue:" << endl;
			while (temp != NULL) { // iterates through the list
				cout << "Data: " << temp->data << "   Priority: " << temp->priority << endl;
				temp = temp->next;
			}
			cout << endl;
		}
	}
};
#endif