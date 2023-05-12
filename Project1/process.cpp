//written by nouran wisam 
#include "process.h"


process::process(int pid, int at, int ct, Queue<pair<int, int>> q) {
	PID = pid;
	AT = at;
	CT = ct;
	Q = q;
	EX = 0; //execution time starting from zero 
	process* kid = nullptr;
	RT = 0; //response time
	TT = 0; //termination time 
	//TRT = TT - AT; //turnaround duration
	//WT = TRT - CT; //waiting time 
	//N = 1; //number of times the process requests the io
}

process::process() {
}

int process::getPID() {
	return PID;
}
int process::getAT() {
	return AT;
}
int process::getRT() {
	return RT;
}
int process::getTT() {
	return TT;
}
int process::getCT() {
	return CT;
}
int process::getTRT() {
	return (TT - AT);
}
int process::getWT() {
	return ((TT-AT)-CT);
}
int process::getEX() {
	return EX;
}
Queue<pair<int, int>> process::getpair()
{
	return Q;
}
void process::setPID(int id) {
	PID = id;
}
void process::setAT(int at) {
	AT = at;
}
void process::setRT(int rt) {
	RT = rt;
}
void process::setCT(int ct) {
	CT = ct;
}
void process::setTT(int tt) {
	TT = tt;
}
//void process::setTRT(int tt, int at) {
	//return (tt - at);
//}
//void process::setWT(int tt, int at, int ct) {
	//WT = tt - ct;
//}


void process::incEX() 
{
	EX++;
}

//void process :: setstate(); //fn that set the process state according to variables
//void process :: getstate(); //still needs implementation 


process*process ::fork(int t, int id){
	int oldct = getCT();
	int exe = getEX();
	int newct = oldct - exe;
	kid = new process(id, t, newct, Queue<pair<int, int>>()); 

	return kid;
	
}