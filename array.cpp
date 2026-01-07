#include <iostream>
#include "array.h"

void printArray(int arr[], int size){

        std::cout << "The array: ";

        for(int i = 0; i < size; i++) {
                std::cout << arr[i] << " ";
        }

        putchar('\n');
}

int findMax(int arr[], int size) {

        int maxVal = arr[0];

        for(int i = 1; i < size; i++) {
                if(maxVal < arr[i]) {
                        maxVal = arr[i];
                }
        }

        return maxVal;
}

int findMin(int arr[], int size) {

        int minVal = arr[0];

        for(int i = 1; i < size; i++) {
                if(minVal > arr[i]) {
                        minVal = arr[i];
                }
        }

        return minVal;
}

void reverseArray(int arr[], int size) {

        int temp[size];

        for(int i = 0; i < size; i++) {
                temp[i] = arr[size - i - 1];
        }
        for(int i = 0; i < size; i++) {
                arr[i] = temp[i];
        }       
}
void bubbleSort(int arr[], int size) {

        int temp = 0;

        for(int i = 0; i < size - 1; i++) {
                for(int j = 0; j < size - i - 1; j++) {
                        if(arr[j] > arr[j + 1])
                        {
                                temp = arr[j];
                                arr[j] = arr[j + 1];
                                arr[j + 1] = temp;
                        }
                }
        }
}
int binarySearch(int arr[], int size) {
	
	int key;

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

	return -1;
}
