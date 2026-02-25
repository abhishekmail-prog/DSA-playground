
#ifndef STACK_H
#define STACK_H

struct Stack {
	int* arr;
	int top;
	int capacity;
};

void stackMenu();
Stack* createStack(int size);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void freeStack(Stack* s);

#endif
