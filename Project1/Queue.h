#pragma once
#include "QueueNode.h"
template<typename T>
class Queue
{
	// any operation O(1) 
	Node<T>* Head, * Tail;
	int size;
public:
	Queue() {
		Head = Tail = nullptr;
		size = 0;
	}

	void Push(T val) {
		Node<T>* temp = new Node<T>(val);
		if (size == 0)
			Head = Tail = temp;
		else {
			Tail->setNext(temp);
			Tail = temp;
		}
		size++;
	}

	T Pop() {
		T item = Head->getItem();
		Head = Head->getNext();
		size--;
		return item;
	}

	T Peek() { return Head->getItem(); }

	bool IsEmpty() { return size == 0; }
	//virtual void Add(T item) { Push(item); }
};
