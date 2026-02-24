#include <iostream>
#include "../include/linked_list.h"

/*
=======================================================================================
Linked List Menu System
Author: Abhishek
Project: DSA-Playground

Description: 
Provides a menu driven interface to perform common singly linked list operations like:

1. Insert At Head
2. Insert At Tail
3. Delete by Value
4. Search Element
5. Display List
6. Find length
7. Reverse Linked List
8. Exit

Concepts used:
~ Pointers
~ Dynamic Memory Allocation
~ Structures
~ Linked List Traversal
~ Iterative Reversal
=======================================================================================
*/

void linkedListMenu() {

	// choice -> user menu selection
	// value  -> value entered by user
	// head   -> pointer to first node of linked list

	int choice, value;
	Node* head = NULL;

	// Menu loop runs until usr selects Exit (8)
	do {
 
                 std::cout << "--- LINKED LIST MENU ---\n";
                 std::cout << "1. Insert at Head\n";
                 std::cout << "2. Insert at Tail\n";
                 std::cout << "3. Delete by value\n";
                 std::cout << "4. Search\n";
                 std::cout << "5. Display\n";
                 std::cout << "6. Length\n";
                 std::cout << "7. Reverse Linked list\n";
		 std::cout << "8. Exit\n";
                 std::cout << "Enter choice: ";
                 std::cin >> choice;
  
                 switch(choice) {
                         case 1:
                                 std::cout << "Enter value: ";
                                 std::cin >> value;
                                 head = insertAtHead(head, value);
                                 break;
 
                         case 2:
                                 std::cout << "Enter value: ";
                                 std::cin >> value;
                                 head = insertAtTail(head, value);
                                 break;
 
                         case 3:
                                 std::cout << "Enter value: ";
                                 std::cin >> value;
                                 head = deleteByValue(head, value);
                                 break;
 
                         case 4:
                                 std::cout << "Enter value: ";
                                 std::cin >> value;
                                 std::cout << (search(head, value) ? "Found\n" : "Not Found\n");
                                 break;
 
                         case 5:
                                 display(head);
                                 break;
  
                         case 6:
                                 std::cout << "Length: " << length(head) << '\n';
                                 break;

                	case 7:
				head = reverseLinkedList(head);
				break;
			}
	} while(choice != 8);
}

/*
=======================================================================================Function: insertAtHead
Description: 
Inserts a new node at the begining of the linked list.

Algorithm:
Create a new node.
Make its next pointer print to current head.
Update head to new node.

Time Complexity: O(1)
Space Complexity: O(1)
=======================================================================================
*/

Node* insertAtHead(Node* head, int value) {
	Node* newNode = new Node;
	newNode->data = value;
	newNode->next = head;

	return newNode;
}

/*
=======================================================================================
Function: insertAtTail
Description:
Inserts a new node at the end of the linked list.

Algorithm:
Traverse until last node.
Attack new node at the end.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================================================
*/

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

	temp->next  = newNode;

	return head;
}

/*
=======================================================================================
Function: deleteByValue
Description:
Deletes the first occurrence of a given value.

Algorithm:
If head contains value, delete head.
Otherwise, traverse and unlink matching node.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================================================
*/

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

/*
=======================================================================================
Function; search
Description:
Searches for a value in the linked list

Returns:
true  -> if value found
false -> if value not found

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================================================
*/

bool search(Node* head, int value) {
	while(head) {
		if(head->data == value)
			return true;

		head = head->next;
	}
	return false;
}

/*
=======================================================================================
Function: length
Description: 
Counts and returns number of nodes in the linked list.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================================================
*/

int length(Node* head) {
	int count = 0;
	while(head) {
		count++;
		head = head->next;
	}

	return count;
}

/*
=======================================================================================
Function: display
Description: 
Prints the linked list in readable format.

Example:
10 -> 20 -> 30 -> NULL
=======================================================================================
*/

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

/*
=======================================================================================
Function: reverseLinkedList
Description:
Reverses the linked list using iterative apprach.

Algorithm:
Use three pointers:
prev, curr, next

Reverse links one by one.

Time Complexity: O(n)
Space Complexity: O(1)
=======================================================================================
*/

Node* reverseLinkedList(Node* head) {

	if(head == NULL) {
		std::cout << "The list is empty!\n";
	}
	Node* prev = nullptr;
	Node* curr = head;
	Node* after = after;

	while (curr != nullptr) {

        	after = after->next;     
        	curr->next = prev;     
       		prev = curr;           
        	curr = after;           
    	}

   	return prev; 
}
