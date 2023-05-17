#pragma once
#include <iostream>
#include "Scheduler.h"
#include "FCFS.h"
#include "process.h"
#include "processor.h"
#include "SJF.h"
#include "RRobin.h"
#include "Queue.h"
#include <string>
#include<windows.h>
#include "BlockedProcesses.h"
//used for sleep function for delay in step by step
//Sleep (1000); for one second 1000 millisecond
#include <stdlib.h> //library for abort function

using namespace std;

class UserInterface {
public:
	UserInterface* UI;
	int choice; //user choice from main menu

	void displayMainMenu()
	{
		cout << "Process Scheduler Program \n";
		cout << "Please choose from the interface modes: \n";
		cout << "1. Interactive mode.\n";
		cout << "2. Step-by-step mode. \n";
		cout << "3. Silent mode. \n";
		cout << "4. Exit the program.\n";
	}

	int getUserInput()
	{
		cout << "Enter your choice: ";
		cin >> choice;

		if (choice < 1 || choice >3) // if he choose any number which is not between 1 and 3
		{
			cout << " Not a Valid Choice ";
		}
		else
		{
			return choice;
		}
	}

	void display(int timestep, Queue<FCFS*> Fcfs, Queue<SJF*>Sjf, Queue<RRobin*>Rr, Blocked* BLK) // to get user what mood does the user need
	{
		if (choice == 1 || choice == 2)
		{
			activemode(timestep, Fcfs, Sjf, Rr, BLK); //either interactive or stepbystep
		}
		else if (choice == 3)
		{
			silentmode();
		}
		else
		{
			exit();
		}
	}

	void activemode(int timestep, Queue<FCFS*> Fcfs, Queue<SJF*>Sjf, Queue<RRobin*>Rr, Blocked* BLK)
	{
		cout << "Current Timestep:" << "  " << timestep << "\n";
		cout << "------------    RDY Processes -----------" << "\n";
		Queue<int> ids;
		int c = 1;
		for (FCFS* i : Fcfs)
		{
			ids = i->GetID();
			cout << "processor " << c++ << " [FCFS]: ";
			int counter = ids.Count(); //return the num of ids in the queue
			cout << counter << " ";
			cout << "RDY: ";
			for (int j : ids)
			{
				cout << j << ", ";
			}
			cout << "\n";
		}

		for (SJF* i : Sjf)
		{
			ids = i->GetID();
			cout << "processor " << c++ << "[SJF ]: ";
			int counter = ids.Count();
			cout << counter << " ";
			cout << "RDY: ";
			for (int j : ids)
			{
				cout << j << ", ";
			}
			cout << "\n";
		}

		for (RRobin* i : Rr)
		{
			ids = i->GetID();
			cout << "processor " << c++ << "[RR ]: ";
			int counter = ids.Count();
			cout << counter << " ";
			cout << "RDY: ";
			for (int j : ids)
			{
				cout << j << ", ";
			}
			cout << "\n";
		}

		//-----------------------------------------------------------------------------------------
		cout << "-------------   BLK Processes ----------" << "\n";
		cout << BLK->BlockedIDsCount() << " BLK: " << BLK->BlockedIDs();

		//----------------------------------------------------------------------------------------

		cout << "-------------   RUN Processes ----------" << "\n";
		int TNumP = Fcfs.Count() + Sjf.Count() + Rr.Count(); //total number of processors
		cout << TNumP << "RUN: "; //for loop for run display

		//the three processors have the same counter
		//printing for running processes for FCFS
		int j = 1;
		for (FCFS* i : Fcfs)
		{
			cout << i->Getidrun() << "(p" << j << ")" << " , ";
			j++;
		}
		cout << "\n";

		//printing for running processes for SJF
		for (SJF* i : Sjf)
		{
			cout << i->Getidrun() << "(p" << j << ")" << " , ";
			j++;
		}
		cout << "\n";

		//printing for running processes for RRobin
		for (RRobin* i : Rr)
		{
			cout << i->Getidrun() << "(p" << j << ")" << " , ";
			j++;
		}
		cout << "\n";

		//------------------------------------------------------------------------------------------

		cout << "------------    TRM Processes ----------" << "\n";
		cout << "number of processes in run" << "RUN: " << ""; //for loop for trm display
		//priority queue of processes, .count for TRM processes
		//print IDs using for loop
		endline();
	}

	void silentmode() {
		cout << "You choose Silent mode." << "\n";
		cout << "--------Silent Mode-------" << "\n";
		cout << "Simulation Starts" << "\n";
	}
	void exit()
	{ //aborts program completely
		abort();
	}

	void pausesleep() { //depending on user choice, program either sleep or pause
		if (choice == 1) { //interactive mode waits for key
				//pause until enter key is pressed
			system("pause");
		}
		else if (choice == 2) { //step by step mode waits for 1 second and continues automatically
			Sleep(1000);
		}
	}

	void endline() { //in either modes interactive or stepbystep, this line is printed
		//and the program waits for the user's key press

		cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !";
		system("pause");
	}

	void displayEndLine() { //ending simulation message
		cout << "Simualtion ends. Output file created.";
		system("pause");
	}
};
