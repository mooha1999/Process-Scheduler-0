#pragma once
#include "FCFS.h"
class Blocked
{
	Queue<Process*> blockedProcesses;
	Process* running;
	Process* finished;
public:
	void AddProcess(Process* process) {
		blockedProcesses.Push(process);
	}
	void ScheduleAlgo() {
		if (!running && !blockedProcesses.IsEmpty()) {
			running = blockedProcesses.Pop();
			finished = nullptr;
		}
		else if (running->getIOT() == running->getPairs().Peek()->second) {
			finished = running;
			running = nullptr;
		}
		else if (running->getIOT() < running->getPairs().Peek()->second) {
			running->incIOT();
			finished = nullptr;
		}
	}
	Process* getCurrentProcess() {
		return running;
	}
	Process* getFinishedProcess() {
		return finished;
	}
	bool IsEmpty() {
		return blockedProcesses.IsEmpty();
	}
};
