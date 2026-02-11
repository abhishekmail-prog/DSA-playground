#include <iostream>
#include "../include/linked_list.h"

Node* insertAtHead(Node* head, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;

	return newNode;
}

Node* insertAtTail(Node* head, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = nullptr;

	if (!head) 
		return newNode;
	
	Node* temp = head;
	while(temp->next) {
		temp = temp->next;
	}

	return head;
}

Node* deleteByValue(Node* head, int value) {
	if(!head)
		return nullptr;
	
	if (head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;

		return head;
	}

	Node* cur = head;
	while(cur->next && cur->next->data != value) {
		cur = cur->next;
	}

	if(cur->next) {
		Node* temp = cur->next;
		cur->next = temp->next;

		delete temp;
	}

	return head;
}

bool search(Node* head, int value) {
	while(head) {
		if(head->data == value)
			return true;

		head = head->next;
	}
	return false;
}

int length(Node* head) {
	int count = 0;
	while(head) {
		count++;
		head = head->next;
	}

	return count;
}

void display(Node* head) {
	if(!head) {
		std::cout << "List is empty\n";
		return;
	}

	while(head) {
		std::cout << head->data << " -> ";
		head = head->next;
	}

	std::cout << "NULL\n";
}
