//nouran wisam 
#include <iostream>
#include <fstream>
#include "process.h"
#include <string>
#include <sstream>
#include "Queue.h"
#include "Pair.h"
#include "Scheduler.h"
#include "UI.h"
#include <stdlib.h>

#pragma once

using namespace std;
void main() {

	UserInterface UI;
	
	UI.displayMainMenu(); //user chooses a mode 
	UI.getUserInput(); //now we have user's choice 
	int x = UI.getUserInput(); //now user's choice assigned to x

	system("cls"); // clear the screen for better UX :) 

	//UI.display(_____); //fill in by inputs for function

	UI.endline(); //line: "PRESS ANY KEY...."

	//functions by scheduler that prints out the output files


	
};