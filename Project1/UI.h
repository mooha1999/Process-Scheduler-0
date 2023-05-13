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



   void displayErrorMessage(string message) {
        cout << "Error: " << message << "\n";
    }

    void displaySuccessMessage(string msg) {
       cout << "Done: " << msg << "\n";
    }

    Queue<string> readInputFile(string filename) {
        Queue<string> input;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) 
            {
                input.Push(line);
            }
            file.close();
            return input;
        }
        else {
            //if file didn't open, show error message 
            throw runtime_error("Unable to open file");
        }
    }

};

