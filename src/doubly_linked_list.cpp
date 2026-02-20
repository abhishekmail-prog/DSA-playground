#include <iostream>
#include "../include/doubly_linked_list.h"

DNode::DNode(int value){
	prev = nullptr;
	data = value;
	next = nullptr;
}

void doublyLinkedListMenu() {

	int choice, value;
	DNode* head = NULL;

	do {
		std::cout << "1. Insert at Begining\n";
		std::cout << "2. Insert at End\n";
		std::cout << "3. Delete by Value\n";
		std::cout << "4. Search a element\n";
		std::cout << "5. Length of the list\n";
		std::cout << "6. Display the list\n";
		std::cout << "7. Exit";

		std::cout << "Enter a choice: ";
		std::cin >> choice;

		switch(choice) {
			case 1:
				std::cout << "Enter value to be inserted at begining: ";
				std::cin >> value;
				insertAtBegining(head, value);
				break;
			/*case 2:
				std::cout << "Enter value to be inserted at end: ";
				std::cin >> value;
				head = insertAtEnd(head, value);
				break;
			case 3:
				std::cout << "Enter the value to be deleted: ";
				std::cin >> value;
				head = deleteByValue(head, size);
				break;
			case 4:
				std::cout << "Enter element you want to search: ";
				std::cin >> value;
				std::cout << (search(head, value)) ? "Found\n" : "Not Found\n";
				break;
			case 5:
				std::cout << "The length of the list is: " << length(head);
				break;*/
			case 6:
				display(head);
				break;
			default:
				std::cout << "Invalid choice! Try again.\n";
		} 

	} while(choice != 7);
}

void display(DNode* head) {
	if(head == NULL) {
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

	std::cout << "Backward: ";
	while(last != NULL) {
		std::cout << last->data << " <-> ";
		last = last->next;
	}
}

DNode* insertAtBegining(DNode* head, int value) {
	DNode* newNode = new DNode;

	if(head == NULL) {
		head = newNode;
		return newNode;
	}

	newNode->next = head;
	head = newNode;
	
	return newNode;
}
