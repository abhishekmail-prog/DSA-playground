#ifndef QUEUE_H
#define QUEUE_H

struct Queue {
	int *arr; // dynamic array
	int front;
	int rear;
	int capacity; // max size of queue
};

void queueMenu();
void createQueue(Queue* q);
void isEmpty(Queue* q);
void isFull(Queue* q);
void enqueue(Queue* q, int value, int front, int rear);
void dequeue(Queue* q, int front, int rear);
void peek(Queue* q, int front);
void displayQueue(Queue* q, int front, int rear);
void freeQueue(Queue* q);

#endif
