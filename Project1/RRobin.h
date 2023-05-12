#pragma once
#include "processor.h"
#include <string>
#include "LinkedList.h"
#include"process.h"

class RRobin 
{
public:

    LinkedList Rdy;
    int time_slice;
    int Num_of_jobs;
    void settimeSlice(int TS); //timeslice 
    void Add_process(process *data); //add data in the linkedlist of the Rdy list
    void  schedulealgo();




 
    void round_robin(int time_slice);
};