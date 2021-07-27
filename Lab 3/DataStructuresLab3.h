#include <iostream>
#include <string>

using namespace std;

#ifndef STACK_CLASS
#define STACK_CLASS

class Stack {
private:
	int next; // spot where next value in stack goes
	char data[10]; // array to hold message
public:
	Stack() { // initializes next
		next = 0;
	};
	bool IsEmpty() { // whether the stack is empty
		if (next <= 0) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsFull() { // whether the stack is full
		if (next >= 10) {
			return true;
		}
		else {
			return false;
		}
	};
	void MakeEmpty() { // makes the stack empty
		if (IsEmpty() == true) {
			cout << "The stack is already empty." << endl;
		}
		else {
			next = 0;
		}
	};
	void Push(char parameterValue) { // adds value to top of stack
		if (IsFull() == true) {
			cout << "The stack is full.  Nothing can be added." << endl; // if stack is full
		}
		else {
			data[next] = parameterValue; // adds value to stack
			next = next + 1;
		}
	};
	char Pop() { // removes and returns top value from the stack
		if (IsEmpty() == true) {
			cout << "The stack is empty.  Nothing can be removed." << endl;
			throw string("error"); // Return statement would go here expection instead for empty error
		}
		else {
			next = next - 1;
			char returnValue = data[next]; // removes character from stack
			return returnValue;
		}
	};
	char Top() { // returns top value without removing it
		if (IsEmpty() == true) {
			cout << "The stack is empty.  There is no top value" << endl;
			throw string("error"); // Return statement would go here exception instead for empty error
		}
		else {
			int temp = next - 1; // temporarily set to next - 1 so value not removed
			char returnValue = data[temp];
			return returnValue;
		}
	};
	int Length() { // returns length of stack
		return next;
	};
};

#endif

#ifndef QUEUE_CLASS
#define QUEUE_CLASS

class Queue {
private:
	int start; // beginning of queue
	int next; // end of queue where next value goes
	int count; // current size of queue
	char data[10]; // array to hold queue values
public:
	Queue() { // intializing variables
		start = 0;
		next = 0;
		count = 0;
	};
	bool IsFull() { // whether the queue is full
		if ((start == next) && (count == 10)) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsEmpty() { // whether the queue is empty
		if ((start == next) && (count == 0)) {
			return true;
		}
		else {
			return false;
		}
	};
	void MakeEmpty() { // makes the queue empty
		if (IsEmpty() == true) {
			cout << "The queue is already empty." << endl;
		}
		else {
			start = 0;
			next = 0;
			count = 0;
		}
	};
	void Enqueue(char parameterValue) { // adds value to end queue
		if (IsFull() == true) {
			cout << "The queue is full.  Nothing can be added." << endl;
		}
		else {
			data[next] = parameterValue;
			next = (next + 1) % 10; // increments next and uses modulus to ensure ring queue
			count = count + 1; // tracks current size
		}
	};
	char Dequeue() { // removes and returns value from start of queue
		if (IsEmpty() == true) {
			cout << "The queue is empty.  Nothing can be removed." << endl;
			throw string("error"); // Return statement would go here exception instead for empty error
		}
		else {
			char returnValue = data[start]; 
			start = (start + 1) % 10; // increments start and uses modulus to make a ring queue
			count = count - 1; // decreases current size
			return returnValue;
		}
	};
	char Peek() { // returns starting value without removing
		if (IsEmpty() == true) {
			cout << "The queue is empty.  There is no first value." << endl;
			throw string("error"); // Return statement would go here exception instead for empty error
		}
		else {
			return data[start]; // returns without removing
		}
	};
	int Length() { // returns size of queue
		return count;
	}
};

#endif