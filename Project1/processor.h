#include "process.h"
#include <string>
#include <iostream>
#pragma once
class Processor
{

public:
	int TBT = 0; //total busy time of processes
	bool BUSY;
	process* RUN;

	virtual void schedulago()=0;
	virtual void push(process*p)=0;
	virtual Queue<int> GetID()=0;
	virtual int GetWT()=0;
	




private:
};


