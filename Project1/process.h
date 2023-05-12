#pragma once

#include <iostream>
#include "Queue.h"
using namespace std;


class process {

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
	Queue<pair<int, int>> Q;

public:
	//the process is a node in the queue
	int data;
	process* next;
	//this is the child created by FCFS in fork a child
	process* kid;
	process(int pid, int at, int rt, Queue<pair<int, int>> q);
	process();


	int getPID();
	int getAT();
	int getRT();
	int getTT();
	int getCT();
	int getTRT();
	int getWT();
    int getEX();
	Queue<pair<int, int>> getpair();


	void setPID(int id);
	void setAT(int at);
	void setRT(int rt);
	void setCT(int ct);
	void setTT(int tt);
	//void setTRT(int tt, int at);
	//void setWT(int tt, int at, int ct);
	//void addpair(int r, int d);




	//void setstate(); //fn that set the process state according to variables
	//void getstate();

	void incEX();

};
