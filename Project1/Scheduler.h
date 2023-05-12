#pragma once
#include <fstream>

#include "Queue.h"
#include "process.h"
#include "FCFS.h"
#include "SJF.h"
#include "RRobin.h"
#include "processor.h"
class Scheduler {
	Queue<process> NEWprocesses;
	FCFS* fcfss;
	SJF* sjfs;
	RRobin* rrobins;
	int rtf, maxW, stl, forkProbability;
	void readFile() {
		fstream inputFile("input.txt");
		defineProcessors(inputFile);
		inputFile >> rtf >> maxW >> stl >> forkProbability;
		int n;
		inputFile >> n;
	}
	void defineProcessors(fstream& inputFile) {
		int a, b, c;
		inputFile >> a >> b >> c;
		fcfss = new FCFS[a];
		sjfs = new SJF[b];
		rrobins = new RRobin[c];
		int time_slice;
		inputFile >> time_slice;
	}
};