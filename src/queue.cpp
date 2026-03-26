#include <iostream>
#include "../include/queue.h"

void queueMenu() {
	
	int choice, size;
	int newItem, removedItem;
	int rear = -1, int front = -1;
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
				break;

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
				break;

			case 3:
				if(queue == nullptr) {
					std::cout << "Create queue first!\n";
				}
				else {
					if(isFull(queue)) {
						std::cout << "Yes! The queue is Full!\n";
					}
					else {
						std::cout << "No! THe queue is not Full!\n";
					}
				}
				break;

			case 4:
				if(queue == nullptr) {
					std::cout << "Create queue first!\n";
				}
				else {
					std::cout << "Enter element to be inserted: ";
					std::cin >> value;
					enqueue(queue, value, front, rear);
				}
				break;

			case 5:
				if(queue == nullptr) {
					std::cout << "Create queue first!\n";
				}
				else {
					removedItem = dequeue(queue, front, value);
					std::cout << removed Item << "sucessfully removed from the queue\n";
				}
				break;

			case 6:
				if(stack == nullptr) {
					std::cout << "Create queue first!\n";
				}
				else {
					peekValue = peek(queue, front);
				}
				break;

			case 7:
				if(queue == nullptr) {
					std::cout << "Create queue first!\n";
				}
				else {
					freeQueue(queue);
					queue = nullptr;

					if(queue == nullptr) {
						std::cout << "Queue memory freed!\n";
					}
				}
				break;

			case 8:
				std::cout << "Returning to Main Menu...\n\n";
				break;

			default:
				std::cout << "Invlaid choice! Try again.\n\n";
		}
	} while(choice != 8);
}
