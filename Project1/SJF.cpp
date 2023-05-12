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
        
    }
    virtual void schedulago()
    {



    }

    Queue<int> GetID()
    {
    }












};