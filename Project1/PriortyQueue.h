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
		rear = nullptr;
		size = 0;
	}

	void Push(T data, int prio)
	{
		PriorityNode<T, int>* temp = new PriorityNode<T, int>(data, prio);
		if (size == 0)
			front = rear = temp;
		else if (prio <= front->getPriority()) {
			temp->setNext(front);
			front = temp;
		}
		else if (prio >= rear->getPriority()) {
			rear->setNext(temp);
			rear = temp;
		}
		else {
			for (PriorityNode<T, int>* i = front; i; i = i->getNext()) {
				if (prio < i->getNext()->getPriority()) {
					temp->setNext(i->getNext());
					i->setNext(temp);
					break;
				}
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
