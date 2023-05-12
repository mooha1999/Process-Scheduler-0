#pragma once
#include "QueueNode.h"
template<typename T>

class PriortyQueue
{
	Node<T>* front;

  public:

	PriortyQueue()
	{
		front= nullptr;
	}

	void Push(T data,T Prio)
	{
		Node<T>* temp = new Node<T>;
		temp->getItem() = data;
		temp->getPrio() = prio;
		Node<T>* curr=nullptr;
		Node<T>* prev=nullptr;
		if (front == nullptr || prio >= front->prio)
		{
			temp->setItem(data)= front;
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

			temp->getNext() = prev->getNext();
			prev->getNext() = temp;
		}
	}
	

	

	

	T Pop() {
		T item = Head->getItem();
		Head = Head->getNext();
		size--;
		return item;
	}

	T Peek() { return Head->getItem(); }


};

