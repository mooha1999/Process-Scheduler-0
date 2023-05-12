#include "processor.h"
#include"process.h"
#include"Queue.h"

class SJF :public Processor
{
 public:

    Queue<process*>* Rdy;
    process* Finish;

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
            else
            {
                RUN->incEX();
            }
        }


    }

    Queue<int> GetID()
    {
        Queue<process*>temp = *Rdy;
        Queue<int>ID;
        while (temp.IsEmpty())
        {
            int x = temp.Pop()->getPID();  //return id 
            ID.Push(x);
        }

    }
    virtual int GetWT()
    {
        Queue<process*>temp = *Rdy;
        int SumWT = 0;
        while (!temp.IsEmpty())
        {
            int x = temp.Pop()->getWT();  //return waiting time 
            SumWT = SumWT + x;
        }
        return SumWT;

    }












};