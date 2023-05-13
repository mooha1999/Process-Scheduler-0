#include "process.h"
#include "Processor.h"



class FCFS : public Processor {
public:

	Queue<Process*>* Rdy; // pointer Queue
	

	virtual void push(Process* p)
	{
		Rdy->Push(p);

	
	}
		
	virtual void schedulago()

	{

		if (!RUN)
		{
			RUN = Rdy->Pop();   //return the value of the firt process in rdy list
			//if execution time = 
			int a = RUN->getpair().Peek()->first;
			int b = RUN->getEX();
			if (a==b) {
				//remove the pair from comparison
				RUN->getpair().Pop();
			}
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
				BUSY = false;
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


 
};