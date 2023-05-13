#include <iostream>
#include <fstream>
#include <vector>
#include "process.h"
#include <string>
#include <sstream>
#include "Queue.h"
#include "Pair.h"
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
	Queue<Pair<>*> queue;
	queue.Push(new Pair<>(1, 2));
	queue.Push(new Pair<>(3, 4));
	queue.Push(new Pair<>(5, 6));
	for (auto i : queue) {
		cout << i->first << ' ' << i->second << endl;
	}

	return 0;
}