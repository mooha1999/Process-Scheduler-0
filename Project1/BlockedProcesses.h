#pragma once
#include <string>
using namespace std;
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
			running->setIOT(0);
			finished = nullptr;
		}
		else if (running->getIOT() == running->getPairs().Peek()->second) {
			running->getPairs().Pop();
			finished = running;
			running = nullptr;
		}
		else if (running->getIOT() < running->getPairs().Peek()->second) {
			running->incIOT();
			finished = nullptr;
		}
	}
	Process* GetCurrentProcess() {
		Process* ret = running;
		running = nullptr;
		return ret;
	}
	Process* GetFinishedProcess() {
		Process* ret = finished;
		finished = nullptr;
		return ret;
	}
	bool IsEmpty() {
		return blockedProcesses.IsEmpty();
	}
	string BlockedIDs() {
		string ret = "";
		for (auto i : blockedProcesses) {
			ret += to_string(i->getPID());
			ret += ", ";
		}
		if (ret.size() > 0) {
			ret.pop_back();
			ret.pop_back();

		}
		return ret;
	}
	int BlockedIDsCount() { return blockedProcesses.Count(); }
};
