#include <iostream>
#include "../include/queue.h"

void queueMenu() {
	
	int choice, size;
	int rear = -1, front = -1;
	int value, peekValue;

	Queue* queue = nullptr;

	do {
		std::cout << "1. Create Queue\n";
		std::cout << "2. isEmpty\n";
		std::cout << "3. isFull\n";
		std::cout << "4. Enqueue\n";
		std::cout << "5. Dequeue\n";
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
				if(queue == nullptr) {
					std::cout << "Create queue first!\n";
				}
				else {
					if(isEmpty(queue)) {
						std::cout << "Yes! The queue is Empty\n";
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
					dequeue(queue, front, value);
				}
				break;

			case 6:
				peekValue = peek(queue, front);

				if(peekValue == -1) {
					std::cout << "Create queue first!\n";
				}
				else {
					std::cout << peekValue << " is the peek value.\n";
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

Queue* createQueue(int size) {
	Queue* q = new Queue;
	q->capacity = size;
	q->front = -1;
	q->rear = -1;
	q->arr = new int[size];

	return q;
}

bool isEmpty(Queue* q) {
	return (q->front == -1);
}

bool isFull(Queue* q) {
	return(q->rear == q->capacity - 1);
}

void enqueue(Queue* q, int value, int front, int rear) {
	
	if(isFull(q)) {
		std::cout << "Queue Overflow!\n";
		return;
	}
	if(q->front == -1) { q->front = 0; }

	q->arr[++rear] = value;
	
	std::cout << value << " inserted sucessfully!\n";
}

void dequeue(Queue* q, int front, int rear) {
	
	if (isEmpty(q)) {
		std::cout << "Queue Underflow\n";
	} 
	
	std::cout << front << " removed sucessfully!\n";
	front++;
}

int peek(Queue* q, int front) {
	
	if(isEmpty(q)) {
		std::cout << "Stack is empty!\n";
		return -1;
	}

	return q->arr[front];
}

void freeQueue(Queue *q) {
	delete[] q->arr;
	delete q;
}
