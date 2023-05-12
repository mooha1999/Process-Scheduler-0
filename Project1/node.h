#pragma once
#ifndef _NODE
#define _NODE

template<typename T>
class Node
{
private:
	T data;	// A data item (template so that it can be any data type)
	Node<T>* next;	// Pointer to next node
public:

	Node() //default constructor
	{
		next = nullptr;
	}

	Node(T newdata) //non-default constructor
	{
		data = newdata;
		next = nullptr;

	}

	void setdata(T newdata)
	{
		data = newdata;
	} 

	void setnext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} 

	T getdata() const
	{
		return data;
	} 

	Node<T>* getNext() const
	{
		return next;
	}
}; // end Node

#endif	

