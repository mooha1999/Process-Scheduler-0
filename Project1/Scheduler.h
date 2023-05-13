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
#include "BlockedProcesses.h"

using namespace std;
class Scheduler {
public:
	Queue<Process*> NEW;
	Blocked* BLK;
	PriortyQueue<Process*> TRM;
	Queue<Pair<int, int>*> sigKills;
	Queue<Processor*> Processors;
	Queue<FCFS*> fcfss;
	Queue<SJF*> sjfs;
	Queue<RRobin*> rrobins;
	int rtf, maxW, stl, forkProbability;
	int lastID;
	void readFile() {
		fstream inputFile("input.txt", ios::in);
		defineProcessors(inputFile);
		inputFile >> rtf >> maxW >> stl >> forkProbability;
		addToNew(inputFile);
		int a, b;
		while (inputFile >> a >> b) {
			sigKills.Push(new Pair<>(a, b));
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
			Queue<Pair<int, int>*> ios;
			string pairString;
			inputFile >> pairString;
			// Remove the parentheses from the string
			pairString.erase(remove(pairString.begin(), pairString.end(), '('), pairString.end());
			pairString.erase(remove(pairString.begin(), pairString.end(), ')'), pairString.end());
			// Split the string into two integers
			stringstream ss(pairString);
			string numString;
			Queue<int>nums;
			while (getline(ss, numString, ',')) {
				nums.Push(stoi(numString));
			}
			while (!nums.IsEmpty()) {
				int f = nums.Pop();
				int s = nums.Pop();
				ios.Push(new Pair<>(f, s));
			}
			// Add the pair to the vector

			NEW.Push(new Process(pid, at, ct, ios));
			lastID = pid; //To generate unique ids for the forked processes
		}
	}
	void simulate() {
		int timestep = 0;
		while (!NEW.IsEmpty() || !BLK->IsEmpty() || !TRM.IsEmpty() || !sigKills.IsEmpty()) {
			while (!NEW.IsEmpty() && NEW.Peek()->getAT() == timestep) {
				getLeastWaitingProcessor()->push(NEW.Pop());
			}
			if (BLK->getFinishedProcess()) {
				getLeastWaitingProcessor()->push(BLK->getFinishedProcess());
			}
			while (!sigKills.IsEmpty() && sigKills.Peek()->first == timestep) {
				Process* killedProcess = getKilledProcess(sigKills.Pop()->first);
				if (killedProcess)
					TRM.Push(killedProcess, killedProcess->getTT());
			}
			for (Processor* p : fcfss) {
				if (p->RUN && shouldFork()) {
					Process* forkedProcess = p->RUN->fork(timestep, ++lastID);
					getLeastWaitingFCFSProcessor()->push(forkedProcess);
				}
			}

			timestep++;
		}
	}
	Processor* getLeastWaitingProcessor() {
		Processor* temp = nullptr;
		int wt = INT_MAX;
		for (auto i : Processors) {
			if (i->GetWT() < wt) {
				wt = i->GetWT();
				temp = i;
			}
		}
		return temp;
	}
	Processor* getLeastWaitingFCFSProcessor() {
		Processor* temp = nullptr;
		int wt = INT_MAX;
		for (auto i : fcfss) {
			if (i->GetWT() < wt) {
				wt = i->GetWT();
				temp = i;
			}
		}
		return temp;
	}
	Process* getKilledProcess(int id) {
		Process* killedProcess = nullptr;
		for (auto i : fcfss) {
			killedProcess = i->kill(id);
		}
		return killedProcess;
	}
	Process* forkedProcess() {
		for (auto p : fcfss) {
			if (p->RUN && shouldFork()) {
			}
		}
	}
	bool shouldFork() {
		return rand() % 100 < forkProbability;
	}
};