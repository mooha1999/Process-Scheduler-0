#include "SJF.h"

void SJF::SchaduelAlgo() {

}

void SJF::push(process p)
{
	FT += p.getCT();
	if (!this->BUSY)
	{
//<<<<<<< HEAD
		this->RUN =p;
//=======
		this->RUN == p;
//>>>>>>> 805a93cbe0234e2f56e141633f9f811d45909652
		this->BUSY = true;
		return;
	}

	RDY.push(p);
}