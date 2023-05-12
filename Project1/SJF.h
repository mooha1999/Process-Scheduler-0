#include "processor.h"
#include"process.h"
#include"PriortyQueue.h"

class SJF :public Processor
{
 public:

    PriortyQueue<process*>* Rdy;
    process* Finish;

   
    
    virtual void push(process* p)
    {
        Rdy->Push(p,p->getCT()); // take the process and the cpu time 
    }
    virtual void schedulago()
    {
        if (!RUN)
        {
            RUN = Rdy->Pop();   //return the value of the firt process in rdy list
        }
        else
        {

            BUSY = true; //busy when running 
            TBT++; //total busy time

            if (RUN->getEX() == RUN->getCT())
            {
                AR = AR + RUN->getTRT();
                Finish = RUN;
                RUN = nullptr;
            }
            else
            {
                RUN->incEX();
            }
        }


    }

    Queue<int> GetID()
    {
        PriortyQueue<process*>temp = *Rdy;
        Queue<int>ID;
        while (temp.IsEmpty())
        {
            int x = temp.Pop()->getPID();  //return id 
            ID.Push(x);
        }

    }
    virtual int GetWT()
    {
        PriortyQueue<process*>temp = *Rdy;
        int SumWT = 0;
        while (!temp.IsEmpty())
        {
            int x = temp.Pop()->getWT();  //return waiting time 
            SumWT = SumWT + x;
        }
        return SumWT;

    }

};