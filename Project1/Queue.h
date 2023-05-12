#pragma once
#include "QueueNode.h"
template<typename T>
class Queue
{
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

	//virtual void Add(T item) { Push(item); }
};
