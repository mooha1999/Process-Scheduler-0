#include <iostream>
#include <fstream>
#include <vector>
#include "process.h"
#include <string>
#include <sstream>
#include "Queue.h"
#include "Pair.h"
#include "Scheduler.h"
#pragma
#pragma once

using namespace std;

//function for ready list, generating random values
void probRDY(Process x) {
	int p = rand() % 100;
	//for () { iteration on all process from input file
	if (p >= 1 && p <= 15) {
		//LinkedList::movenode(process** BLK, process **RUN); function from linkedlist class
	}
	if (p >= 20 && p <= 30) {}
	if (p >= 50 && p <= 60) {}
	//}
};

void probBLK() {
	int p = rand() % 100;
	if (p < 10) {}
};

int main()
{
	/*Scheduler* scheduler = new Scheduler();
	scheduler->readFile();
	scheduler->simulate();*/
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Remove(2);
	for (int i : q)
		cout << i << ' ';
	return 0;
}