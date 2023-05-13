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
	Queue<Pair<int, int>*> sigKills;
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
		}
	}
	void simulate() {
		int timestep = 0;
		while (!NEW.IsEmpty() || !BLK.IsEmpty() || !TRM.IsEmpty() || !sigKills.IsEmpty()) {
			while (!NEW.IsEmpty() && NEW.Peek()->getAT() == timestep) {
				getLeastWaitingProcessor(Processors)->push(NEW.Pop());
			}
			while (true)
			{
			}
			timestep++;
		}
	}
	Processor* getLeastWaitingProcessor(Queue<Processor*> Processors) {
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
};