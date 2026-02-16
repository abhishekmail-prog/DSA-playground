#include <iostream>
#include "../include/array.h"

/*
==================================================================================
Array Menu System
Author: Abhishek
Project: DSA Playground

Description: 
Provides a menu driven interface to perform common array operation like:

1. Find Maximum
2. Find Minimum
3. Reverse Array
4. Bubble Sort
5. Binary Search
6. Exit

Concepts used:
- Arrays
- Functions
- Loops
- Searching Algorithms
- Sorting Algorithms
==================================================================================
*/

void arrayMenu() {

	// size     -> number of elements in array
	// choice   -> user menu choice
	// maxVal   -> stores maximum element
	// minVal   -> sotres minimum element
	// b_search -> stores index returned by binary search

	int size, choice;
        int maxVal, minVal, b_search;

	//Take array size from user
        std::cout << "Enter size of the array: ";
        std::cin >> size;
	
	// Declare array with maximum capacity of 100 elements
        int arr[100];

	// Input array element from user
        for(int i = 0; i < size; i++) {
                std::cout << "arr[" << i << "]: ";
                std::cin >> arr[i];
        }

	// Display initial array
        printArray(arr, size);

	// Menu loop runs until user chooses Exit (6)
        do {
                putchar('\n');

		// Display menu options
                std::cout << "1. Find Max" << '\n';
                std::cout << "2. Find Min" << '\n';
                std::cout << "3. Reverese array" << '\n';
                std::cout << "4. Bubble Sort" << '\n';
                std::cout << "5. Binary Search (Only works for Sorted Arrays!)" << '\n';
                std::cout << "6. Exit" << '\n';
		
		// Take user choice
                std::cout << "Enter your choice: ";
                std::cin >> choice;
		
		// Validates input choice
	        if(choice > 5 || choice < 1) {
                        std::cout << "Invalid choice! Try again." << '\n';
                }
		
		// Perform operations based on your choice
                switch(choice) {
			
			// Find maximum element
                        case 1:
                                maxVal = findMax(arr, size);
                                std::cout << "Maximum element is: " << maxVal;
                                putchar('\n');
                                break;

			// Find minimum element
                        case 2:
                                minVal = findMin(arr, size);
                                std::cout << "Minimum element is: " << minVal;
                                putchar('\n');
                                break;

			// Reverse the Array
                        case 3:
                                reverseArray(arr, size);
                                putchar('\n');
                                std::cout << "Array after Reverse!" << '\n';
                                printArray(arr, size);
                                putchar('\n');
                                break;

			// Sort array using Bubble Sort
                        case 4:
                                bubbleSort(arr, size);
                                putchar('\n');
                                std::cout << "Array after Bubble Sort!" << '\n';
                                printArray(arr, size);
                                putchar('\n');
                                break;

			// Perform Binary Search (array must be sorted)
                        case 5:
                                b_search = binarySearch(arr, size);
                                std::cout << "Element found at index:  " << b_search << '\n';
                                putchar('\n');
                                break;

			// Exiting option
			case 6:
				std::cout << "Exiting Program...\n";
				break;

			// Invalid input handler
                        default:
                                std::cout << "Invlaid option!\n";

                }

        } while(choice != 6);
}


/*
==================================================================================
Function: printArray
Description:
Prints all elements of the array.

Time Complexity: O(n)
Space Complexity: O(1)
==================================================================================
*/

void printArray(int arr[], int size){

        std::cout << "The array: ";

        for(int i = 0; i < size; i++) {
                std::cout << arr[i] << " ";
        }

        putchar('\n');
}
/*
==================================================================================
Function: findMax
Description: 
Finds and returns the maximum element in the array.

Algorithm:
Linear traversal and compare elements.

Time Complexity: O(n)
Space Complexity: O(1)
==================================================================================
*/

int findMax(int arr[], int size) {

        int maxVal = arr[0];

        for(int i = 1; i < size; i++) {
                if(maxVal < arr[i]) {
                        maxVal = arr[i];
                }
        }

        return maxVal;
}

/*
==================================================================================
Function: findMin
Description: 
Finds and returns the maximum element in the array.

ALgorithm:
Linear traversal and compare elements.

Time Complexity: O(n)
Space Complexity: O(1)
==================================================================================
*/

int findMin(int arr[], int size) {

        int minVal = arr[0];

        for(int i = 1; i < size; i++) {
                if(minVal > arr[i]) {
                        minVal = arr[i];
                }
        }

        return minVal;
}

/*
==================================================================================
Function: reverseArray
Description:
Reverse the array using temporary array.

Example:
Input:  1 2 3 4
Output: 4 3 2 1

Time Complexity: O(n)
Space Complexity: O(n)
==================================================================================
*/

void reverseArray(int arr[], int size) {
	
	// Temporary array to store reversed elements
        int temp[size];

	// Store elements in reverse order
        for(int i = 0; i < size; i++) {
                temp[i] = arr[size - i - 1];
        }

	// Copy back to original array
        for(int i = 0; i < size; i++) {
                arr[i] = temp[i];
        }       
}

/*
==================================================================================
Function: bubbleSort
Description:
Sorts the array using Bubble Sort algorithm.

Algorithm:
Repeatedly swap adjacent elements is they are in 
wrong order.

Time Complexity: O(n^2)
Space Complexity: O(1)
==================================================================================
*/

void bubbleSort(int arr[], int size) {

        int temp = 0;

        for(int i = 0; i < size - 1; i++) {
                for(int j = 0; j < size - i - 1; j++) {
			
			// Swap if elements are in wrong order
                        if(arr[j] > arr[j + 1])
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}

/*
==================================================================================
Function: binarySearch
Description:
Searches for an element using Binary Search.

IMPORTANT:
Array must be sorted before calling this function.

Returns:
Index of element if found
-1 if not found

Time Complexity: O(log n)
Space ComplexityL O(1)
==================================================================================
*/

int binarySearch(int arr[], int size) {
	
	int key;
	
	// Takes element to search
	std::cout << "Enter element you want to search: ";
	std::cin >> key;

	int low = 0, high = size - 1;

	while(low <= high) {

		int mid = (low + high) / 2;

		if(arr[mid] == key) {
			return mid;
		}
		else if(arr[mid] > key) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	
	// Element not found
	return -1;
}
