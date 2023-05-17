#pragma once
#include "processor.h"
#include <string>
#include "LinkedList.h"
#include"process.h"
#include"Queue.h"
//fffff
class RRobin : public Processor
{
public:
	int time_slice;

			//execution time and pair comparison
			int a = RUN->getPairs().Peek()->first;
			int b = RUN->getEX();
			if (a == b)
			{
				//remove the pair from comparison
				RUN->getPairs().Pop();
			}
		}
		else
		{
			BUSY = true; //busy when running
			TBT++; //total busy time

};
