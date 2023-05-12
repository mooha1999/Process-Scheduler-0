#pragma once
#include <fstream>
#include <string>
#include <sstream>

#include "Queue.h"
#include "process.h"
#include "FCFS.h"
#include "SJF.h"
#include "RRobin.h"
#include "processor.h"

using namespace std;
class Scheduler {
	Queue<process> NEWprocesses;
	FCFS* fcfss;
	SJF* sjfs;
	RRobin* rrobins;
	int rtf, maxW, stl, forkProbability;
	void readFile() {
		fstream inputFile("input.txt", ios::in);
		defineProcessors(inputFile);
		inputFile >> rtf >> maxW >> stl >> forkProbability;
		int m;
		inputFile >> m;
		process* tempProcess = nullptr;
		while (m--) {
			int at, pid, ct, n;
			inputFile >> at >> pid >> ct >> n;
			string line;
			getline(inputFile, line);
			while (n--) {
				getline(inputFile, line, ',');
				line = line.substr(1);
				stringstream ss(line);
			}
		}
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