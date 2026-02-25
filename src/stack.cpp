#include <iostream>
#include "../include/stack.h"

void stackMenu() {

	int choice;
	do {
		std::cout << "1. Create Stack\n";
		std::cout << "2. isEmpty\n"
		std::cout << "3. isFull\n";
		std::cout << "4. Push\n";
		std::cout << "5. Pop\n";
		std::cout << "6. Peek\n";
		std::cout << "7. freeStack\n";

		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch(choice) {
			case 1: 
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				std::cout << "Invalid choice! Try again.\n";
		}
	} while(choice != 8);
}
