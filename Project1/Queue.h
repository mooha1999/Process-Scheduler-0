#pragma once
#include "QueueNode.h"
template<typename T>
class Queue
{
	// any operation O(1)
	Node<T>* Head, * Tail;
	int size;
	class Iterator {
	private:
		Node<T>* currentNode;
	public:
		Iterator(Node<T>* node) : currentNode(node) {}

		Iterator& operator++() {
			if (currentNode) {
				currentNode = currentNode->getNext();
			}
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return currentNode != other.currentNode;
		}

		T operator*() const {
			return currentNode->getItem();
		}
	};
public:
	Queue()
	{
		Head = Tail = nullptr;
		size = 0;
	}

	void Push(T val) {
		Node<T>* temp = new Node<T>(val);
		if (size == 0)
		{
			Head = Tail = temp;
		}

		else
		{
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

	bool Remove(T val) {
		Node<T>* temp = Head;
		Node<T>* ret = nullptr;
		if (temp->getItem() == val)
			return Pop();
		else {
			while (temp->getNext()) {
				if (temp->getNext()->getItem() == val) {
					ret = temp->getNext();
					temp->setNext(ret->getNext());
					size--;
					break;
				}
			}
		}
		return (ret);
	}

	bool IsEmpty() { return size == 0; }

	Iterator begin() const {
		return Iterator(Head);
	}

	Iterator end() const {
		return Iterator(nullptr);
	}
};
