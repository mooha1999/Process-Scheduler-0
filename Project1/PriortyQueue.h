#pragma once
#include "PriorityNode.h"
template<typename T>

class PriortyQueue
{
	PriorityNode<T, int>* front;
	PriorityNode<T, int>* rear;
	int size;
	class Iterator {
	private:
		Node<T>* current;

	public:
		Iterator(Node<T>* node) : current(node) {}

		T operator*() const {
			return current->getItem();
		}

		Iterator& operator++() {
			current = current->getNext();
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}
	};
public:

	PriortyQueue()
	{
		front = nullptr;
		size = 0;
	}

	void Push(T data, int prio)
	{
		PriorityNode<T, int>* temp = front;
		PriorityNode<T, int>* newnode = new PriorityNode<T, int>(data, prio);
		if (front == nullptr || prio < front->getPriority())
		{
			newnode->setNext(front);
			front = newnode;
		}
		else
		{
			while (temp->getNext() != nullptr && temp->getNext()->getPriority() <= prio)
			{
				temp = temp->getNext();
				newnode->setNext(temp->getNext());
				temp->setNext(newnode);
			}
		}
		size++;
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
	int Count() { return size; }
	Iterator begin() const {
		return Iterator(front);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}
};
