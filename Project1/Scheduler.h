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
public:
	Queue<Process*> NEW;
	Queue<Process*> BLK;
	Queue<Process*> TRM;
	Queue<pair<int, int>> sigKills;
	Queue<Processor*> Processors;
	Queue<FCFS*> fcfss;
	Queue<SJF*> sjfs;
	Queue<RRobin*> rrobins;
	int rtf, maxW, stl, forkProbability;

	void readFile() {
		fstream inputFile("input.txt", ios::in);
		defineProcessors(inputFile);
		inputFile >> rtf >> maxW >> stl >> forkProbability;
		addToNew(inputFile);
		int a, b;
		while (inputFile >> a >> b) {
			sigKills.Push(make_pair(a, b));
		}
	}
	void defineProcessors(fstream& inputFile) {
		int a, b, c, time_slice;
		inputFile >> a >> b >> c;
		while (a--) {
			FCFS* temp = new FCFS();
			fcfss.Push(temp);
			Processors.Push(temp);
		}
		while (b--) {
			SJF* temp = new SJF();
			sjfs.Push(temp);
			Processors.Push(temp);
		}
		inputFile >> time_slice;
		while (c--) {
			RRobin* temp = new RRobin(time_slice);
			rrobins.Push(temp);
			Processors.Push(temp);
		}
	}
	void addToNew(fstream& inputFile) {
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
	}
	void simulate() {
		int timestep = 0;
		while (!NEW.IsEmpty() || !BLK.IsEmpty() || !TRM.IsEmpty() || !sigKills.IsEmpty()) {
			while (!NEW.IsEmpty() && NEW.Peek()->getAT() == timestep) {
			}
			timestep++;
		}
	}
	//Processor
};