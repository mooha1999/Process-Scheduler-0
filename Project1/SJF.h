#include "processor.h"
#include"process.h"
#include"PriortyQueue.h"
class SJF :public Processor
{
public:

	PriortyQueue<Process*>* Rdy;

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
			if (RUN->getEX() == RUN->getPairs().Peek()->first && !RUN->getPairs().IsEmpty())
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
	int GetCount() {
		return Rdy->Count();
	}

	//nouran: get id of running processes 
	virtual int getidrun() //return the id of the running process 
	{
		int r = RUN->getPID();
		return r;
	}

};