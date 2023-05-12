#include "SJF.h"

void SJF::SchaduelAlgo() {
}

void SJF::push(process* p)
{
	FT += p.getCT();
	if (!this->BUSY)
	{
		this->RUN == p;
		this->BUSY = true;
		return;
	}

	RDY.push(p);
}