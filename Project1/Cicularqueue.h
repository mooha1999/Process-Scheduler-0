#pragma once
#include "processor.h"
#include"process.h"
class Circularqueue
{
public:
    process* front;
    process* rear;
   

 // for queue of RR

  Circularqeueu()
	{
		front = NULL;
		rear = front;
        
	}
	bool Isempty()
	{
		if (front == NULL)
		{
			return true;
		}
		return false;

	}
    void front(process*firstp)
    {
        firstp=front->data;
    }
	void push(process * p) //push the value but it is queue 
	{

		process* newnode = new process;
		newnode->data = p;
		process* temp = front;
		if (Isempty())
		{
			front = rear= temp;

		}
		else
		{
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newnode;
			front = newnode;
			process* rear = front;  // here will be another pointer to link the last ptr with the first ptr 
			newnode->next = NULL;
		}



	}
  void  pop()
	{
		process* temp=front;
		
		if (Isempty())
		{
			return;

		}
		else
		{
			front = front->next;

		}
		delete temp;

	}


	int Peek()
	{ 
		return front->next;
	}
    
	int countQ()
	{
		int count = 0;
		process* temp = front;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
			return count;
		}
	}

	void delnode(int value)
	{
		process* rear = front; //another pointer have the address of first
		if (Isempty())
		{
			cout << "The Queue is empty\n" << endl;
		}

		process* deleteptr = front;
		if (front->data == value)
		{
			//case if we want to delete first node 
			front = front->next;
			delete deleteptr;
		}
		else
		{  //case if the value we want to delete is not the first

			process* prev = NULL;
			deleteptr = front;

			while (deleteptr->data != value)
			{
				prev = deleteptr;
				deleteptr = deleteptr->next;

				prev->next = deleteptr->next;
				delete deleteptr;
			}



		}

    }





};