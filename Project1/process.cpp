//written by nouran wisam 
#include "process.h"

process::process() { //default constructor // initialization
	PID = 1;
	AT = 1; //arrival time 
	RT = 1; //response time 
	TT = 1; //termination time 
	EX = 0; //execution time starting from zero 
	int TRT = TT - AT; //turnaround duration
	int WT = TRT - CT; //waiting time 
}
process::process(int id, int at, int ct, int n)
{
	PID = id;
	AT = at;
	CT = ct;
	N = n;
}
process::process(int id, int at, int rt, int ct, int tt) {
	PID = id;
	AT = at;
	RT = rt;
	CT = ct;
	TT = tt;
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

void process::getEX(int ex) {
	EX = ex;
}
void process::incEX(int ex) {
	EX = ex++;
}

//void process :: setstate(); //fn that set the process state according to variables
//void process :: getstate(); //still needs implementation 
