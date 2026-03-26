#include <iostream>
#include "../include/queue.h"

void queueMenu() {
	
	int choice, size;
	int newItem, removedItem;
	int top = -1, int front = -1;
	int value;

	Queue* queue = nullptr;

	do {
		std::cout << "1. Create Queue\n";
		std::cout << "2. isEmpty\n";
		std::cout << "3. isFull\n";
		std::cout << "4. Push\n";
		std::cout << "5. Pop\n";
		std::cout << "6. Peek\n";
		std::cout << "7. Free Stack\n";
		std::cout << "8. Exit\n";

		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch(choice) {
			case 1:
				std::cout << "Enter size: ";
				std::cin >> size;
				queue = createQueue(size);
				std::cout << "Queue sucessfully created.\n";

			case 2:
				if(queue = nullptr) {
					std::cout << "Create queue first!\n";
				}
				else {
					if(isEmpty(queue)) {
						std::cout << "Yes! The queue is Empty\n";
					}
					else {
						"No! The stack is not empty!\n";
					}
				}


		}
	}
}
