#include <iostream>
#include "../include/stack.h"

void stackMenu() {

	int choice;
	int size;
	Stack* stack;
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
				std::cout << "Enter size: ";	
				std::cin >> size;
				stack = createStack(size):
				break;
			case 2:
				if(isEmpty()) {
					std::cout << "Yes! The stack is Empty.\n";
				}
				else {
					std::cout "No! The stack is not Empty.\n";
				}
				break;
			case 3:
				if(isFull()) {
					std::cout << "Yes! THe stack is Full.\n";
				}
				else {
					std::cout << "No! The stack is not rmpty.\n";
				}
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

Stack* stack(int size) {
	Stack* s = new Stack;
	s->capacity = size;
	s->top = -1;
	s->arr = new int[size];

	return s;
}

bool isEmpty() {
	return (s->top == -1);
}

bool isFull() {
	return (s->top == s->capacity - 1);
}



