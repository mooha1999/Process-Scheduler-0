#include "linkedlist.h"
#include "process.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
}

void LinkedList::insertprocess(int val)
{
	Process* new_node = new Process();
	new_node->data = val;
	new_node->next = NULL;
	if (head == NULL) {
		head = new_node;
	}
	else {
		Process* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

void LinkedList::displayList() {
	Process* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void LinkedList::movenode(Process** destination, Process** source) {
	Process* newNode = *source;
	*source = newNode->next;
	newNode->next = *destination;
	*destination = newNode;
}