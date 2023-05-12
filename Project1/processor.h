#include "process.h";
class Processor
{
public:
	int FT = 0;
	bool BUSY = false;
	process RUN;
	Processor();
	virtual void SchaduelAlgo();
	virtual void push(process p);
	~Processor();


private:

};

Processor::Processor()
{
}

void Processor::push(process p) {}
void Processor::SchaduelAlgo() {}

Processor::~Processor()
{
}

