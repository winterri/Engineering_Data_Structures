#include <iostream>
#include "DataStructuresLab10Task1.h"

using namespace std;

bool isNum(string val) { // checks if input is a number
	for (int i = 0; i < val.length(); i++) { // loops through the string to check if number
		if (isdigit(val[i]) == false) {
			return false;
		}
	}
	return true;
}

int getGraphSize() {
	string sizeOption; // Size option input as a string from user
	int sizeOpt; // Holds the size option that the user chooses
	int size; // Array size to be set
	string sizeInput; // Size input as a string from user
	cout << "What size would you like the table to be?" << endl;
	cout << "1: Default Size (50)" << endl;
	cout << "2: Insert Own Size" << endl;
	getline(cin >> ws, sizeOption);
	if (isNum(sizeOption)) { // if sizeOption is a number than it is converted to int
		sizeOpt = stoi(sizeOption);
	}
	else { // strChoice is not a number
		while (isNum(sizeOption) == false) { // loops till number is input
			cout << "Enter a valid choice 1 or 2: ";
			getline(cin >> ws, sizeOption); // gets user input					
		}
		sizeOpt = stoi(sizeOption); // converts sizeOption to integer
	}
	if (sizeOpt == 1) {
		size = 50; // Default size
		return size;
	}
	else if (sizeOpt == 2) {
		cout << "What size would you like the graph to be: ";
		getline(cin >> ws, sizeInput);
		if (isNum(sizeInput)) {
			size = stoi(sizeInput); // Converts user input for size into an integer
		}
		else {
			while (isNum(sizeOption) == false) { // Checks if the input is not a number
				cout << "Please enter a number for the size: ";
				getline(cin >> ws, sizeOption);
			}
			size = stoi(sizeOption); // Converts user input for size into an integer
		}
		return size;
	}
}

