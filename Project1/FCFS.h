#include "process.h"
#include "Processor.h"

class FCFS : public Processor {

public:

    Queue<process*>* Rdy; // pointer Queue 
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
        Queue<process*>temp = *Rdy;   //*Rdy to return the value of Rdy (copy)
        Queue<int>Id;
        while (temp.)
        {
            int x = temp.Pop()->getPID();  //return id 
            Id.Push(x); //push the id in the queue
        }


    }







};