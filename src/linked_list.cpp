#include <iostream>
#include "../include/linked_list.h"

void linkedListMenu() {

	int choice, value;
	Node* head = NULL;
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
				std::cout << "Succesfully reversed linkedlist\n";
				break;
			}
  
	} while(choice != 8);

	
}

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

	temp->next  = newNode;

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

Node* reverseLinkedList(Node* head) {

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

