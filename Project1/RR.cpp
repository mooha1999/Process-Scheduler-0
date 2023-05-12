#include <iostream>
using namespace std;

class Node
{
public:

	int Ldata;  // here is for the data for any node 
	Node* nextD; // here is a pointer for the next node 
};

class RRobin
{
public:

	Node* fst; // first node 
	Node* lst;  // last node which will be equal to the first 

	RRobin()
	{
		fst = NULL;
		lst = fst;

	}
	bool Isempty()
	{
		if (fst == NULL)
		{
			return true;
		}
		return false;

	}
	void push(int val) //push the value but it is queue 
	{

		Node* newnode = new Node;
		newnode->Ldata = val;
		Node* temp = lst;
		if (Isempty())
		{
			fst = lst = temp;

		}
		else
		{
			while (temp->nextD != NULL)
			{
				temp = temp->nextD;
			}
			temp->nextD = newnode;
			lst = newnode;
			Node* lst2 = fst;  // here will be another pointer to link the last ptr with the first ptr 
			newnode->nextD = NULL;
		}



	}
	int countQ()
	{
		int count = 0;
		Node* temp = fst;
		while (temp != NULL)
		{
			count++;
			temp = temp->nextD;
			return count;
		}
	}

	void delnode(int value)
	{
		Node* lst2 = fst; //another pointer have the address of first
		if (Isempty())
		{
			cout << "The Queue is empty\n" << endl;
		}

		Node* deleteptr = fst;
		if (fst->Ldata == value)
		{
			//case if we want to delete first node 
			fst = fst->nextD;
			delete deleteptr;
		}
		else
		{  //case if the value we want to delete is not the first

			Node* prev = NULL;
			deleteptr = fst;

			while (deleteptr->Ldata != value)
			{
				prev = deleteptr;
				deleteptr = deleteptr->nextD;

				prev->nextD = deleteptr->nextD;
				delete deleteptr;
			}



		}
	}
};