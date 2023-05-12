#pragma once
#include "processor.h"
#include"process.h"
#include"Queue.h"
//fffff
class RRobin : public Processor
{
public:

    Queue<process*>* Rdy; // pointer Queue 
    process* Finish;
    int time_slice;

    virtual void push(process* p)
    {

        Rdy->Push(p);
    }
    virtual void schedulago()
    {


        if (!RUN)
        {
            RUN = Rdy->Pop();   //return the value of the firt process in rdy list
        }
        else
        {
            if (RUN->getEX() == RUN->getCT())
            {
                Finish = RUN;
                RUN = nullptr;
            }
            //case 1  if the execution time is equal to time slicev
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
        Queue<process*>temp = *Rdy;   //*Rdy to return the value of Rdy (copy)
        Queue<int>Id;
        while (temp.)
        {
            int x = temp.Pop()->getPID();  //return id 
            Id.Push(x); //push the id in the queue
        }


    }






};
