#pragma once
#include "PriorityNode.h"
template<typename T>

class PriortyQueue
{
	PriorityNode<T, int>* front;
	PriorityNode<T, int>* rear;
public:

	PriortyQueue()
	{
		front = nullptr;
	}

	void Push(T data, int Prio)
	{
		PriorityNode<T, int>* temp = front;
		PriorityNode<T, int>* newnode = new PriorityNode<T, int>(data, Prio);
		if (front == nullptr || prio < front->prio)
		{
			newnode->getNext() = front;
			front = newnode;
		}
		else
		{
			while (temp->getNext()->prio <= prio && temp->getNext() != nullptr)
			{
				temp = temp->getNext();
				newnode->getNext() = temp->getNext();
				temp->getNext() = newnode;
			}
		}
	}

	T Pop()
	{
		T item = front->getItem();
		front = front->getNext();
		size--;
		return item;
	}

	T Peek()
	{
		return front->getItem();
	}

	bool IsEmpty()
	{
		return size == 0;
	}
};
