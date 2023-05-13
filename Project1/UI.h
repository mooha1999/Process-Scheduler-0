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

    void displayResults(Queue<string> results) { //need some editing here
        for (auto result : results) {
            cout << result << "\n";
        }
    }

   void displayErrorMessage(string msg) {
        cout << "Error: " << msg<< "\n";
    }

    void displaySuccessMessage(string msg) {
       cout << "Done: " << msg << "\n";
    }

    Queue<string> readInputFile(string filename) {
        Queue<string> input;
        ifstream file(filename);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
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

    void writeOutputFile(string filename, Queue<string> output) {
        ofstream file(filename);
        if (file.is_open()) {
            for (string line : output) {
                file << line << "\n";
            }
            file.close();
            displaySuccessMessage("Output is ready");
        }
        else {
            throw runtime_error("Unable to open file");
        }
    }
};

