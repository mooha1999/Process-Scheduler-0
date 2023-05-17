#pragma once
#include <fstream>
#include <string>
#include <sstream>

#include "Queue.h"
#include "FCFS.h"
#include "SJF.h"
#include "RRobin.h"
#include "processor.h"
#include "BlockedProcesses.h"
#include "UI.h"
using namespace std;
class Scheduler {
	Queue<Process*> NEW;
	Blocked* BLK = new Blocked();
	PriortyQueue<Process*> TRM;
	Queue<Pair<int, int>*> sigKills;
	Queue<Processor*> Processors;
	Queue<FCFS*> fcfss;
	Queue<SJF*> sjfs;
	Queue<RRobin*> rrobins;
	UserInterface ui;
	int rtf, maxW, stl, forkProbability;
	int lastID;
	int totalProcessesNum = 0, totalKilled = 0, totalForked = 0;
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

			if (nums.Count() > 1) {
				while (!nums.IsEmpty()) {
					int f = nums.Pop();
					int s = nums.Pop();
					ios.Push(new Pair<>(f, s));
				}
			}
			// Add the pair to the vector

			NEW.Push(new Process(pid, at, ct, ios));
			lastID = pid; //To generate unique ids for the forked processes
		}
	}
	void scheduleAlgo(int timestep)
	{
		for (Processor* p : Processors) {
			p->schedulago(timestep);
			Process* finishedProcess = p->Finish;
			if (finishedProcess) {
				TRM.Push(finishedProcess, finishedProcess->getTT() * -1);
				p->Finish = nullptr;
			}
			Process* blockedProcess = p->Blk;
			if (blockedProcess) {//TODO tell ganna/nouran to make it a getter
				BLK->AddProcess(blockedProcess);
				p->Blk = nullptr;
			}
		}
	}
	void killSignal(int timestep)
	{
		while (!sigKills.IsEmpty() && sigKills.Peek()->first == timestep) {
			Process* killedProcess = getKilledProcess(sigKills.Pop()->first);
			if (killedProcess) {
				killedProcess->setTT(timestep);
				totalKilled++;
				TRM.Push(killedProcess, killedProcess->getTT());
			}
		}
	}
	void forkProcesses(int timestep)
	{
		for (Processor* p : fcfss) {
			if (p->RUN && shouldFork()) {
				Process* forkedProcess = p->RUN->fork(timestep, ++lastID);
				getLeastWaitingFCFSProcessor()->push(forkedProcess);
				totalProcessesNum++;
				totalForked++;
			}
		}
	}
	Processor* getLeastWaitingProcessor() {
		Processor* temp = nullptr;
		int wt = INT_MAX;
		for (auto i : Processors) {
			if (i->GetTWT() < wt) {
				wt = i->GetTWT();
				temp = i;
			}
		}
		return temp;
	}
	Processor* getLeastWaitingFCFSProcessor() {
		Processor* temp = nullptr;
		int wt = INT_MAX;
		for (auto i : fcfss) {
			if (i->GetTWT() < wt) {
				wt = i->GetTWT();
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
				//p->RUN()
			}
		}
	}
	bool shouldFork() {
		return rand() % 100 < forkProbability;
	}
	void generateOutputFile(int timestep) {
		ofstream out("output.txt");
		int twt = 0, trt = 0, ttrt = 0;
		out << "TT\tPID\tAT\tCT\tIO_D\tWT\tRT\tTRT\n";
		for (auto p : TRM) {
			out << p->getTT() << '\t';
			out << p->getPID() << '\t';
			out << p->getAT() << '\t';
			out << p->getCT() << '\t';
			out << p->getTIOD() << '\t';
			out << p->getWT() << '\t';
			out << p->getRT() << '\t';
			out << p->getTRT() << '\n';
			twt += p->getWT();
			trt += p->getRT();
			ttrt += p->getTRT();
		}

		out << "Processes: " << totalProcessesNum << '\n';

		out << "Avg WT = " << twt / totalProcessesNum << '\t';
		out << "Avg RT = " << trt / totalProcessesNum << '\t';
		out << "Avg TRT = " << ttrt / totalProcessesNum << '\t';

		out << "Forked Processes: " << (totalForked / totalProcessesNum) * 100 << '\n';
		out << "Killed Processes: " << (totalKilled / totalProcessesNum) * 100 << '\n';

		out << "Processors: " << Processors.Count() << " [";
		out << fcfss.Count() << " FCFS, ";
		out << sjfs.Count() << " SJF, ";
		out << rrobins.Count() << " RR]\n";

		out << "Processors Load\n";
		int i = 1;
		for (auto p : Processors) {
			out << 'p' << i++ << '=' << (p->GetBusyTime() / p->GetTRT()) * 100 + '\t';
		}
		out << "\nProcessors Utiliz\n";
		i = 0;
		int totalUtil = 0;
		for (auto p : Processors) {
			int util = (p->GetBusyTime() / timestep) * 100;
			totalUtil += util;
			out << 'p' << i++ << '=' << util + '\t';
		}
		out << "\nAvg utilization = " << (totalUtil / Processors.Count()) * 100;
	}
	bool isAllEmpty() {
		for (auto p : Processors) {
			if (p->RUN)
				return false;
			if (p->GetCount() > 0)
				return false;
		}
		return true;
	}
public:
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
	void StartSimulation() {
		int timestep = 0;
		ui.displayMainMenu();
		ui.getUserInput();
		while (!NEW.IsEmpty() || !BLK->IsEmpty() || !sigKills.IsEmpty() || !isAllEmpty()) {
			//from NEW to RDY, a while loop because there might be more than one process arriving at the same time
			while (!NEW.IsEmpty() && NEW.Peek()->getAT() == timestep) {
				Processor* leastProcessor = getLeastWaitingProcessor();
				leastProcessor->push(NEW.Pop());
			}
			//from BLK to RDY
			if (BLK->GetFinishedProcess()) {
				getLeastWaitingProcessor()->push(BLK->GetFinishedProcess());
			}
			//killing signals
			killSignal(timestep);
			//forking process
			forkProcesses(timestep);
			//Schedule algorithms
			scheduleAlgo(timestep);
			//Increment IO time for blocked process
			BLK->ScheduleAlgo();
			Process* finishedBlockedProcess = BLK->GetFinishedProcess();
			if (finishedBlockedProcess) {
				getLeastWaitingProcessor()->push(finishedBlockedProcess);
			}
			ui.display(timestep, fcfss, sjfs, rrobins, BLK, TRM);
			timestep++;
		}
		generateOutputFile(timestep);
		ui.displayEndLine();
	}
};