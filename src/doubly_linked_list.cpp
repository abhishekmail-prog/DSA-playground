#include <iostream>
#include "../include/doubly_linked_list.h"

DNode::DNode(int value) {
	prev = nullptr;
	data = value;
	next = nullptr;
}

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

				if(result == -1)
					std::cout << "Element not found!\n";
				else
					std::cout << "Element found at " << result << '\n';
				break;
			/*case 5:
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
	std::cout << "NULL\n";

	std::cout << "Backward: ";
	while(last != NULL) {
		std::cout << last->data << " <-> ";
		last = last->prev;
	}
	std::cout << "NULL\n";
}

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
