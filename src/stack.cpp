/*
====================================================================================
Stack Implementation (Array-Based)
Author: Abhishek
Project: DSA Playground

Description:
Provides a menu-driven stack implemenetation using arrays.

A Stack follows LIFO (Last In First Out) principle.

Key Components:
1. Array to store elements
2. Top pointer to track top element
3. Capacity to limit stack size

Opeartions Implemented:
1. Create Stack
2. Check if Empty
3. Check if Full
4. Push Element
5. Pop Element
6. Peek Element
7. Free Stack Memory

====================================================================================
*/

#include <iostream>
#include "../include/stack.h"

/*
====================================================================================
Stack Menu

Provides a menu-driven interface allowing users
to perform operations on the stack.

The menu continues until the user selects Exit.
====================================================================================
*/

void stackMenu() {

	int choice, size;
	int poppedValue, peekValue;
	int top = -1, value;

	Stack* stack = nullptr;

	do {
		std::cout << "1. Create Stack\n";
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
				stack = createStack(size);
				std::cout << "Stack sucessfully Created!\n\n";
				break;

			case 2:
				if(stack == nullptr) {
					std::cout << "Create stack first!\n\n";
				}
				else {
					if(isEmpty(stack)) {
						std::cout << "Yes! The stack is Empty.\n\n";
					}
					else {
						std::cout << "No! The stack is not Empty.\n\n";
					}
				}
				break;

			case 3:
				if(stack == nullptr) {
					std::cout << "Create stack first!\n\n";
				}
				else {
					if(isFull(stack)) {
						std::cout << "Yes! The stack is Full.\n\n";
					}
					else {
						std::cout << "No! The stack is not Full.\n\n";
					}
				}
				break;

			case 4:
				if(stack == nullptr) {
					std::cout << "Create stack first!\n\n";
				}
				else {
					std::cout << "Enter element to be pushed: ";
					std::cin >> value;
					push(stack, value);
				}
				break;

			case 5:
				if(stack == nullptr) {
					std::cout << "Create stack first!\n\n";
				}
				else {
					poppedValue = pop(stack);
					std::cout << poppedValue << " sucessfully popped\n\n";
				}
				break;

			case 6:
				if(stack == nullptr) {
					std::cout << "Create stack first!\n\n";
				}
				else {
					peekValue = peek(stack);
					std::cout << "Top element is: " << peekValue << "\n\n"; 
				}
				break;

			case 7:
				if(stack == nullptr) {
					std::cout << "Create stack first!\n";
				}
				else {
					freeStack(stack);
					stack = nullptr;

					if(stack == nullptr) {
						std::cout << "Stack memory freed Sucessfully\n\n";
					}
				}
				break;

			case 8:
				std::cout << "Returning to Main Menu...\n\n";
				break;

			default:
				std::cout << "Invalid choice! Try again.\n\n";
		}
	} while(choice != 8);
}

/*
====================================================================================
Create Stack

Allocates memory for a stack and initializes:
	- capacity
	- top index
	- internal array

Returns:
	Pointer to the created stack
====================================================================================
*/

Stack* createStack(int size) {
	Stack* s = new Stack;
	s->capacity = size;
	s->top = -1;
	s->arr = new int[size];

	return s;
}

/*
====================================================================================
Check is Stack is Empty

Condition: 
	top == -1

Returns:
	true  -> stack is empty
	false -> stack has elements
====================================================================================
*/

bool isEmpty(Stack* s) {
	return (s->top == -1);
}

/*
====================================================================================
Check if Stack is Full

Condition: 
	top == capacity - 1

Returns: 
	true  -> stack is full
	false -> stack has space
====================================================================================
*/

bool isFull(Stack* s) {
	return (s->top == s->capacity - 1);
}

/*
====================================================================================
Push Operation

Inserts an element at the top of the stack.

Steps:
1. Check overflow condition
2. Increment top
3. Insert element

====================================================================================
*/

void push(Stack* s, int value) {
	if(isFull(s)) {
		std::cout << "Stack Overflow\n\n";
		return;
	}

	s->top++;
	s->arr[top] = value;

	std::cout << value << " pushed successfully\n\n";
}

/*
====================================================================================
Pop Operation

Removes and returns the top element.

Steps:
1. Check underflow condition
2. Store top element
3. Decrement top

Returns:
	popped element OR -1 if empty
====================================================================================
*/

int pop(Stack* s) {
	if(isEmpty(s)) {
		std::cout << "Stack Underflow\n\n";
		return -1;
	}

	int poppedValue = s->arr[top];
	s->top--;

	return poppedValue;
}

/*
====================================================================================
Peek Operation

Returns the top element without removing it.

Returns:
	top element OR -1 if empty
====================================================================================
*/

int peek(Stack* s) {
	if(isEmpty(s)) {
		std::cout << "Stack is Empty\n\n";
		return -1;
	}

	return s->arr[top];
}

/*
====================================================================================
Free Stack Memory

Deallocates:
	- internal array
	- stack structure

Prevents memory leaks
====================================================================================
*/

void freeStack(Stack* s) {
	delete[] s->arr;
	delete s;
}
