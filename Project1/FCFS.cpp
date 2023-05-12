//new update by nouran
#pragma once
#include "processor.h"
#include "qqueue.h"

class FCFS : public processor
{
private:
	queue<process*> rdy;
};