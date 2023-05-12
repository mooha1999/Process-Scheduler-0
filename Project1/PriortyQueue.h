#pragma once
#include "QueueNode.h"
template<typename T>

class PriortyQueue
{
	Node<T>* front;
	Node<T>* rear;
  public:

	PriortyQueue()
	{
		front= nullptr;
	}

	void Push(T data,int Prio)
	{
		Node<T>* temp = front;
		Node<T>* newnode = new Node<T>(data, Prio);
		if (front==nullptr  || prio < front->prio)
		{
			newnode->getNext() = front;
			front = newnode;
			
		}
		else
		{

			while (temp->getNext()->prio<=prio && temp->getNext()!=nullptr)
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

