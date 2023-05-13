#include "Process.h"
#include <string>
#include <iostream>
#pragma once
class Processor
{
public:
	int TBT = 0; //total busy time of processes
	int AR; //total turn around time of all processes
	bool BUSY;
	Process* RUN; // this process to assign the runnin process
	Process* Finish; // this process to put the finished process

	virtual void schedulago() = 0;
	virtual void push(Process* p) = 0;
	virtual Queue<int> GetID() = 0;
	virtual int GetWT() = 0;
	//virtual int GetBT(bool BUSY) = 0; //calculate busy time
};
