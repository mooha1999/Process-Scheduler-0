#pragma once

#include "QueueNode.h"
template<typename T>

class PriortyQueue
{
	Node<T>* front;
	int size
  public:
	PriortyQueue()
	{
		front= nullptr;
		size = 0;
	}

	void Push(T data,T Prio)
	{
		Node<T>* temp = new Node<T>(data ,Prio);
		Node<T>* curr=nullptr;
		Node<T>* prev=nullptr;
		if (front == nullptr || prio >= front->prio)
		{
			temp->next = front;
			front = temp;
		}
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

