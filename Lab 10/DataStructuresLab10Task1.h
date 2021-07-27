#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

#ifndef Graph_Class
#define Graph_Class
class Vertex {
public:
	int value; // value in the vertex
	Vertex* edge; // pointer to linked list of edges
	Vertex() { // constructor
		value = -1;
		edge = nullptr;
	}

	Vertex(int val) { // constructor for new vertex with value
		value = val;
		edge = nullptr;
	}
};

class Graph {
private:
	Vertex* data; // pointer to array
	int count; // number of vertices
	int graphSize; // size of array
public:
	Graph() { // default constructor
		graphSize = 50;
		count = 0;
		data = new Vertex[graphSize]; // new array of graphSize
	}

	Graph(int size) { // overloaded constructor
		graphSize = size;
		count = 0;
		data = new Vertex[graphSize]; // new array of graphSize
	}

	~Graph() { // destructor
		delete[] data;
	}

	bool IsFull() { // if graph is full
		if (count == graphSize) { // if count is same as graphSize
			return true;
		}
		else {
			return false;
		}
	}

	bool IsEmpty() { // if graph is empty
		if (count == 0) { // nothing in graph
			return true;
		}
		else {
			return false;
		}
	}

	bool HasVertex(int i) { // if there is a vertex of the value passed
		for (int k = 0; k < graphSize; k++) { // finds the value if it exists
			if (data[k].value == i) {
				return true;
			}
		}
		return false;
	}

	void AddVertex(int i) { // add vertex to array
		if (IsFull()) {
			cout << "The graph is full. No vertex can be added" << endl;
		}
		else {
			int index = 0;
			Vertex* item = new Vertex(i); // creates new vertex pointer
			while (data[index].value != -1) { // finds next empty spot
				index = index + 1;
			}
			data[index] = *item; // adds item to data array
			count = count + 1;
		}
	}

	int RemoveVertex(int i) { // remove vertex from the array
		if (IsEmpty()) {
			cout << "The graph is empty. No vertices can be removed" << endl;
		}
		else {
			if (HasVertex(i)) { // if the vertex exists
				vector<int> inEdges = InEdges(i); // stores in edges
				vector<int> outEdges = OutEdges(i); // stores out edges
				if (inEdges.empty() && outEdges.empty()) { // if there are no edges
					for (int k = 0; k < graphSize; k++) {
						if (data[k].value == i) { // if the array is at the vertex
							int retVal = data[k].value;
							data[k].value = -1; // remove the vertex
							count = count - 1;
							return retVal;
						}
					}
				}
				else if (inEdges.empty() && !outEdges.empty()) { // if there are out edges
					int index = 0;
					while (data[index].value != i) { // find the vertex
						index = index + 1;
					}
					Vertex* temp = &data[index]; // temp is the vertex
					Vertex* temp2 = temp->edge; // first item in linked list
					while (temp != nullptr) { // deletes all outedges from the i value
						temp = temp2->edge;
						delete temp2; // deletes from linked list
						temp2 = temp;
					}
					delete temp; // delete final value
					int retVal = data[index].value;
					data[index].edge = nullptr; // remove from array
					data[index].value = -1; // remove from array
					count = count - 1;
					return retVal;
				}

				else if (!inEdges.empty() && outEdges.empty()) { // if there are in edges but no out edges
					int index = 0;
					int k = 0;
					Vertex* temp = &data[index]; // temp at beginning of array
					Vertex* temp2;
					while(k != inEdges.size()){ // until reaches end of in edges
						if (data[index].value == inEdges.at(k)) {
							temp = &data[index]; // temp is value with i as out edge
							temp2 = temp->edge;
							while (temp != nullptr) { // finds i in the linked list
								if (temp2->value == i) {
									temp->edge = temp2->edge; // removes i from linked list
									delete temp2;
									break;
								}
								temp = temp2; // iterate if not i
								temp2 = temp2->edge;
							}
							k = k + 1; // next in vector
							index = index + 1; // next in array
						}
						else {
							index = index + 1;
						}
					}
					index = 0;
					while (data[index].value != i) { // find where i is in array
						index = index + 1;
					}
					int retVal = data[index].value;
					data[index].value = -1; // remove from array
					count = count - 1;
					return retVal;
					
				}

				// above to cases put together for when there are both out and in edges for the vertex
				else if (!inEdges.empty() && !outEdges.empty()) {
					int index = 0;
					int k = 0;
					while (data[index].value != i) {
						index = index + 1;
					}
					Vertex* temp = &data[index];
					Vertex* temp2 = temp->edge;
					while (temp != nullptr) {
						temp = temp2->edge;
						delete temp2;
						temp2 = temp;
					}
					delete temp;
					data[index].edge = nullptr;

					index = 0;
					temp = &data[index];
					while (k != inEdges.size()){
						if (data[index].value == inEdges.at(k)) {
							temp = &data[index];
							temp2 = temp->edge;
							while (temp != nullptr) {
								if (temp2->value == i) {
									temp->edge = temp2->edge;
									delete temp2;
									break;
								}
								temp = temp2;
								temp2 = temp2->edge;
							}
							k = k + 1;
							index = index + 1;
						}
						else {
							index = index + 1;
						}
					}
					index = 0;
					while (data[index].value != i) {
						index = index + 1;
					}
					int retVal = data[index].value;
					data[index].value = -1;
					count = count - 1;
					return retVal;
				}
			}
			else { // throw error if the value isn't in the graph
				throw string("The value is not a vertex in the graph");
			}
		}

	}

