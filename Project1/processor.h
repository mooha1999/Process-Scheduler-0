#include "Process.h"
#include <string>
#include <iostream>
#pragma once
class Processor
{
public:
	int TBT = 0; //total busy time of processes
	int AR = 0; //total turn around time of all processes
	bool BUSY; //is the processor busy?
	Process* RUN; // this process to assign the runnin process
	Process* Finish; // this process to put the finished process
	Process* Blk; // this for block , when requested io we get the first element in pairs to cmp with Ex-time

	virtual Process* getBlk() {
		return Blk;
	}

	virtual Process* getFinish() {
		return Finish;
	}

	virtual void setBlk(Process* blk) {
		Blk = blk;
	}

	virtual void setFinish(Process* finish) {
		Finish = finish;
	}

	virtual void schedulago(int timestep) = 0;
	virtual void push(Process* p) = 0;
	virtual Queue<int> GetID() = 0;
	virtual int GetCount() = 0;
	virtual int GetTWT() = 0;
	virtual int Getidrun() = 0;
	int GetBusyTime()
	{
		return TBT;
	}

	int GetTRT() //total turn around time (TT-AT)

	{
		return AR;
	}
	//virtual int GetBT(bool BUSY) = 0; //calculate busy time
};
