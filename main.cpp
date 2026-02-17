#include <iostream>
#include "../include/array.h"
#include "../include/linked_list.h"

int main()
{

	Node* head = nullptr;
	int choice, value;

	do {
		std::cout << "1. Array\n";
		std::cout << "2. Linked List\n";
		std::cout << "3. Exit\n";
		std::cin >> choice;
		
		switch(choice) {
			case 1:
				arrayMenu();
				break;
			case 2:
				linkedListMenu();
				break;
		}

	} while(choice != 3);

	/*do {

		std::cout << "--- LINKED LIST MENU ---\n";
		std::cout << "1. Insert at Head\n";
		std::cout << "2. Insert at Tail\n";
		std::cout << "3. Delete by value\n";
		std::cout << "4. Search\n";
		std::cout << "5. Display\n";
		std::cout << "6. Length\n";
		std::cout << "7. Exit\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;

		switch(choice) {
			case 1:
				std::cout << "Enter value: ";
				std::cin >> value;
				head = insertAtHead(head, value);
				break;

			case 2:	
				std::cout << "Enter value: ";
				std::cin >> value;
				head = insertAtTail(head, value);
				break;

			case 3:
				std::cout << "Enter value: ";
				std::cin >> value;
				head = deleteByValue(head, value);
				break;

			case 4:
				std::cout << "Enter value: ";
				std::cin >> value;
				std::cout << (search(head, value) ? "Found\n" : "Not Found\n");
				break;

			case 5:
				display(head);
				break;

			case 6:
				std::cout << "Length: " << length(head) << '\n';
				break;
		}

	} while(choice != 7);*/

	/*int size, choice;
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

        } while(choice != 6);*/

	return 0;
}
