#include "processor.h"
#include"process.h"
#include"PriortyQueue.h"
#pragma once

class SJF :public Processor
{
public:

	PriortyQueue<Process*>* Rdy = new PriortyQueue<Process*>; // intializing pointer Queue

	virtual void push(Process* p)
	{
		Rdy->Push(p, p->getCT()); // take the process and the cpu time
	}

	virtual void schedulago(int timestep)
	{
		if (!Rdy->IsEmpty() && !RUN) //check if rdy queue isn't empty
		{
			RUN = Rdy->Pop();   //return the value of the firt process in rdy list
			RUN->setRT(timestep - (RUN->getAT()));
			//Response time is difference between current timestep and the arrival time to the processor
		}
		else if (RUN)
		{
			BUSY = true; //busy when running
			TBT++; //total busy time

			if (RUN->getEX() == RUN->getCT())
			{
				RUN->setTT(timestep);
				AR = AR + RUN->getTRT();
				Finish = RUN;
				RUN = nullptr;
			}
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

	virtual Queue<int> GetID()
	{
		PriortyQueue<Process*>temp = *Rdy;
		Queue<int>ID;
		while (!temp.IsEmpty())
		{
			int x = temp.Pop()->getPID();  //return id
			ID.Push(x);
		}
		return ID;
	}
	virtual int GetTWT()
	{
		PriortyQueue<Process*>temp = *Rdy;
		int SumWT = 0;
		while (!temp.IsEmpty())
		{
			int x = temp.Pop()->getWT();  //return waiting time
			SumWT = SumWT + x;
		}
		return SumWT;
	}
	virtual int GetCount()
	{
		return Rdy->Count();
	}

	virtual int Getidrun()  //return the id of the running process
	{
		int r = RUN->getPID();
		return r;
	}
};