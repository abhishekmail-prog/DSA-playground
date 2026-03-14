#include <iostream>
#include "include/array.h"
#include "include/linked_list.h"
#include "include/doubly_linked_list.h"
#include "include/stack.h"

int main()
{
	int choice, value;

	do {
		std::cout << "1. Array\n";
		std::cout << "2. Linked List\n";
		std::cout << "3. Doubly Linked List\n";
		std::cout << "4. Stack\n";
		std::cout << "5. Exit\n";
		std::cin >> choice;
		
		switch(choice) {
			case 1:
				arrayMenu();
				break;
			case 2:
				linkedListMenu();
				break;
			case 3:
				doublyLinkedListMenu();
				break;
			case 4: 
				stackMenu();
				break;
			case 5:
				std::cout << "Exiting DSA Playground. Goodbye!\n";
				break;
			default:
				std::cout << "Invalid choice! Try again.\n";
		}

	} while(choice != 5);

	return 0;
}
