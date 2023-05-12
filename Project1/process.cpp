//written by nouran wisam 
#include "process.h"

process::process() { //default constructor // initialization
	EX = 0; //execution time starting from zero 
	}
process::process(int pid, int at, int ct) {
	PID = pid;
	AT = at;
	CT = ct;
	int TRT = TT - AT; //turnaround duration
	int WT = TRT - CT; //waiting time 
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
	return TRT;
}
int process::getWT() {
	return WT;
}
int process::getEX() {
	return EX;
}
Queue<pair<int, int>> process::getpair()
{
	return q;
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
void process::setTRT(int tt, int at) {
	TRT = tt - at;
}
void process::setWT(int tt, int at, int ct) {
	WT = tt - ct;
}

void process::addpair(int r, int d)
{
	ior = r;
	iod = d;
	enqueue.make_pair<ior, iod>;


}



void process::incEX() {
	EX++;
}

//void process :: setstate(); //fn that set the process state according to variables
//void process :: getstate(); //still needs implementation 

