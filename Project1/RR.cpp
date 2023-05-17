#pragma once
#include "processor.h"
#include"process.h"
#include"Queue.h"
//fffff
class RRobin : public Processor
{
public:

	Queue<Process*>* Rdy = new Queue<Process*>; // intializing pointer Queue
	//Process* Finish; // this process to put the finished process
	int time_slice;
	RRobin(int TS)
	{
		TS = time_slice;
	}
	virtual void push(Process* p)
	{
		Rdy->Push(p);
	}
	virtual void schedulago()
	{
		if (!Rdy->IsEmpty() && !RUN)// if the RUN process is not empty
		{
			RUN = Rdy->Pop();   //return the value of the firt process in rdy list

			//execution time and pair comparison
			int a = RUN->getPairs().Peek()->first;
			int b = RUN->getEX();
			if (a == b)
			{
				//remove the pair from comparison
				RUN->getPairs().Pop();
			}
		}
		else
		{
			BUSY = true; //busy when running
			TBT++; //total busy time

			if (RUN->getEX() == RUN->getCT()) //Ex-time=CPU-time
			{
				AR = AR + RUN->getTRT();
				Finish = RUN;
				RUN = nullptr;
			}
			//case 1  if the execution time is equal to time slice
			if (RUN->getEX() % time_slice == 0) // reminder (
			{
				RUN->incEX(); // hna 34an mayd5ol4 be nafs el ex-time (resulting infinte loop)
				Rdy->Push(RUN);
				RUN = nullptr;
			}
			//RUN->getPairs().Peek()->first
			// case 2
			else
			{
				RUN->incEX();
			}
		}
	}
	Queue<int> GetID()
	{
		Queue<Process*>temp = *Rdy;   //*Rdy to return the value of Rdy (copy the rdy queue )
		Queue<int>Ids; //Id of each process
		while (!temp.IsEmpty())
		{
			int x = temp.Pop()->getPID();  //return id
			Ids.Push(x); //push the id in the queue
		}
		return Ids;
	}
	int GetCount() // to get number od ids
	{
		Queue<int>ids;
		int counter = 0;
		ids = GetID(); //return ids
		for (int i : ids)
		{
			counter++;
		}
		return counter;
	}

	virtual int GetWT()
	{
		Queue<Process*>temp = *Rdy;
		int SumWT = 0;
		while (!temp.IsEmpty())
		{
			int x = temp.Pop()->getRMT();  //return waiting time
			SumWT = SumWT + x;
		}
		return SumWT;
	}

	//nouran: get id of running processes
	virtual int getidrun() //return the id of the running process
	{
		int r = RUN->getPID();
		return r;
	}
};