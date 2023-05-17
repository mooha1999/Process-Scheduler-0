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
		time_slice = TS;
	}
	virtual void push(Process* p)
	{
		Rdy->Push(p);
	}
	virtual void schedulago(int timestep)
	{
		if (!Rdy->IsEmpty() && !RUN) //check if rdy queue isn't empty
		{
			RUN = Rdy->Pop();   //return the value of the firt process in rdy list
			RUN->setRT(timestep - (RUN->getAT()));
		}
		else if (RUN)
		{
			BUSY = true; //busy when running
			TBT++; //total busy time
			if (RUN->getEX() == RUN->getCT()) //Ex-time=CPU-time
			{
				RUN->setTT(timestep);
				AR = AR + RUN->getTRT();
				Finish = RUN;
				RUN = nullptr;
			}
			//case 1  if the execution time is equal to time slice
			else if (RUN->getEX() != 0 && RUN->getEX() % time_slice == 0) // reminder (
			{
				RUN->incEX(); // hna 34an mayd5ol4 be nafs el ex-time (resulting infinte loop)
				Rdy->Push(RUN);
				RUN = nullptr;
			}
			// case 2 when the ex time is equal to the first element(time step)in pairs
			// kman lw el pairs fadya 34an lw 3amal peek le 7aga fadya hay3mil error
			else if (!RUN->getPairs().IsEmpty() && RUN->getEX() == RUN->getPairs().Peek()->first)
			{
				Blk = RUN;
				RUN = nullptr;
			}
			else
			{
				RUN->incEX();
			}
		}
	}
	Queue<int> GetID()
	{
		Queue<Process*>temp = *Rdy;   //*Rdy to return the value of Rdy (copy the rdy queue )
		Queue<int> Ids; //Id of each process
		while (!temp.IsEmpty())
		{
			int x = temp.Pop()->getPID();  //return id
			Ids.Push(x); //push the id in the queue
		}
		return Ids;
	}
	virtual int GetTWT()
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
	virtual int Getidrun() //return the id of the running process
	{
		if (!RUN) //RUN==nullptr  hna lazem a3mil check 34an hay3mil error
		{
			return -1;
		}
		else
		{
			int r = RUN->getPID();
			return r;
		}
		
	}
	int GetCount() {
		return Rdy->Count();
	}
};