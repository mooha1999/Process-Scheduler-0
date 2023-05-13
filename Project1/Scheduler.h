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
	Queue<Process*> NEW;
	Queue<Process*> BLK;
	Queue<Process*> TRM;
	Queue<pair<int, int>> sigKills;
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
		Process* tempProcess = nullptr;
		while (m--) {
			int at, pid, ct, n;
			inputFile >> at >> pid >> ct >> n;
			string line;
			getline(inputFile, line);
			Queue<pair<int, int>> ios;
			while (n--) {
				getline(inputFile, line, ',');
				line = line.substr(1);
				stringstream ss(line);
				int first, second;
				ss >> first >> second;
				ios.Push(make_pair(first, second));
			}
			NEW.Push(new Process(pid, at, ct, ios));
		}
		int a, b;
		while (inputFile >> a >> b) {
			sigKills.Push(make_pair(a, b));
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
	void simulate() {
		int timestep = 0;
		while (!NEW.IsEmpty() || !BLK.IsEmpty() || !TRM.IsEmpty() || !sigKills.IsEmpty()) {
			while (!NEW.IsEmpty() && NEW.Peek()->getAT() == timestep) {
			}
			timestep++;
		}
	}
};