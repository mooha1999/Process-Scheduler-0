#include "processor.h"
#include"process.h"
#include"PriortyQueue.h"
#pragma once 

class SJF :public Processor
{
public:

	PriortyQueue<Process*>* Rdy;
	int countBlk = 0;
	virtual void push(Process* p)
	{
		Rdy->Push(p, p->getCT()); // take the process and the cpu time
	}
	virtual void schedulago()
	{
		if (!RUN)
		{
			RUN = Rdy->Pop();   //return the value of the firt process in rdy list
	
		}
		else
		{
			BUSY = true; //busy when running
			TBT++; //total busy time

			if (RUN->getEX() == RUN->getCT())
			{
				AR = AR + RUN->getTRT();
				Finish = RUN;
				RUN = nullptr;
			}
			if (!RUN->getPairs().IsEmpty() && RUN->getEX() == RUN->getPairs().Peek()->first)
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
		while (temp.IsEmpty())
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

	virtual int Getcountblk()// to calculated the total number of blk in sjf
	{
		return countBlk;
	}
	virtual int Getidrun()  //return the id of the running process 
	{
		int r = RUN->getPID();
		return r;
	}

	virtual int Getidblk() //return the id of the blocked process 
	{
		int b = Blk->getPID();
		return b;
	}

};