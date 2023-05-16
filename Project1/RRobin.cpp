#include <iostream>
using namespace std;
#include"RRobin.h"


void RRobin::settimeSlice(int TS)
{
	time_slice = TS;
}
void RRobin::Add_process(process * data)  //insert the process in te rdy list 
{
	Rdy.insertprocess(data);
}
void RRobin::schedulealgo() //here i need to calculate num_of_jobs that will done
{
	

}


//Circular queue
    RRobin::RRobin()
	{
		front = NULL;
		rear = front;

	}
	bool RRobin::Isempty()
	{
		if (front == NULL)
		{
			return true;
		}
		return false;

	}
	void RRobin::push(int val) //push the value but it is queue 
	{

		process* newnode = new process;
		newnode->data = val;
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
	int RRobin::countQ()
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

	void RRobin::delnode(int value)
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

