
#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DNode {
	DNode* prev;
	int data;
	DNode* next;

	DNode(int value);
};

void doublyLinkedListMenu();
DNode* insertAtBegining(DNode* head, int value);
DNode* insertAtEnd(DNode* head, int value);
DNode* deleteByValue(DNode* head, int value);
int searchElement(DNode* head, int value);
int lengthOfList(DNode* head);
void display(DNode* head);

#endif
