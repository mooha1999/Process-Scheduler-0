#include <iostream>
#include <fstream>
#include <vector>
#include "process.h"
#include <string>
#include <sstream>
#include "LinkedList.h"
#pragma 
#pragma once

using namespace std;


//function for ready list, generating random values
void probRDY(process x) {
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

	fstream FileName;
	FileName.open("input.txt", ios::in);
	if (!FileName) {
		cout << "File doesn’t exist.";
	}

	string s;

	//first line for number of processors in each type of the three types of processor
	getline(FileName, s);
	istringstream s1(s);

	//creating lists for process status
	LinkedList RUN; //run list
	LinkedList RDY; //ready list
	LinkedList BLK; //block list
	LinkedList TRM; //termination list


	int word;

	vector<int> n_processors; //each element represents number of processors

	while (s1 >> word)
	{
		n_processors.push_back(word);
	}



	//second line is time for RR slice time.
	getline(FileName, s);

	istringstream s2(s);
	int RR_time_slice;

	s2 >> RR_time_slice;

	cout << RR_time_slice << endl;

	//third line for RTF,MaxW,STL,and Fork_Probability
	getline(FileName, s);

	istringstream s3(s);
	int RTF, MaxW, STL, fork_prob;
	s3 >> RTF;
	s3 >> MaxW;
	s3 >> STL;
	s3 >> fork_prob;

	cout << RTF << " " << MaxW << " " << STL << " " << fork_prob << endl;

	//third line for number of processes
	getline(FileName, s);
	istringstream s4(s);

	int num_processes;
	s4 >> num_processes;

	cout << num_processes << endl;

	//now we store each process values;
	vector<process> processes;
	for (int i = 0; i < num_processes; i++) {
		getline(FileName, s);
		istringstream s5(s);
		int AT, PID, CT, N;
		s5 >> AT;
		s5 >> PID;
		s5 >> CT;
		s5 >> N;

		process p(PID, AT, CT, N);
		processes.push_back(p);
	};

	

	cout << processes.size() << endl;

	FileName.close();

	return 0;
}