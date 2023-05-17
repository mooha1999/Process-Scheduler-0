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
void main() 
{
	Scheduler* scheduler = new Scheduler();
	scheduler->readFile();
	scheduler->StartSimulation();
};