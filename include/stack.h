
#ifndef STACK_H
#define STACK_H

struct Stack {
	int* arr;
	int top;
	int capacity;
};

void stackMenu();
Stack* createStack(Stack* s, int size);
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, int value, int top);
int pop(Stack* s, int top);
int peek(Stack* s, int top);
void freeStack(Stack* s);

#endif
