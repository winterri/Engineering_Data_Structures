#include <iostream>
#include <string>

using namespace std;

#ifndef STACK_CLASS
#define STACK_CLASS

class Stack {
private:
	int next; // spot where next value in stack goes
	char data[25]; // array to hold message sent
public:
	Stack() {
		next = 0;
	};
	bool IsEmpty() { // whether stack is empty
		if (next <= 0) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsFull() { // whether stack is full
		if (next >= 25) {
			return true;
		}
		else {
			return false;
		}
	};
	void MakeEmpty() { // makes stack empty
		next = 0;
	};
	void Push(char parameterValue) { // adds new character to the stack
		if (IsFull() == true) {
			cout << "The stack is full.  Nothing can be added." << endl; // if stack is full
		}
		else {
			data[next] = parameterValue; // adds value to stack
			next = next + 1;
		}
	};
	char Pop() { // removes and returns top value from stack
		if (IsEmpty() == true) {
			cout << "The stack is empty.  Nothing can be removed." << endl;
			throw string("error"); // Return statement would go here exception thrown to state full
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
			throw string("error"); // Return statement would go here exception instead to state full
		}
		else {
			int temp = next - 1;
			char returnValue = data[temp]; // sets retrunValue to top of structure
			return returnValue;
		}
	};
	int Length() { // returns length of stack
		return next;
	};
	void PrintStack() { // prints out the values of the stack
		if (IsEmpty() == true) {
			cout << "The stack is empty." << endl;
		}
		else {
			int printIndex = next - 1;
			cout << "Stack Data:" << endl;
			while (printIndex >= 0) {
				cout << data[printIndex] << endl;
				printIndex = printIndex - 1;
			}
		}
	};
};

#endif

#ifndef QUEUE_CLASS
#define QUEUE_CLASS

class Queue {
private:
	int start; // beginning of queue
	int next; // end of queue where next value goes
	int count; // how many items in queue
	char data[25]; // array to hold queueu values
public:
	Queue() {
		start = 0;
		next = 0;
		count = 0;
	};
	bool IsFull() { // returns whether queue is full
		if ((start == next) && (count == 25)) {
			return true;
		}
		else {
			return false;
		}
	};
	bool IsEmpty() { // whether queue is empty is returned
		if ((start == next) && (count == 0)) {
			return true;
		}
		else {
			return false;
		}
	};
	void MakeEmpty() { // makes queue empty
		start = 0;
		next = 0;
		count = 0;
	};
	void Enqueue(char parameterValue) { // adds value to the queue
		if (IsFull() == true) {
			cout << "The queue is full.  Nothing can be added." << endl; // if queue is full
		}
		else {
			data[next] = parameterValue;
			next = (next + 1) % 25; // increments and uses modulus so a ring queue is made
			count = count + 1; // increments to know size of queue
		}
	};
	char Dequeue() { // removes and returns value at start of queue
		if (IsEmpty() == true) {
			cout << "The queue is empty.  Nothing can be removed." << endl;
			throw string("error"); // Return statement would go here exception instead to state full
		}
		else {
			char returnValue = data[start];
			start = (start + 1) % 25; // increments start and uses modulus queue is ring
			count = count - 1; // reduces count so the correct size is known
			return returnValue;
		}
	};
	char Peek() { // returns value at start of queue without removing
		if (IsEmpty() == true) {
			cout << "The queue is empty.  There is no first value." << endl;
			throw string("error"); // Return statement would go here execption instead for empty
		}
		else {
			return data[start];
		}
	};
	int Length() { // returns length of queue
		return count;
	}
	void PrintQueue() { // prints queue out
		if (IsEmpty() == true) {
			cout << "The queue is empty." << endl;
		}
		else {
			cout << "Queue Data:" << endl;
			int i = start;
			while (i < next) {
				cout << data[i] << endl;
				i = i + 1;
			}
		}
	};
};

#endif