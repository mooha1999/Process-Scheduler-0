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

	void Push(T data,T Prio)
	{
		Node<T>* temp = new Node<T>(data,Prio);
		
		if (front==nullptr  || prio < front->prio)
		{
			temp->next = front;
			front = temp;
			
		}
		else
		{
			curr = front;

			while (curr <= curr->priority && prio<= curr->prio)
			{
				pre = curr;
				curr = curr->getNext();
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

