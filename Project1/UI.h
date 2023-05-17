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
//used for sleep function for delay in step by step
//Sleep (1000); for one second 1000 millisecond 
#include <stdlib.h> //library for abort function

using namespace std;

class UserInterface {
public:
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
	

	void display(int timestep, Queue<Processor*> Fcfs, Queue<Processor*>Sjf, Queue<Processor*>Rr) // to get user what mood does the user need
	{
			if (choice == 1)
			{
				interactivemode( timestep, Fcfs,Sjf, Rr);
			}
			else if (choice == 2)
			{
				stepbystep(timestep, Fcfs, Sjf, Rr);
			}
			else if (choice == 3)
			{
				silentmode();
			}
	}



	void interactivemode(int timestep, Queue<Processor*> Fcfs, Queue<Processor*>Sjf, Queue<Processor*>Rr)
	{
		cout << "You choose Interactive mode." << "\n";
		cout << "Current Timestep:" << "  " << timestep<<"\n";
		cout << "------------    RDY Processes -----------" << "\n";
		Queue<int> ids;
		int counter = 0;
		//Printing processes from FCFS
			cout << "processor 1 [FCFS]: "; //then cout number of processors
			cout << "RDY: ";
		for (Processor* i : Fcfs)
		{
			ids = i->GetID();
			cout << "processor 1 [FCFS]: " << "number of processes" << "RDY: ";
			int counter = ids.Count(); //return the num of ids in the queue
			cout << counter << '  ';
			for (int j : ids)
			{
				
				cout << j << ' , ';
				
			}
			cout << "\n";
		}

		//pause until enter key is pressed 
		system("pause");

		//Printing processes from SJF processor 
		cout << "processor 2 [SJF ]: "; //then cout number of processors
		cout << "RDY: ";

		for (Processor* i : Sjf)
		{
			ids = i->GetID();
			cout << "processor 2 [SJF ]: " << "number of processes" << "RDY: ";
			int counter = ids.Count();
			cout << counter << '  ';
			for (int j:ids)
			{
				cout << j << ' , ';
			}
			cout << "\n";
		}

		//pause until enter key is pressed 
		system("pause");

		//Printing processes from RR processor 
		cout << "processor 3 [RR  ]: "; //cout the number of processors 
		cout << "RDY: ";

		for (Processor* i : Rr)
		{
			ids = i->GetID();
			int counter = ids.Count(); 
			cout << counter << '  ';
			for (int j : ids)
			{
				cout << j << ' , ';
			}
			cout <<' '<< counter << "\n";
		}

		//pause until enter key is pressed 
		system("pause");
		
		cout << "-------------   BLK Processes ----------" << "\n";
		cout << "number of processes from blk" << "BLK: " << "IDs of processes in blk";

		//pause until enter key is pressed 
		system("pause");

		cout << "-------------   RUN Processes ----------" << "\n";
		cout << "number of processes in run" << "RUN: "; //for loop for run display
		//the three processors have the same counter 
		//printing for running processes for FCFS
		int j = 1;
		for (Processor* i : Fcfs)
		{
			cout << i->getidrun() << "(p" << j << ")"<<" , ";
			j++;
		}


		//printing for running processes for SJF
		for (Processor* i : Sjf)
		{
			cout << i->getidrun() << "(p" << j << ")" << " , ";
			j++;
		}
		cout << "\n";

		//printing for running processes for RRobin
		for (Processor* i : Rr)
		{
			cout << i->getidrun() << "(p" << j << ")" << " , ";
			j++;
		}
		cout << "\n";



		//pause until enter key is pressed 
		system("pause");

		cout << "------------    TRM Processes ----------" << "\n";
		cout << "number of processes in run" << "RUN: " << ""; //for loop for trm display
		cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !";

		//pause until enter key is pressed 
		system("pause");
	} 


	void silentmode(){
		cout << "You choose Silent mode." << "\n";
		cout << "--------Silent Mode-------" << "\n";
		cout << "Simulation Starts" << "\n";
		//calls scheduler class to print output text file

		cout << "Simualtion ends. Output file created.";
	}
	
	
	void stepbystep(int timestep, Queue<Processor*> Fcfs, Queue<Processor*>Sjf, Queue<Processor*>Rr)
	{
		cout << "You choose Interactive mode." << "\n";
		cout << "Current Timestep:" << "  " << timestep << "\n";
		cout << "------------    RDY Processes -----------" << "\n";
		Queue<int> ids;
		int counter = 0;
		//Printing processes from FCFS
		cout << "processor 1 [FCFS]: "; //then cout number of processors
		cout << "RDY: ";
		for (Processor* i : Fcfs)
		{
			ids = i->GetID();
			cout << "processor 1 [FCFS]: " << "number of processes" << "RDY: ";
			int counter = ids.Count(); //return the num of ids in the queue
			cout << counter << '  ';
			for (int j : ids)
			{

				cout << j << ' , ';

			}
			cout << "\n";
		}

		//pause until enter key is pressed 
		Sleep(1000);

		//Printing processes from SJF processor 
		cout << "processor 2 [SJF ]: "; //then cout number of processors
		cout << "RDY: ";

		for (Processor* i : Sjf)
		{
			ids = i->GetID();
			cout << "processor 2 [SJF ]: " << "number of processes" << "RDY: ";
			int counter = ids.Count();
			cout << counter << '  ';
			for (int j : ids)
			{
				cout << j << ' , ';
			}
			cout << "\n";
		}

		//pause until enter key is pressed 
		Sleep(1000);

		//Printing processes from RR processor 
		cout << "processor 3 [RR  ]: "; //cout the number of processors 
		cout << "RDY: ";

		for (Processor* i : Rr)
		{
			ids = i->GetID();
			int counter = ids.Count();
			cout << counter << '  ';
			for (int j : ids)
			{
				cout << j << ' , ';
			}
			cout << ' ' << counter << "\n";
		}

		//pause until enter key is pressed 
		Sleep(1000);

		cout << "-------------   BLK Processes ----------" << "\n";
		cout << "number of processes from blk" << "BLK: " << "IDs of processes in blk";

		//pause until enter key is pressed 
		Sleep(1000);

		cout << "-------------   RUN Processes ----------" << "\n";
		cout << "number of processes in run" << "RUN: "; //for loop for run display
		//the three processors have the same counter 
		//printing for running processes for FCFS
		int j = 1;
		for (Processor* i : Fcfs)
		{
			cout << i->getidrun() << "(p" << j << ")" << " , ";
			j++;
		}


		//printing for running processes for SJF
		for (Processor* i : Sjf)
		{
			cout << i->getidrun() << "(p" << j << ")" << " , ";
			j++;
		}
		cout << "\n";

		//printing for running processes for RRobin
		for (Processor* i : Rr)
		{
			cout << i->getidrun() << "(p" << j << ")" << " , ";
			j++;
		}
		cout << "\n";



		//pause until enter key is pressed 
		Sleep(1000);

		cout << "------------    TRM Processes ----------" << "\n";
		cout << "number of processes in run" << "RUN: " << ""; //for loop for trm display
		cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !";

		//pause until enter key is pressed 
		Sleep(1000);
		system("pause");
	}
	void exit()
	{ //aborts program completely
		abort();
	}

};