int main() {
	int testGraphSize = getGraphSize(); // Gets the size for the array for the graph
	Graph graph1(testGraphSize); // Declares graph of proper size
	bool exit = false; // if true exits the program
	string strChoice; // which function to test
	int choice; // int variable for case structure
	vector<int> edges; // Vector that holds all the in or out edges of a certain vertex
	string strI, strJ; // string inputs for i and j
	int i, j; // values for adding, removing, and finding vertices, edges, inEdges, and outEdges
	while (!exit) {
		cout << "Graph Functions:" << endl << "1.AddEdge" << endl << "2.RemoveEdge" << endl << "3.FindEdge";
		cout << endl << "4.FindOutEdges" << endl << "5.FindInEdges" << endl << "6.AddVertex" << endl;
		cout << "7.RemoveVertex" << endl << "8.PrintGraph" << endl << "9.Exit" << endl << "Enter Choice: " << endl;
		getline(cin >> ws, strChoice); // allows spaces
		if (isNum(strChoice)) { // if strChoice is a number than it is converted to in
			choice = stoi(strChoice);
		}
		else { // strChoice is not a number
			while (isNum(strChoice) == false) { // loops till number is input
				cout << "Enter a valid choice 1-6: ";
				getline(cin >> ws, strChoice); // gets user input					
			}
			choice = stoi(strChoice); // converts strChoice to integer
		}
		switch (choice) {
		case 1: 
			cout << "Enter vertex i: ";
			getline(cin >> ws, strI); // allows spaces
			if (isNum(strI)) { // if strI is a number than it is converted to int
				i = stoi(strI);
			}
			else { // strI is not a number
				while (isNum(strI) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strI); // gets user input					
				}
				i = stoi(strI); // converts strI to integer
			}
			cout << endl;
			cout << "Enter vertex j being pointed at by i: ";
			getline(cin >> ws, strJ); // allows spaces
			if (isNum(strJ)) { // if strJ is a number than it is converted to int
				j = stoi(strJ);
			}
			else { // strJ is not a number
				while (isNum(strJ) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strJ); // gets user input					
				}
				j = stoi(strJ); // converts strJ to integer
			}
			graph1.AddEdge(i, j); // Adds edge to from i to j in the graph
			if (graph1.HasEdge(i, j)) { // Checks if edge was added for verification
				cout << "Edge has been successfully added" << endl;
			}
			break;
		case 2: 
			cout << "Enter vertex i: ";
			getline(cin >> ws, strI); // allows spaces
			if (isNum(strI)) { // if strI is a number than it is converted to int
				i = stoi(strI);
			}
			else { // strI is not a number
				while (isNum(strI) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strI); // gets user input					
				}
				i = stoi(strI); // converts strI to integer
			}
			cout << endl;
			cout << "Enter vertex j being pointed at by i: ";
			getline(cin >> ws, strJ); // allows spaces
			if (isNum(strJ)) { // if strJ is a number than it is converted to int
				j = stoi(strJ);
			}
			else { // strChoice is not a number
				while (isNum(strJ) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strJ); // gets user input					
				}
				j = stoi(strJ); // converts strJ to integer
			}
			graph1.RemoveEdge(i, j); // Removes edge pointing from i to j from the graph
			if (graph1.HasEdge(i, j) == false) { // Checks that the edge no longer exists for verification
				cout << "Edge has been successfully removed" << endl;
			}
			break;
		case 3: 
			cout << "Enter vertex i: ";
			getline(cin >> ws, strI); // allows spaces
			if (isNum(strI)) { // if strI is a number than it is converted to int
				i = stoi(strI);
			}
			else { // strI is not a number
				while (isNum(strI) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strI); // gets user input					
				}
				i = stoi(strI); // converts strI to integer
			}
			cout << endl;
			cout << "Enter vertex j being pointed at by i: ";
			getline(cin >> ws, strJ); // allows spaces
			if (isNum(strJ)) { // if strJ is a number than it is converted to int
				j = stoi(strJ);
			}
			else { // strJ is not a number
				while (isNum(strJ) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strJ); // gets user input					
				}
				j = stoi(strJ); // converts strJ to integer
			}
			if (graph1.HasEdge(i, j) == true) { // Checks if there is an edge from vertex i to vertex j
				cout << "There is an edge between vertices " << i << " and " << j << endl;
			}
			else {
				cout << "There is not an edge between vertices " << i << " and " << j << endl;
			}
			break;
		case 4:
			cout << "Enter vertex i: ";
			getline(cin >> ws, strI); // allows spaces
			if (isNum(strI)) { // if strI is a number than it is converted to int
				i = stoi(strI);
			}
			else { // strI is not a number
				while (isNum(strI) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strI); // gets user input					
				}
				i = stoi(strI); // converts strI to integer
			}
			cout << endl;
			edges = graph1.OutEdges(i); // Gathers all of the out edges for vertex i and stores them in the 'edges' vector
			if (edges.empty() == true) {
				cout << "There are no out edges for vertex " << i << endl;
			}
			else { // 'edges' vector is not empty
				cout << "Out Edges: " << endl;
				for (int k = 0; k < edges.size(); k++) { // Iterates through the entire 'edges' vector
					if (graph1.HasEdge(i, edges.at(k))) { // checks if the edge exists from i to its respective outEdges for verification
						cout << "The out edge from " << i << " to " << edges.at(k) << " exists" << endl;
					}
					else {
						cout << "The out edge does not exist" << endl << endl;
					}
				}
			}
			break;
		case 5:
			cout << "Enter vertex i: ";
			getline(cin >> ws, strI); // allows spaces
			if (isNum(strI)) { // if strI is a number than it is converted to int
				i = stoi(strI);
			}
			else { // strI is not a number
				while (isNum(strI) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strI); // gets user input					
				}
				i = stoi(strI); // converts strI to integer
			}
			cout << endl;
			edges = graph1.InEdges(i); // Gets all of the inEdges of vertex i and stores them in the 'edges' vector
			if (edges.empty() == true) {
				cout << "There are no in edges for vertex " << i << endl;
			}
			else {
				cout << "In Edges: " << endl;
				for (int k = 0; k < edges.size(); k++) { // Iterates through the entire 'edges' vector
					if (graph1.HasEdge(edges.at(k), i)) { // Checks all of the inEdges that point to i for verification
						cout << "The in edge from " << edges.at(k) << " to " << i << " exists" << endl;
					}
					else {
						cout << "The in edge doesn't exist" << endl << endl;
					}
				}
			}
			break;
		case 6: 
			cout << "Enter vertex i: ";
			getline(cin >> ws, strI); // allows spaces
			if (isNum(strI)) { // if strI is a number than it is converted to int
				i = stoi(strI);
			}
			else { // strI is not a number
				while (isNum(strI) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strI); // gets user input					
				}
				i = stoi(strI); // converts strI to integer
			}
			cout << endl;
			graph1.AddVertex(i); // Adds the vertex of value i to the graph
			if (graph1.HasVertex(i) == true) { // Checks if the graph has the vertex for verification
				cout << "Vertex successfully added" << endl;
			}
			break;
		case 7:
			cout << "Enter vertex i: ";
			getline(cin >> ws, strI); // allows spaces
			if (isNum(strI)) { // if strI is a number than it is converted to int
				i = stoi(strI);
			}
			else { // strI is not a number
				while (isNum(strI) == false) { // loops till number is input
					cout << "Enter a valid choice 1-6: ";
					getline(cin >> ws, strI); // gets user input					
				}
				i = stoi(strI); // converts strI to integer
			}
			cout << endl;
			try { // Try/catch statement for error thrown from removeVertex function
				graph1.RemoveVertex(i); // Removes vertex from the graph (and handles all in/out edges appropriately)
				if (graph1.HasVertex(i) == false) { // Checks that vertex is no longer in the graph for verification
					cout << "Vertex successfully removed" << endl;
				}
			}
			catch (string msg) {
				cout << msg << endl << endl; // Will output if the graph is empty and no vertex can be removed
			}
			break;
		case 8:
			graph1.PrintGraph(); // Prints the graph
			break;
		case 9: // case to exit main
			exit = true;
			break;
		default: // if the input is invalid
			cout << "Invalid input. Choose again" << endl << endl;
			break;
		}
	}
	return 0;
}
