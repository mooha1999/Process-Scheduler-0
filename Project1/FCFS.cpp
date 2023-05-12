
#include "FCFS.h"

FCFS::FCFS() {
    front = NULL;
    rear = NULL;
}

void FCFS::enqueue(int data) {
    process* new_node = new process();
    new_node->data = data;
    new_node->next = NULL;

    if (rear == NULL) {
        front = new_node;
        rear = new_node;
        return;
    }

    rear->next = new_node;
    rear = new_node;
}

int FCFS::dequeue() {
    if (front == NULL) {
        return -1;
    }

    process* temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    int data = temp->data;
    delete temp;

    return data;
}

void FCFS::migrate(process x, int MaxW) {
    int n = x.getWT();
    if (n > MaxW) {
        

    }

}