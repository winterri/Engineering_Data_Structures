#include "DataStructuresLab3_Task3.h"

using namespace std;

int main() {

	string message; // message user inputs
	string finalMessage; // transformed message
	bool exit = true; // exits main
	char testAgain; // whether to continue
	char addToSender; // characters of message to send to stack and queue
	char reversal; // message being reversed and sent
	char secondReversal; // message being reversed and sent again
	int i; // used for length
	char temp; // temp to for when remving values

	while (exit == true) {
		Stack senderStack; // stack for big edian reversal
		Stack recipientStack;
		Queue recipientQueue;
		cout << "SPECIAL NOTE: Please ensure that your message does not exceed 24 characters in length" << endl;
		cout << "Please insert the message you would like to send: ";
		getline(cin >> ws, message); // This line of code was obtained with help from stack overflow
		cout << endl;
		i = message.length(); // Length will be used for indexing in the loops between stack and queue data transfers
		senderStack.Push('\0'); // Adds the null terminator so the queue knows when to stop adding items to the buffer
		for (int k = 0; k < i; k++) {
			addToSender = message[k];
			senderStack.Push(addToSender); // Adds individual characters to the sender stack, starting with the first item in the message
		}
		try {
			temp = senderStack.Pop(); // Initializes value of temp for following while loop to be top value of the stack
		}
		catch (string std) {
			cout << endl;
		}
		
		while (temp != '\0') {
			recipientQueue.Enqueue(temp); // Adds characters from the sender stack to the queue buffer
			try {
				temp = senderStack.Pop(); // Resets temp to be the next item in the sender stack
			}
			catch (string std) {
				cout << endl;
			}
		}
		cout << "Values in the recipient buffer (queue): " << endl;
		recipientQueue.PrintQueue(); // Displays values in the buffer in the order in which they would be removed from the queue
		for (int j = 0; j < i; j++) {
			try {
				reversal = recipientQueue.Dequeue(); // Sets reversal equal to the value to be removed from the queue, starting with the first item in the queue
			}
			catch (string std) {
				cout << endl;
			}
			recipientStack.Push(reversal); // Adds item removed from the queue buffer into the receiver stack
		}
		recipientStack.PrintStack(); // Displays everything in the stack in the order in which it would be removed from the stack
		finalMessage = "";
		for (int h = 0; h < i; h++) {
			try {
				finalMessage.push_back(recipientStack.Pop()); // Adds character removed from receiver stack to the final message string
			}
			catch (string std) {
				cout << endl;
			}
		}
		cout << "Final Message: " << finalMessage << endl; // Displays final message
		cout << "Would you like to test another message (y/n): ";
		cin >> testAgain;
		cout << endl;
		if ((testAgain == 'n') || (testAgain == 'N')) {
			exit = false; // Exits while loop if user selects option to not test another message
		}
	}

	return 0;
}
