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
    process* new_node = new process();
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    }
    else {
        process* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void LinkedList::displayList() {
    process* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::movenode(process** destination, process** source) {
    process* newNode = *source;
    *source = newNode->next;
    newNode->next = *destination;
    *destination = newNode;
}
