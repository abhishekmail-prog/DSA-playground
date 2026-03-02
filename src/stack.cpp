#include <iostream>
#include "../include/stack.h"

void stackMenu() {

	int choice;
	int size;
	int poppedValue;
	int peekValue;
	int top = -1;
	Stack* stack;
	do {
		std::cout << "1. Create Stack\n";
		std::cout << "2. isEmpty\n";
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
				stack = createStack(stack, size);
				break;
			case 2:
				if(isEmpty(stack)) {
					std::cout << "Yes! The stack is Empty.\n";
				}
				else {
					std::cout << "No! The stack is not Empty.\n";
				}
				break;
			case 3:
				if(isFull(stack)) {
					std::cout << "Yes! THe stack is Full.\n";
				}
				else {
					std::cout << "No! The stack is not rmpty.\n";
				}
				break;
			case 4:
				push(stack, size, top);
				break;
			case 5:
				poppedValue = pop(stack, top);
				std::cout << poppedValue << "sucessfully poppoed\n";
				break;
			case 6:
				peekValue = peek(stack, top);
				std::cout << "Top element is: " << peekValue; 
				break;
			case 7:
				freeStack(stack);
				break;
			default:
				std::cout << "Invalid choice! Try again.\n";
		}
	} while(choice != 8);
}

Stack* stack(Stack* s, int size) {
	Stack* s = new Stack;
	s->capacity = size;
	s->top = -1;
	s->arr = new int[size];

	return s;
}

bool isEmpty(Stack* s) {
	return (s->top == -1);
}

bool isFull(Stack* s) {
	return (s->top == s->capacity - 1);
}

void push(Stack* s, int value, int top) {
	
	if(isFull) {
		std::cout << "Stack Overflow\n";
		return;
	}

	s->top++;
	s->arr[top] = value;

	std::cout << value << " pushed successfully\n";
}

int pop(Stack* s, int value, int top) {
	if(isEmpty) {
		std::cout << "Stack Overflow\n";
		return -1;
	}

	int poppedValue = s->arr[top];
	s->top--;

	return poppedValue;
}

int peek(Stack* s, int top) {
	
	if(isEmpty(s)) {
		std::cout << "Stack is Empty\n";
		return -1;
	}

	return s->arr[s->top];
}

void freeStack(Stack* s) {
	delete s->arr;
	delete s;
}
