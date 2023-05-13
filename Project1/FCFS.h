#include "process.h"
#include "Processor.h"

class FCFS : public Processor {
public:

	Queue<Process*>* Rdy; // pointer Queue
	Process* Finish;

	virtual void push(Process* p)
	{
		Rdy->Push(p);
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
			else
			{
				RUN->incEX();
			}
		}
	}
	Queue<int> GetID()
	{
		Queue<Process*>temp = *Rdy;   //*Rdy to return the value of Rdy (copy)
		Queue<int>ID;
		while (temp.IsEmpty())
		{
			int x = temp.Pop()->getPID();  //return id
			ID.Push(x); //push the id in the queue
		}
		return ID;
	}
	virtual int GetWT()
	{
		Queue<Process*>temp = *Rdy;
		int SumWT = 0;
		while (!temp.IsEmpty())
		{
			int x = temp.Pop()->getWT();  //return waiting time
			SumWT = SumWT + x;
		}
		return SumWT;
	}
};