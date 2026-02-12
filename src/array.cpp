#include <iostream>
#include "../include/array.h"

void arrayMenu() {
	int size, choice;
        int maxVal, minVal, b_search;

        std::cout << "Enter size of the array: ";
        std::cin >> size;

        int arr[100];

        for(int i = 0; i < size; i++) {
                std::cout << "arr[" << i << "]: ";
                std::cin >> arr[i];
        }
        printArray(arr, size);

        do {
                putchar('\n');
                std::cout << "1. Find Max" << '\n';
                std::cout << "2. Find Min" << '\n';
                std::cout << "3. Reverese array" << '\n';
                std::cout << "4. Bubble Sort" << '\n';
                std::cout << "5. Binary Search (Only works for Sorted Arrays!)" << '\n';
                std::cout << "6. Exit" << '\n';

                std::cout << "Enter your choice: ";
                std::cin >> choice;

                if(choice > 5 || choice < 1) {
                        std::cout << "Invalid choice! Try again." << '\n';
                }

                switch(choice) {
                        case 1:
                                maxVal = findMax(arr, size);
                                std::cout << "Maximum element is: " << maxVal;
                                putchar('\n');
                                break;
                        case 2:
                                minVal = findMin(arr, size);
                                std::cout << "Minimum element is: " << minVal;
                                putchar('\n');
                                break;
                        case 3:
                                reverseArray(arr, size);
                                putchar('\n');
                                std::cout << "Array after Reverse!" << '\n';
                                printArray(arr, size);
                                putchar('\n');
                                break;
                        case 4:
                                bubbleSort(arr, size);
                                putchar('\n');
                                std::cout << "Array after Bubble Sort!" << '\n';
                                printArray(arr, size);
                                putchar('\n');
                                break;
                        case 5:
                                b_search = binarySearch(arr, size);
                                std::cout << "Element found at index:  " << b_search << '\n';
                                putchar('\n');
                                break;
                        default:
                                std::cout << "Invlaid option!";

                }

        } while(choice != 6);
}

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
