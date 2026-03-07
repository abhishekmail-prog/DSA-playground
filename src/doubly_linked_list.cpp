/*
=====================================================================================
Doubly Linked List Implementation
Author: Abhishek
Project: DSA Playground

Description:
Provides a menu-driven Doubly Linked List to perform common operations.

A Doubly Linked List node contains:
1. Data
2. Pointer to previous node
3. Pointer to next node

Operations Implemented:
1. Insert At Begining
2. Insert At End
3. Delete By Value
4. Search Element
5. Find Length
6. Display List (Forward & Backward)

=====================================================================================
*/

#include <iostream>
#include "../include/doubly_linked_list.h"

/*
=====================================================================================
DNode Constructor

Initialized a doubly linked list node:
	- given value
	- previous pointer set to nullptr
	- next pointer set to nullptr
=====================================================================================
*/

DNode::DNode(int value) {
	prev = nullptr;
	data = value;
	next = nullptr;
}

/*
=====================================================================================
Doubly Linked List Menu

Provides a menu-driven interface allowing users
to perform operations on the doubly linked list.

The menu loops until the user selects Exit.
=====================================================================================
*/

void doublyLinkedListMenu() {

	int choice, value;
	DNode* head = NULL;

	do {
		std::cout << "\n1. Insert at Begining\n";
		std::cout << "2. Insert at End\n";
		std::cout << "3. Delete by Value\n";
		std::cout << "4. Search a element\n";
		std::cout << "5. Length of the list\n";
		std::cout << "6. Display the list\n";
		std::cout << "7. Exit\n";

		std::cout << "\nEnter a choice: ";
		std::cin >> choice;

		switch(choice) {
			case 1:
				std::cout << "Enter value to be inserted at begining: ";
				std::cin >> value;
				head = insertAtBegining(head, value);
				break;

			case 2:
				std::cout << "Enter value to be inserted at end: ";
				std::cin >> value;
				head = insertAtEnd(head, value);
				break;

			case 3:
				std::cout << "Enter the value to be deleted: ";
				std::cin >> value;
				head = deleteByValue(head, value);
				break;

			case 4:
				std::cout << "Enter element you want to search: ";
				std::cin >> value;
				int result;
				result = searchElement(head, value);

				if(result == -1) {
					std::cout << "Element not found!\n";
				}
				else {
					std::cout << "Element found at " << result << '\n';
				}
				break;

			case 5:
				int length;
				length = lengthOfList(head);
				std::cout << "The length of the list is: " << length << '\n';
				break;

			case 6:
				display(head);
				break;

			case 7:
				std::cout << "Returning to Main Menu...\n\n";
				break;

			default:
				std::cout << "Invalid choice! Try again.\n";
		} 

	} while(choice != 7);
}

/*
=====================================================================================
Display Function

Prints the doubly linked list in two directions:

1. Forward Traversal (Head -> Tail)
2. Backward Traversal (Tail -> Head)

Helps verify correct functioning of prev and next pointers
in the doubly Linked List.
=====================================================================================
*/

void display(DNode* head) {
	if(head == NULL) {
		std::cout << "List is empty!\n";
		return;
	}
	
	DNode* temp = head;
	DNode* last = NULL;

	std::cout << "Forward: ";
	while(temp != NULL) {
		std::cout << temp->data << " <-> ";
		last = temp;
		temp = temp->next;
	}
	std::cout << "NULL\n";

	std::cout << "Backward: ";
	while(last != NULL) {
		std::cout << last->data << " <-> ";
		last = last->prev;
	}
	std::cout << "NULL\n";
}

/*
=====================================================================================
Insert At Begining

Creates a new node and inserts at the start of
the doubly Linked list.

Steps:
1. Create new node
2. Point newNode->next to current head
3. Update head->prev to newNode
4. Update head pointer

Returns:
Updated head of the list
=====================================================================================
*/

DNode* insertAtBegining(DNode* head, int value) {
	DNode* newNode = new DNode(value);

	if(head == NULL) {
		head = newNode;
		return newNode;
	}

	
	newNode->next = head;
	head->prev = newNode;
	head = newNode;

	return newNode;
}

/*
=====================================================================================
Insert At End

Adds a new node at the end of the doubly linked list.

Steps:
1. Traverse to the last node
2. Link last node's next pointer to new node
3. Set newNode prev to last node

Returns:
Head of the list
=====================================================================================
*/

DNode* insertAtEnd(DNode* head, int value) {
	DNode* newNode = new DNode(value);

	if(head == NULL) {
		head = newNode;
		return newNode;
	}
	DNode* temp = head;

	while(temp->next != NULL) {
		temp = temp->next;
	}
	//temp->next = newNode;
	newNode->prev = temp;
	temp->next = newNode;

	return head;
}

/*
=====================================================================================
Delete By Value

Delete the first node containing the specific value.

Cases handled:
1. List is empty
2. Node to delete is the head
3. Node is in the middle
4. Node is at the end

Returns:
Updated head pointer
=====================================================================================
*/

DNode* deleteByValue(DNode* head, int value) {

	if(head == NULL) {
		return NULL;
	}
	DNode* temp = head;

	while(temp != NULL && temp->data != value) {
		temp = temp->next;
	}

	if (temp == NULL) {
		std::cout << "Element not found!\n";
		return head;
	}

	if(temp == head) {
		head = head->next;
		if(head != nullptr) {
			head->prev= nullptr;
		}
		std::cout << "Element successfully deleted\n";
		delete temp;
		return head;
	}

	if(temp->next != nullptr) {
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		std::cout << "Element sucessfully deleted\n";
	}

	delete temp;
	return head;
}

/*
=====================================================================================
Search Element

Searches for a value in the doubly Linked list.

Returns:
Position of the element (-1 if element not found)
=====================================================================================
*/

int searchElement(DNode* head, int value) {
	int position = 1;

	DNode* temp = head;
	while(temp != nullptr) {
		if(temp->data == value) {
			return position;
		}
		temp = temp->next;
		position++;
	}

	return -1;
}

/*
=====================================================================================
Length of List

Traverses the entire list and counts the number of nodes present.

Returns:
Total number of nodes in the list.
=====================================================================================
*/

int lengthOfList(DNode* head) {
	
	int count = 0;
	while(head) {
		count++;
		head = head->next;
	}
	return count;
}
