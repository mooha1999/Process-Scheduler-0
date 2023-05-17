#include "process.h"
#include "Processor.h"
#pragma once

class FCFS : public Processor
{
public:

	Queue<Process*>* Rdy = new Queue<Process*>; // intializing pointer Queue
	int countBlk = 0;

	virtual void push(Process* p)
	{
		Rdy->Push(p);
	}

	virtual void schedulago(int timestep)
	{
		if (!Rdy->IsEmpty() && !RUN)
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
				RUN->setTT(timestep); //now the termination time of process is equal to current timestep
				AR = AR + RUN->getTRT(); // total turn around time of all processes
				Finish = RUN;
				RUN = nullptr;
				BUSY = false;
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
		Queue<Process*>temp = *Rdy;   //*Rdy to return the value of Rdy (copy)
		Queue<int>ID;
		while (!temp.IsEmpty())
		{
			int x = temp.Pop()->getPID();  //return id
			ID.Push(x); //push the id in the queue
		}
		return ID;
	}
	virtual int GetTWT()
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

	Process* kill(int id) {
		//for running processes
		int z = RUN->getPID();  //return id of running process
		if (z == id) {
			Process* killPR = RUN;
			RUN = nullptr;
			BUSY = false;
			return killPR;
		}
		//for rdy processes
		for (Process* i : *Rdy) {
			int y = i->getPID();  //return id from ready queue
			if (y == id) {
				Process* killPD = i;
				//removing the process
				Rdy->Remove(i);
				return killPD;
			}
		}

		return nullptr;
	}
	virtual int GetCount()
	{
		return Rdy->Count();
	}

	virtual int Getidrun() //return the id of the running process
	{
		if (!RUN) //RUN==nullptr
		{
			return -1;
		}
		else
		{
			int r = RUN->getPID();
			return r;
		}
	}
};