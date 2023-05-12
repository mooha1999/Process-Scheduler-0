#include "process.h"
#include <string>
#include <iostream>
#pragma once
class Processor
{

public:
	int FT = 0;
	bool BUSY = false;
	process* RUN;

	virtual void schedulago()=0;
	virtual void push(process*p)=0;
	virtual Queue<int> GetID()=0;
	virtual int GetWT()=0;


private:
};


