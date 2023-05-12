#pragma once
#include "processor.h"
#include <string>
#include "LinkedList.h"
#include"process.h"
#include"processor.h"
class RRobin 
{
public:
    process* front;
    process* rear;
    LinkedList Rdy;
    int time_slice;
    int Num_of_jobs;
    void settimeSlice(int TS); //timeslice 
    void Add_process(process *data); //add data in the linkedlist of the Rdy list
    void  schedulealgo();




 // for queue of RR
    RRobin();
    bool Isempty();
    void push(int val);
    int countQ();
    void delnode(int value);
    void round_robin(int time_slice);
};