#include <string>
#include <iostream>

using namespace std;

#ifndef LINKED_LIST // Include guards
#define LINKED_LIST

typedef class Node* nodePtr;

class Node { // Defines the nodes that will go in our linked list
public:
	string first;
	string last;
	int mNumber;
	Node* next; // Pointer to a node to link nodes together
	Node(string f, string l, int val) {
		first = f;
		last = l;
		mNumber = val;
		next = nullptr;
	}
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
	}

	void MakeEmpty() {
		while (head != nullptr) { // Iterates through list and deletes nodes in the list, preventing memory leaks
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		count = 0;
	}

	void AddItemFront(string first, string last, int mNum) { // Function adding item to the front of the linked list
		Node* item = new Node(first, last, mNum);
		item->next = head; // Item points at the old first item in the list
		head = item; // The new head points at the new first item in the list
		if (IsEmpty() == true) {
			nextNode = head;
		}
		count = count + 1;
	}

	void AddItemEnd(string first, string last, int mNum) { // Function adding item to the end of the linked list
		if (IsEmpty() == true) {
			Node* item = new Node(first, last, mNum);
			item->next = head; // Item points at the old first item in the list
			head = item; // The new head points at the new first item in the list
			nextNode = head;
			count = count + 1;
		}
		else {
			Node* item = new Node(first, last, mNum);
			Node* temp = head;
			while (temp->next != nullptr) { // Cycles through the list until the end of the list is found
				temp = temp->next;
			}
			temp->next = item; // Sets location of the last item's pointer to point at the new item to be added
			count = count + 1;
		}
	}

	Node* GetItem(int mNum) { // Function for removing an item with a desired string from the list
		if (IsEmpty() == true) {
			cout << "The list is empty" << endl;
			return nullptr;
		}
		else {
			if (head->mNumber == mNum) { // Checks if the first node is the item to be removed
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
			while ((temp->next->mNumber != mNum) && (temp != nullptr)) { // While loop looks until end of the list is reached or until the string is found
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
	}

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
	}

	bool IsInList(int mNum) { // Function to see if a desired string is in a list
		if (IsEmpty() == true) {
			return false;
		}
		else {
			Node* temp = head;
			while (temp != nullptr) { // Goes through the entire list
				if (temp->mNumber == mNum) { // Checks if the desired string is in the individual items
					return true;
				}
				else {
					temp = temp->next;
				}
			}
			return false;
		}
	}

	int Size() { // Function that returns the number of items in the list
		return count;
	}

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
	}

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
	}

	void Reset() { // Function to reset the "next" item in the list back to the front of the list
		nextNode = head;
		seeCounter = 0;
	}

	void Print() { // Function that prints all of the items in a list
		if (IsEmpty() == true) {
			cout << "The list is empty" << endl << endl;
		}
		else {
			Node* temp = head;
			cout << "List:" << endl;
			while (temp != nullptr) { // Iterates through the whole list 
				cout << "Name: " << temp->first << " " << temp->last << endl;
				cout << "MNumber: M" << temp->mNumber << endl << endl;
				temp = temp->next;
			}
		}
	}

	void BubbleSortAscending() { // sorts list in ascending order by first name
		if (IsEmpty()) {
			cout << "The list is empty" << endl;
		}
		else {
			for (int i = 1; i < count + 1; i++) { // iterates till it reaches count + 1
				Node* item = head;
				while (item != nullptr) { // runs until end of the list
					if (item->next != nullptr) { // if the next item exists
						if (item->first > item->next->first) { // if the item is greater than the next item
							if (item == head) { // if item is head
								Node* temp = item; // save item
								head = item->next; // removes item from list
								temp->next = head->next; // set temp next to point at second thing in list
								head->next = temp; //put temp in as second thing in the list
								item = head->next; // iterate head
							}
							else {
								Node* temp = item; // save item
								Node* temp2 = head;
								while (temp2->next != temp) { // find parent of temp
									temp2 = temp2->next;
								}
								temp2->next = item->next; // remove item from list
								temp->next = temp2->next->next; // set temps next to be next thing in list
								temp2->next->next = temp; // insert temp into the list
								item = item->next; // iterate item
							}
						}
						else {
							item = item->next; // iterate item
						}
					}
					else {
						item = item->next; // iterate item
					}
				}
			}
		}
	}

	void BubbleSortDescending() { // sort list using bubble sort in a descending order
		if (IsEmpty()) {
			cout << "The list is empty" << endl;
		}
		else {
			for (int i = 1; i < count + 1; i++) { // iterates till count + 1
				Node* item = head;
				while (item != nullptr) { // runs until end of list
					if (item->next != nullptr) { // if next item exists
						if (item->first < item->next->first) { // if current item is less than the next
							if (item == head) { // if item is head
								Node* temp = item; // save item
								head = item->next; // remove item from the list
								temp->next = head->next; // temp next points at second item in list
								head->next = temp; // insert temp between first and second item
								item = head->next; // iterate item
							}
							else {
								Node* temp = item; // save item
								Node* temp2 = head;
								while (temp2->next != temp) { // find parent of temp
									temp2 = temp2->next;
								}
								temp2->next = item->next; // remove item from list
								temp->next = temp2->next->next; // have temp point at next item
								temp2->next->next = temp; // insert temp into the list
								item = item->next; // iterate item
							}
						}
						else {
							item = item->next; // iterate item
						}
					}
					else {
						item = item->next; // iterate item
					}
				}
			}
		}
	}

	void InsertionSortAscending() { // sort list in ascending order using insertion sort
		if (IsEmpty()) {
			cout << "list is empty" << endl;
		}
		else {
			Node* item = head;
			Node* temp;
			while (item != nullptr && item->next != nullptr) { // runs while item and the next item exist
				if (item->mNumber > item->next->mNumber) { // if current item mnumber greater than next item's mnumber
					temp = item->next; // remove item from list
					item->next = item->next->next; // iterate the item
					Node* temp2 = head;
					while (temp2 != nullptr && temp2->next != nullptr) { // runs until end of list
						if (temp->mNumber < temp2->mNumber) { // if item to be inserted is less then the first item
							Node* temp3 = head; // save the current head
							head = temp; // insert temp at beginning of the list
							temp->next = temp3; // insert the rest of the list
							break;
						}
						if (temp->mNumber > temp2->mNumber && temp->mNumber < temp2->next->mNumber) { // if temp is less than next item and greater than the previous
							Node* temp3 = temp2->next; // save temp2 next value
							temp2->next = temp; // insert temp
							temp->next = temp3; // add the rest of list at end of temp
							break;
						}
						else {
							temp2 = temp2->next; // iterate temp2
						}
					}
				}
				else {
					item = item->next; // iterate item
				}
			}
		}
	}

	void InsertionSortDescending() { // sort the list in descending order using insertion sort
		if (IsEmpty()) {
			cout << "list is empty" << endl;
		}
		else {
			Node* item = head;
			Node* temp;
			while (item != nullptr && item->next != nullptr) { // runs until end of the list
				if (item->mNumber < item->next->mNumber) { // if the current item is less than the next item
					temp = item->next; // remove the item from the list
					item->next = item->next->next; // iterate item
					Node* temp2 = head;
					while (temp2 != nullptr && temp2->next != nullptr) { // runs until the end of the list
						if (temp->mNumber > temp2->mNumber) {
							Node* temp3 = head; // save the current head
							head = temp; // insert temp at beginning of the list
							temp->next = temp3; // add rest of the list to end
							break;
						}
						if (temp->mNumber < temp2->mNumber && temp->mNumber > temp2->next->mNumber) { // if temp is less then current temp2 and greater than the next temp2
							Node* temp3 = temp2->next; // save next value
							temp2->next = temp; // insert temp into the list
							temp->next = temp3; // add the rest of list to the end
							break;
						}
						else {
							temp2 = temp2->next; // iterate temp2
						}
					}
				}
				else {
					item = item->next; // iterate item
				}
			}
		}
	}

/*
	For the merge sort implementation, we used help from YouTube tutorials on how to perform merge sort on a linked list.  The links to these 2 tutorial videos are below:
	Part 1: https://www.youtube.com/watch?v=jOyYaBHyN28
	Part 2: https://www.youtube.com/watch?v=iQzoVUU5-Ss
*/
	
	
	void Partition(nodePtr ptrParameter, nodePtr* l1, nodePtr* l2) { // Function for partitioning the linked list into 2 smaller linked lists (used for Merge Sort)
		nodePtr fast; // Fast pointer (will move through list until end of list is reached)
		nodePtr slow; // Slow pointer (will trail behind fast pointer to find the middle location of linked list)
		if (ptrParameter == nullptr || ptrParameter->next == nullptr) { // Will check if there is either nothing to point at in list or if item is only one in list
			*l1 = ptrParameter; // Sets the first list equal to the value of the one item in the list
			*l2 = nullptr; // Sets the second list equal to nullptr
		}
		else { // Will execute if there is more than one item in the list being passed into Partition function
			slow = ptrParameter; // Starts slow pointer at the first item in the list
			fast = ptrParameter->next; // Starts the fast pointer one item ahead of the slow pointer
			while (fast != nullptr) { // Will execute until the fast pointer has reached the end of the list
				fast = fast->next; // Will first need to move the fast pointer to the next item in the list
				if (fast != nullptr) { // Will only execute if fast pointer has not yet reached end of list
					slow = slow->next; // Moves slow pointer to next item in list
					fast = fast->next; // Moves fast pointer to next item in list
				}
			} // End of while loop means fast pointer has reached end of list and slow pointer is pointing at where we want to split the list
			*l1 = ptrParameter; // Sets the first list equal to the front of the entire list
			*l2 = slow->next; // Sets the second list equal to the part of the list after the slow pointer
			slow->next = nullptr; // Splits the list at the slow pointer location
		}
	};

	Node* MergeListsAscending(nodePtr l1, nodePtr l2) { // Function for merging the partitioned lists back together in an ascending order
		nodePtr mergedList = nullptr;
		if (l1 == nullptr) { // Recursion exit case for when l1 is nullptr
			return l2;
		}
		else if (l2 == nullptr) { // Recursion exit case for when l2 is nullptr
			return l1;
		}
		if (l1->last <= l2->last) { // Checks if l1 is less than or equal to l2 (comparison based on last name)
			mergedList = l1; // Sets the merged list equal to the smaller of the two values (l1)
			mergedList->next = MergeListsAscending(l1->next, l2); // Recursive call to MergeListsAscending (links to the merged list)
		}
		else {
			mergedList = l2; // Sets the merged list equal to the smaller of the two values (l2)
			mergedList->next = MergeListsAscending(l1, l2->next); // Recursive call to MergeListsAscending (links to the merged list)
		}
		return mergedList; // Returns the merged list
	};

	Node* MergeListsDescending(nodePtr l1, nodePtr l2) { // Function for merging the partitioned lists back together in a descending order
		nodePtr mergedList = nullptr;
		if (l1 == nullptr) { // Recursion exit case for when l1 is nullptr
			return l2;
		}
		else if (l2 == nullptr) { // Recursion exit case for when l2 is nullptr
			return l1;
		}
		if (l1->last >= l2->last) { // Checks if l1 is greater than or equal to l2 (comparison based on last name)
			mergedList = l1; // Sets the merged list equal to the larger of the two values (l1)
			mergedList->next = MergeListsDescending(l2, l1->next); // Recursive call to MergeListsDescending (links to the merged list)
		}
		else {
			mergedList = l2; // Sets the merged list equal to the larger of the two values (l2)
			mergedList->next = MergeListsDescending(l2->next, l1); // Recursive call to MergeListsDescending (links to merged list)
		}
		return mergedList; // Returns the merged list
	};

	void MergeSortAscending(nodePtr* ptrParameter) { // Merge Sort function for an ascending order
		nodePtr head2 = *ptrParameter;
		nodePtr list1 = nullptr; // Initializes list1 to nullptr
		nodePtr list2 = nullptr; // Initializes list2 to nullptr
		if (head2 == nullptr || head2->next == nullptr) { // Exit case for recursive call to MergeSortAscending
			return;
		}
		Partition(head2, &list1, &list2); // Partitions the list into two smaller lists (stored in list1 and list2)
		MergeSortAscending(&list1); // Recursive call to MergeSortAscending on list1
		MergeSortAscending(&list2); // Recursive call to MergeSortAscending on list2
		*ptrParameter = MergeListsAscending(list1, list2); // Merges list1 and list2 back together in ascending order
	};

	void MergeSortDescending(nodePtr* ptrParameter) { // Merge sort function for a descending order
		nodePtr head2 = *ptrParameter;
		nodePtr list1 = nullptr; // Initializes list1 to nullptr
		nodePtr list2 = nullptr; // Initializes list2 to nullptr
		if (head2 == nullptr || head2->next == nullptr) { // Exit case for recursive call to MergeSortDescending
			return;
		}
		Partition(head2, &list1, &list2); // Partitions the list into two smaller lists (stored in list1 and list2)
		MergeSortDescending(&list1); // Recursive call to MergeSortDescending on list1
		MergeSortDescending(&list2); // Recursive call to MergeSortDescending on list2
		*ptrParameter = MergeListsDescending(list1, list2); // Merges list1 and list2 back together in descending order
	};

	void MergeSortAscending() { // Overloaded MergeSortAscending function
		MergeSortAscending(&head); // Passes the head pointer of our linked list into the MergeSortAscending function
	}

	void MergeSortDescending() { // Overload MergeSortDescending function
		MergeSortDescending(&head); // Passes the head pointer of our linked list into the MergeSortDescending function
	}
};
#endif
