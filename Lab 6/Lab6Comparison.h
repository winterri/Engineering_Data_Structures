#include <string>
#include <iostream>

using namespace std;

#ifndef BINARY_TREE // Include guards
#define BINARY_TREE

class Node { // Class for the individual nodes in the trees
public:
	Node* left; // Pointer to the left child node
	Node* right; // Pointer to the right child node
	int data; // Data the node holds
	Node(int val) { // Constructor for a node
		data = val; // Initializes data to be desired string value
		left = nullptr; // Initializes left and right child pointers to be null
		right = nullptr;
	}
};

class Tree { // Class for the binary tree
private:
	Node* root; // Root pointer for the binary tree
	int count; // Holds the number of items in the tree
public:
	Tree() { // Default constructor
		root = nullptr; // Initializes root to null and count to zero (empty tree)
		count = 0;
	};
	~Tree() { // Destructor
		EmptyTree(); // Will empty the tree and delete individual nodes
		cout << "Tree successfully destroyed" << endl;
	};
	Node* getRoot() { // Function for returning the root of the binary tree
		return root;
	}
	bool IsEmpty() { // Function for testing if the tree is empty
		if (root == nullptr) {
			return true;
		}
		else {
			return false;
		}
	};
	void Insert(int val) { // Function for inserting a string into the tree
		if (IsEmpty() == true) {
			root = new Node(val); // Sets root to point at the newly created node if the list is empty
			count = count + 1;
		}
		else {
			Node* temp = root;
			while ((temp->left != nullptr && temp->data > val) || (temp->right != nullptr && temp->data < val)) { // While loop will find the parent of the item to be added
				if (temp->data > val) {
					temp = temp->left; // Goes to the left in the tree
				}
				else {
					temp = temp->right; // Goes to the right in the tree
				}
			}
			if (temp->data > val) {
				temp->left = new Node(val); // Creates new leaf node that holds the string value to the left of the parent
				count = count + 1;
			}
			else {
				temp->right = new Node(val); // Creates new leaf node that holds the string value to the right of the parent
				count = count + 1;
			}
		}
	};
	int Find(int val) { // Function for finding a string in a binary tree
		if (IsEmpty() == true) {
			throw string("Tree is empty"); // Throws an error if the tree is empty
		}
		else {
			Node* temp = root;
			while (temp != nullptr && temp->data != val) { // Will iterate until either the value is found or the end of the tree is reached without finding the value
				if (temp->data > val) {
					temp = temp->left; // Goes to the left in the tree
				}
				else {
					temp = temp->right; // Goes to the right in the tree
				}
			}
			if (temp == nullptr) {
				return -1; // Returns a blank string if the desired string wasn't found in the tree
			}
			else {
				return temp->data;
			}
		}
	};
	int Size() { // Function for returning the number of items in the binary tree
		return count;
	};
	void EmptyTree(Node* pointer) { // Overloaded function for emptying the tree
		if (IsEmpty() == true) {
			cout << "The tree is already empty" << endl;
		}
		else if (pointer != nullptr) {
			EmptyTree(pointer->left); // Code help on using recursion to empty the binary tree was obtained from www.stackoverflow.com
			EmptyTree(pointer->right);
			delete pointer;
		}
	};
	void EmptyTree() {
		EmptyTree(root); // Calls overloaded function starting at the root of the tree
		count = 0; // Sets count to be zero
		root = nullptr; // Sets root to be null pointer after the tree is empty and all nodes have been deleted
	};
	int Remove(int val) { // Function for removing a desired item from a binary tree
		if (IsEmpty() == true) {
			throw string("The tree is empty.  Nothing can be removed."); // Throws an error if the tree is empty
		}
		else {
			Node* temp = root;
			int retVal; // Will hold the value of the string to be removed and returned from the Remove function
			while (temp != nullptr && temp->data != val) { // Will find if the desired string is in the tree
				if (temp->data > val) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
			if (temp == nullptr) {
				throw string("The item is not in the tree"); // Will throw an error if the item is not in the tree and cannot be removed
			}
			if (temp == root) { // The item to be removed is the root
				if (temp->right == nullptr && temp->left == nullptr) { // Root is the only item in the tree
					retVal = temp->data; // Stores return string
					delete root; // Deletes node that root points at
					root = nullptr; // Resets root to be null after root node is removed
					count = count - 1;
					return retVal;
				}
				else if ((temp->right == nullptr && temp->left != nullptr) || (temp->right != nullptr && temp->left == nullptr)) { // Root has one child
					retVal = temp->data;
					if (temp->left != nullptr) {
						root = temp->left; // Sets the new root to be the child of what is to be removed
					}
					else {
						root = temp->right; // Sets the new root to be the child of what is to be removed
					}
					delete temp; // Deletes the original root node
					count = count - 1;
					return retVal;
				}
				else if (temp->right != nullptr && temp->left != nullptr) { // Root has two children
					retVal = temp->data;
					Node* temp2 = temp->left;
					while (temp2->right != nullptr) { // Will find the greatest smaller value of the item to be removed
						temp2 = temp2->right;
					}
					temp2->right = root->right; // Sets the right branch of the tree to be the new right branch of the greatest smaller value of the item to be removed
					root = root->left; // Sets the left child of the root to be the new root
					delete temp;
					count = count - 1;
					return retVal;
				}
			}
			else if (temp->right == nullptr && temp->left == nullptr) { // The item to be removed is a leaf
				temp = root;
				while ((temp->data > val && temp->left->data != val) || (temp->data < val && temp->right->data != val)) { // Finds the parent of the leaf to be removed
					if (temp->data > val) {
						temp = temp->left;
					}
					else {
						temp = temp->right;
					}
				}
				if (temp->data > val) {
					retVal = temp->left->data; // Left's data is the one we want to remove
					delete temp->left; // Deletes leaf node
					temp->left = nullptr;
				}
				else {
					retVal = temp->right->data; // Right's data is the one we want to remove
					delete temp->right; // Deletes leaf node
					temp->right = nullptr;
				}
				return retVal;
				count = count - 1;
			}
			else if ((temp->right == nullptr && temp->left != nullptr) || (temp->left == nullptr && temp->right != nullptr)) { // The item to be removed has 1 child
				Node* temp2;
				temp = root;
				while ((temp->data > val && temp->left->data != val) || (temp->data < val && temp->right->data != val)) { // Finds the parent of the item to be removed
					if (temp->data > val) {
						temp = temp->left;
					}
					else {
						temp = temp->right;
					}
				}
				if (temp->data > val) {
					retVal = temp->left->data;
					temp2 = temp->left;
					if (temp->left->left != nullptr) {
						temp->left = temp->left->left; // Loops the tree back together
					}
					else {
						temp->left = temp->left->right; // Loops the tree back together
					}
					delete temp2; // Deletes node we want to remove
				}
				else {
					retVal = temp->right->data;
					temp2 = temp->right;
					if (temp->right->right != nullptr) {
						temp->right = temp->right->right; // Loops the tree back together
					}
					else {
						temp->right = temp->right->left; // Loops the tree back together
					}
					delete temp2; // Deletes node we want to remove
				}
				count = count - 1;
				return retVal;
			}
			else if (temp->right != nullptr && temp->left != nullptr) { // The item to be removed has 2 children
				Node* temp2;
				temp = root;
				while ((temp->data > val && temp->left->data != val) || (temp->data < val && temp->right->data != val)) { // Finds the parent of the item to be removed
					if (temp->data > val) {
						temp = temp->left;
					}
					else {
						temp = temp->right;
					}
				}
				if (temp->data > val) {
					retVal = temp->left->data;
					temp2 = temp->left; // Will make temp2 point at the node we want to remove
					Node* temp3 = temp2;
					temp3 = temp3->left;
					while (temp3->right != nullptr) { // Will make temp3 point at the greatest smaller value
						temp3 = temp3->right;
					}
					temp->left = temp->left->left;
					temp3->right = temp2->right;
					delete temp2; // Deletes the node we want to remove
				}
				else {
					retVal = temp->right->data;
					temp2 = temp->right; // Will make temp2 point at the node we want to remove
					Node* temp3 = temp2;
					temp3 = temp3->right;
					while (temp3->left != nullptr) { // Will make temp3 point at the smallest greater value
						temp3 = temp3->left;
					}
					temp->right = temp->right->right;
					temp3->left = temp2->left;
					delete temp2; // Deletes the node we want to remove
				}
				count = count - 1;
				return retVal;
			}
		}
	};
	void PrintTree(Node* t) { // Overloaded function for printing the tree
		if (IsEmpty() == true) {
			cout << "The tree is empty" << endl;
			return;
		}
		else {
			if (t == nullptr) {
				return;
			}
			if (t->left == nullptr && t->right == nullptr) { // Will print if t is a leaf
				cout << t->data << "(NULL,NULL)" << endl;
				return;
			}
			else if (t->left != nullptr && t->right == nullptr) { // Will print if t has one child to the left
				cout << t->data << "(" << t->left->data << ",NULL)" << endl;
			}
			else if (t->left == nullptr && t->right != nullptr) { // Will print if t has one child to the right
				cout << t->data << "(NULL," << t->right->data << ")" << endl;
			}
			else { // Will print if t has two children
				cout << t->data << "(" << t->left->data << "," << t->right->data << ")" << endl;
			}
			PrintTree(t->left); // Recursive calls for printing the tree
			PrintTree(t->right);
		}
	};
	void PrintTree() { // Function for printing the tree
		PrintTree(root); // Calls the overloaded PrintTree function with the root as the parameter
		cout << endl;
	};
};

#endif#pragma once
