#pragma once
#include <iostream>

using namespace std;

#ifndef SORTING // Include guards
#define SORTING

/*
	We used the GeeksForGeeks website sorting implementations provided in the module for help developing the different sorting algorithms
*/

void BubbleSort(int data[], int size) { // Bubble Sort Function
	for (int i = 0; i < size - 1; i++) { // Will iterate through the list the proper number of times needed to sort the array
		for (int j = 0; j < size - 1 - i; j++) { // Will iterate through the list again but can ignore the most recent index (i), as that value will be in its sorted position
			if (data[j] > data[j + 1]) {
				swap(data[j], data[j + 1]); // If the data at the index is greater than the data at the next index, we need to swap the values
			}
		}
	}
};

void InsertionSort(int data[], int size) { // Insertion Sort Function
	int insertionKey, j;
	for (int i = 0; i < size; i++) { // Will iterate through the entire unsorted array
		insertionKey = data[i]; // Sets the insertion value equal to the data value in the unsorted array
		j = i - 1;
		while (j >= 0 && data[j] > insertionKey) { // Checks if the 'j' counter is greater than or equal to zero and that the value in the unsorted array is greater than the insertion value (requires data shifting for insertion)
			data[j + 1] = data[j]; // Moves the data in the array forward one index so that the 'key' insertion value can be placed in its proper location
			j = j - 1;
		}
		data[j + 1] = insertionKey; // Inserts the 'key' insertion value at its proper location
	}
};

int Partition(int data[], int bottom, int top) { // Partition Function for QuickSort Implementation
	int pivot = data[top]; // Sets the pivot to be the last item in the array
	int i = bottom - 1; // Starts the first counter one index before the first item in the array
	for (int j = bottom; j < top; j++) { // For loop iterates through the data array
		if (data[j] < pivot) { // Checks if the data value is less than the pivot
			i++; // Increments i counter
			swap(data[i], data[j]); // Swaps the two data values if the data we are looking at (j) is less than the pivot value
		}
	}
	swap(data[i + 1], data[top]); // Swaps the value one index greater than counter i's location with the pivot
	return (i + 1); // Returns index of where the pivot is now located

	/*
	After the partition function executes, the pivot will be in its proper location with all of the unsorted values to the left of the pivot being less than the pivot
	and all of the unsorted values to the right of the pivot being greater than the pivot.  The fact that the values on either side of the pivot may not be sorted is
	not important, as the recursive function calls within QuickSort will continue to divide the unsorted array into smaller lists until the entire array is sorted.
	*/
};

void QuickSort(int data[], int bottom, int top) { // Quick Sort Function
	if (bottom < top) { // Checks that the bottom index passed to QuickSort is less than the top index passed (exit case for recursion)
		int part = Partition(data, bottom, top); // Finds the index of the pivot of the array passed to data
		QuickSort(data, bottom, part - 1); // Recursive call to the part of the data array from the bottom index to one less than the pivot's index
		QuickSort(data, part + 1, top); // Recursive call to the part of the data array from one greater than the pivot's index to the top index
	}
};

void CountSort(int data[], int size) { // Count Sort Function
	int sizeCount = 2 * size; // Gets the size of the count array (all possible values that could be in the unsorted array)
	int* count = new int[sizeCount]; // Creates new count array (using pointer to the array) of integers of size 'sizeCount'
	int* output = new int[size]; // Creates new output array (using pointer to the array) of integers of the same size as the unsorted array

	for (int i = 0; i < sizeCount; i++) { // Initializes all counts in the count array to be 0
		count[i] = 0;
	}

	for (int i = 0; i < size; i++) { // Iterates through the data array and adds one at the index value in the count array that matches the data value in the unsorted array
		++count[data[i]];
	}

	for (int i = 1; i < sizeCount; i++) { // Iterates through the count array (starting at index 1) that generates the "running sum" by adding the value at the previous index to the value at the current index
		count[i] = count[i] + count[i - 1];
	}

	for (int i = 0; i < size; i++) { // Iterates through the output array and sets it equal
		output[count[data[i]] - 1] = data[i]; // Sets the output array value (at the index of one less than the value in the count array at the proper data[i] index location) to be equal to the value in the unsorted array
		--count[data[i]]; // Decrements the value in the 'count' array at the proper data[i] index value
	}

	for (int i = 0; i < size; i++) { // Iterates through the data and output arrays, replacing the unsorted values in the 'data' array with the sorted values from the 'output' array
		data[i] = output[i];
	}
}

void RadixSort(int data[], int size) { // Radix Sort Function
	int maxValue = data[0]; // Sets the max value equal to the first item in the unsorted array
	int outputSize = 2 * size; // Sets the 'output' array size equal to all possible values in the unsorted array
	int digit = 1; // Sets the digit equal to 1 (the ones place)
	int* output = new int[outputSize]; // Creates new output array (using pointer to the array) of integers of size 'outputSize'
	for (int i = 0; i < size; i++) { // Iterates through the unsorted array to find the maximum data value
		if (data[i] > maxValue) {
			maxValue = data[i]; // Replaces maxValue if the data value we are looking at is greater than the current maxValue
		}
	}
	while (maxValue / digit > 0) { // Will iterate until we get through all of the digits (exits when digit place we want to compare is beyond the size of the maxValue)
		int* count = new int[outputSize]; // Creates new count array (using pointer to the array) of integers of size 'outputSize'
		for (int i = 0; i < outputSize; i++) { // Initializes all values in the count array to be 0
			count[i] = 0;
		}
		for (int i = 0; i < size; i++) { // Iterates through the entire unsorted array
			count[data[i] / digit % outputSize]++; // Increments the 'count' array value at the index of the digit that we are sorting by
		}
		for (int i = 1; i < outputSize; i++) { // Iterates through the count array (starting at index 1) that generates the "running sum" by adding the value at the previous index to the value at the current index
			count[i] += count[i - 1];
		}
		for (int i = size - 1; i >= 0; i--) { // Begins inputing the "sorted" data back into the array (starts at the end of the data array to maintain order)
			output[count[data[i] / digit % outputSize] - 1] = data[i]; // Sets the output array value (at the index of one less than the corresponding index for the digit of data[i] that we are sorting) equal to the value in our unsorted array
			--count[(data[i] / digit) % outputSize]; // Decrements the value in the 'count' array at the corresponding index for the digit of data[i] that we are sorting
		}
		for (int i = 0; i < size; i++) { // Iterates through the data and output arrays, replacing the unsorted values in the 'data' array with the sorted values from the 'output' array
			data[i] = output[i];
		}
		digit = digit * 10; // Multiplies digit by 10 to move us on to the next digit
	}
}

void PrintArray(int data[], int size) { // Function for printing the array
	for (int i = 0; i < size; i++) { // Iterates through the entire data array
		cout << data[i] << endl; // Outputs the data in the array
	}
}

#endif