	void AddEdge(int i, int j) { // add the edge
		if (HasVertex(i) && HasVertex(j)) { // if the passed values are in graph
			if (!HasEdge(i, j)) { // if there is no edge
				int index = 0;
				while (data[index].value != i) { // finds i in the array
					index = index + 1;
				}
				Vertex* item = new Vertex(j); // creates new j 
				Vertex* temp = &data[index];
				while (temp->edge != nullptr) { // finds end of linked list of edges from i
					temp = temp->edge;
				}
				temp->edge = item; // adds j to end of the linked list
			}
			else {
				cout << "The vertices already have an edge" << endl;
			}
		}
		else {
			cout << "One of the vertices doesn't exist in the graph" << endl << endl;
		}
	}

	void RemoveEdge(int i, int j) { // removing the edge from the graph
		if (HasVertex(i) && HasVertex(j)) { // if the values are in the graph
			if (HasEdge(i, j)) { // if there is an edge between the values
				int index = 0;
				while (data[index].value != i) { // find i in the array
					index = index + 1;
				}
				Vertex* temp = &data[index]; // temp pointing at the i value
				Vertex* temp2 = temp->edge; // advance into the linked list
				while (temp2 != nullptr) { // runs until end of the list
					if (temp2->value == j) { // if j is found
						temp->edge = temp2->edge; // removes j from the list
						delete temp2;
						break; // exit loop
					}
					temp = temp2; // iterate temp and temp2
					temp2 = temp2->edge;
				}
			}
			else {
				cout << "The vertices don't have an edge" << endl;
			}
		}
		else {
			cout << "One of the vertices doesn't exist in the graph" << endl << endl;
		}
	}

	bool HasEdge(int i, int j) { // if the edge exists in the graph
		if (HasVertex(i) && HasVertex(j)) { // if the passed values are in the graph
			int index = 0;
			while (data[index].value != i) { // finds the i value in the array
				index = index + 1;
			}
			Vertex* temp = &data[index]; // temp that points at the array at the index
			temp = temp->edge; // advance into the linked list
			if (temp != nullptr) { // if temp exists
				while (temp->edge != nullptr) { // runs until end of linked list
					if (temp->value == j) { // if edge exists
						return true;
					}
					temp = temp->edge; // advance through linked list
				}
				if (temp->value == j) { // if j is the final value
					return true;
				}
			}	
			return false;
		}
		else {
			cout << "One of the vertices doesn't exist in the graph" << endl << endl;
			return false;
		}
	}

	vector<int> OutEdges(int i) { // finds the outedges of the value passed
		vector<int> outEdges; // vector to hold the outedge values
		if (IsEmpty()) { // if the graph is empty
			cout << "The graph is empty" << endl;
			return outEdges;
		}
		else {
			if (HasVertex(i)) { // if the value passed is a vertex
				int index = 0;
				while (data[index].value != i) { // find the value passed in the array
					index = index + 1;
				}
				Vertex* temp = &data[index]; // create new temp at that index
				if (temp->edge == nullptr) { // if there isn't a linked list
					return outEdges;
				}
				else {
					while (temp->edge != nullptr) { // until the linked list ends
						outEdges.push_back(temp->edge->value); // add to vector
						temp = temp->edge;
					}
					if (temp->edge != nullptr) { // get the last value
						outEdges.push_back(temp->edge->value);
					}
					return outEdges;
				}
			}
			else { 
				return outEdges;
			}
		}
	}

	vector<int> InEdges(int i) { // returns list of the in edges
		vector<int> inEdges; // holds inedge values
		if (IsEmpty()) { // if empty
			cout << "The graph is empty" << endl;
			return inEdges;
		}
		else {
			if (HasVertex(i)) { // if the value passed exists
				Vertex* temp = &data[0];
				for (int index = 0; index < graphSize; index++) { // iterates through the array
					if (temp->edge != nullptr) { // if data at that spot has a linked list
						temp = temp->edge;
						while (temp != nullptr) { // runs until end of the linked list
							if (temp->value == i) { // if the value is in the list
								inEdges.push_back(data[index].value);
							}
							temp = temp->edge;
						}
					}
					if(index < graphSize - 1){
						temp = &data[index + 1];
					}
					
				}
				return inEdges;
			}
			else {
				return inEdges;
			}
		}
	}

	void PrintGraph() { // prints the values in the graph
		if (IsEmpty()) {
			cout << "The graph is empty" << endl << endl;
		}
		else {
			cout << "Graph:" << endl;
			for (int i = 0; i < graphSize; i++) { // iterates through the array
				if (data[i].value == -1) { // if the value is null
					cout << "NULL" << endl;
				}
				else {
					if (data[i].edge == nullptr) { // if there is no edges for the value
						cout << "Vertex: " << endl;
						cout << data[i].value << endl;
					}
					else { // printing the vertex and its out edges
						cout << "Vertex: " << endl;
						cout << data[i].value << "(";
						Vertex* temp = data[i].edge;
						while (temp->edge != nullptr) {
							cout << temp->value << ", ";
							temp = temp->edge;
						}
						cout << temp->value << ")" << endl << endl;
					}
				}
			}
			cout << endl;
		}
	}
};
#endif