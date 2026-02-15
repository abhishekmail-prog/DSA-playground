#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
	int data;
	Node* next;
};

void linkedListMenu();
Node* insertAtHead(Node* head, int value);
Node* insertAtTail(Node* head, int value);
Node* deleteByValue(Node* head, int value);
bool search(Node* head, int value);
int length(Node* head);
void display(Node* head);
Node* reverseLinkedList(Node* head);

#endif
