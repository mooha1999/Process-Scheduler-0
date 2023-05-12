#pragma once
#include "processor.h"
#include"process.h"
#include"Queue.h"
//fffff
class RRobin : public Processor
{
public:

    Queue<process*>* Rdy; // pointer Queue
    process* Finish; // this process to put the finished process
    int time_slice;
    RRobin(int TS)
    {
        TS = time_slice;
    }
    virtual void push(process* p)
    {
        Rdy->Push(p);
    }
    virtual void schedulago()
    {
        if (!RUN) // if the RUN process is not empty 
        {
            RUN = Rdy->Pop();   //return the value of the firt process in rdy list
        }
        else
        {
            BUSY = true; //busy when running 
            TBT++; //total busy time

            if (RUN->getEX() == RUN->getCT()) //Ex-time=CPU-time  
            {
                Finish = RUN;
                RUN = nullptr;

            }
            //case 1  if the execution time is equal to time slice
            if (RUN->getEX() % time_slice == 0) // reminder ( 
            {
                RUN->incEX(); // hna 34an mayd5ol4 be nafs el ex-time (resulting infinte loop)
                Rdy->Push(RUN);
                RUN = nullptr;
            }
            // case 2
            else
            {
                RUN->incEX();
            }
        }

    }
    Queue<int> GetID()
    {
        Queue<process*>temp = *Rdy;   //*Rdy to return the value of Rdy (copy the rdy queue )
        Queue<int>Ids; //Id of each process 
        while (!temp.IsEmpty())
        {
            int x = temp.Pop()->getPID();  //return id 
            Ids.Push(x); //push the id in the queue
        }
        return Ids;

    }
   virtual int GetWT()
    {
        Queue<process*>temp = *Rdy;
        int SumWT=0;
        while (!temp.IsEmpty())
        {
            int x = temp.Pop()->getWT();  //return waiting time 
            SumWT = SumWT + x;
        }
        return SumWT;

    }







};
