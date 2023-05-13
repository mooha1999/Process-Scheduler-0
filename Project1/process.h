#pragma once

#include <iostream>
#include "Queue.h"
#include "Pair.h"
using namespace std;

class Process {
private:
	int PID; //unique identifier
	int AT; //arrival time
	int RT; //response time
	int CT; //CPU time
	int TT; //termination time
	//int TRT;//turnaround duration
	//int WT; //waiting time
	//int N; //number of times the process requests the io
	int EX;
	Queue<Pair<int, int>*> Q;
	int IOT; //io time //setter getter incremental 

public:
	//the process is a node in the queue
	int data;
	Process* next;
	//this is the child created by FCFS in fork a child
	Process* kid;
	Process(int pid, int at, int rt, Queue<Pair<int, int>*> q);



	int getIOT();
	int getPID();
	int getAT();
	int getRT();
	int getTT();
	int getCT();
	int getTRT();
	int getWT();
	int getEX();
	Queue<Pair<int, int>*> getpair();

	void setPID(int id);
	void setAT(int at);
	void setRT(int rt);
	void setCT(int ct);
	void setTT(int tt);
	//void setTRT(int tt, int at);
	//void setWT(int tt, int at, int ct);
	//void addpair(int r, int d);
	void setIOT(int iot);

	//void setstate(); //fn that set the process state according to variables
	//void getstate();

	Process* fork(int t, int id);
	void incEX();
	void incIOT();
	~Process(); //destructor
};
