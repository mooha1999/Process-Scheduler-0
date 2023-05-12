#pragma once
#include "processor.h"
#include"process.h"
#include"Queue.h"
//fffff
class RRobin
{
public:

    Queue<process*> Rdy;
    process* RUN;
    process* Finish;
    int time_slice;
    int Num_of_jobs;
    void push(process*p )
    {
        Rdy.Push(p);
    }
    void schedulago()
    {

        if (!RUN)
        {
            RUN = Rdy.Pop();   //return the value of the firt process in rdy list
        }
        else  
        {  
            if (RUN->getEX()==RUN->getCT()) 
            {
                Finish = RUN;
                RUN = nullptr;
            }
            //case 1  if the execution time is equal to time slicev
            if (RUN->getEX() % time_slice == 0) // reminder ( 
            {
                RUN->incEX(); // hna 34an mayd5ol4 be nafs el ex-time (resulting infinte loop)
                Rdy.Push(RUN);
                RUN = nullptr; 
            }
            // case 2
            else
            {
                RUN->incEX();
            }
        }

        




    }






};
