#pragma once
template<typename T>
class Node
{
private:
	T item;
	T prio;//priority 
	Node<T>* next;
public:

	Node()
	{
		next = nullptr;
	}

	Node(T newItem)
	{
		item = newItem;
		next = nullptr;
	}
	Node(T priority)
	{
		prio = priority;
	}

	void setItem(T newItem)
	{
		item = newItem;
	}
	void setPrio(T Newprio)
	{
		prio = Newprio;
	}

	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}

	T getItem() const
	{
		return item;
	}
	T getPrio() const
	{
		return prio;
	}
	Node<T>* getNext() const
	{
		return next;
	}
};