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

using namespace std;

class UserInterface {
public:

    void displayMainMenu() {
        cout << "Process Scheduler Program \n";
        cout << "Please choose from the interface modes: \n";
        cout << "1. Interactive mode.\n";
        cout << "2. Step-by-step mode. \n";
        cout << "3. Silent mode. \n";
        cout << "4. Exit the program.\n";
    }

    int getUserInput() {
        int choice; //user choice from main menu 
        cout << "Enter your choice: ";
        cin >> choice;
        return choice;
    }
    void UserInerface()
    {



   // void displayOutput(Queue<int> output) { //displays a queue of intergers
     //   for (int i : output) {
          //  cout << output.Pop() << "  ";
    //}

        void Userchoice() // to get user what mood does the user need 
        {
            int Uchoice = getUserInput();
            if (Uchoice < 1 || Uchoice >4) // if he choose any number which is not between 1 and 4
            {
                cout << " Not a Valid Choice ";
            }
            else
            {
                if (Uchoice == 1)
                {

                }
                else if (Uchoice == 2)
                {

                }
                else if (Uchoice == 3)
                {
                }
            }

        }


<<<<<<< HEAD
    

    void interfacemode(int timestep, Queue<int>IDFCFS, Queue<int>IDSJF, Queue<int>IDRR) {
        cout << "Current Timestep:" << "  " << timestep;
=======

        void displayErrorMessage(string message)
        {
            cout << "Error: " << message << "\n";
        }

    void interfacemode() {
        cout << "Current Timestep:" << "  " << Scheduler.timestep;
>>>>>>> 969ab5cc5e6bff94db058e485a02c3d583f92747
        cout << "------------    RDY Processes -----------" << "\n";
        cout << "processor 1 [FCFS]: " << "number of processes" << "RDY: " << FCFS.GetID() << "\n";
        cout << "processor 2 [SJF ]: " << "number of processes" << "RDY: " << SJF.GetID() << "\n";
        cout << "processor 1 [RR  ]: " << "number of processes" << "RDY: " << RRobin.GetID() << "\n";
        cout << "-------------   BLK Processes ----------" << "\n";


        cout << "number of processes from blk" << "BLK: " << "IDs of processes in blk";
        cout << "-------------   RUN Processes ----------" << "\n";
        cout << "number of processes in run" << "RUN: " << ""; //for loop for run display
        cout << "------------    TRM Processes ----------" << "\n";
        cout << "number of processes in run" << "RUN: " << ""; //for loop for trm display
        cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !";
    
    } //latest update from nouran
};

