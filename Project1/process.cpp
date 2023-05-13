//written by nouran wisam
#include "process.h"

Process::Process(int pid, int at, int ct, Queue<Pair<int, int>*> q) {
	PID = pid;
	AT = at;
	CT = ct;
	Q = q;
	EX = 0; //execution time starting from zero
	Process* kid = nullptr;
	RT = 0; //response time
	TT = 0; //termination time
	//TRT = TT - AT; //turnaround duration
	//WT = TRT - CT; //waiting time
	//N = 1; //number of times the process requests the io
}

//Process::Process() {
//}

int Process::getIOT()
{
	return IOT;
}

int Process::getPID() {
	return PID;
}
int Process::getAT() {
	return AT;
}
int Process::getRT() {
	return RT;
}
int Process::getTT() {
	return TT;
}
int Process::getCT() {
	return CT;
}
int Process::getTRT() {
	return (TT - AT);
}
int Process::getWT() {
	return ((TT - AT) - CT);
}
int Process::getEX() {
	return EX;
}
Queue<Pair<int, int>*> Process::getPairs()
{
	return Q;
}
void Process::setPID(int id) {
	PID = id;
}
void Process::setAT(int at) {
	AT = at;
}
void Process::setRT(int rt) {
	RT = rt;
}
void Process::setCT(int ct) {
	CT = ct;
}
void Process::setIOT(int iot) {
	IOT = iot;
}
void Process::setTT(int tt) {
	TT = tt;
}
//void process::setTRT(int tt, int at) {
	//return (tt - at);
//}
//void process::setWT(int tt, int at, int ct) {
	//WT = tt - ct;
//}

void Process::incEX()
{
	EX++;
}

void Process::incIOT()
{
	IOT++;
}

//void process :: setstate(); //fn that set the process state according to variables
//void process :: getstate(); //still needs implementation

Process* Process::fork(int t, int id) {
	int oldct = getCT();
	int exe = getEX();
	int newct = oldct - exe;
	kid = new Process(id, t, newct, Queue<Pair<int, int>*>());

	return kid;
}

Process ::~Process() {
	delete next; // deallocate memory for the pointed process
	delete kid;
}