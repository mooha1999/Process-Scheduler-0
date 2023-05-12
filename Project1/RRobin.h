#pragma once
#include "processor.h"
#include <string>
#include "LinkedList.h"
#include"process.h"

class RRobin 
{
public:

    Cirularqueue Rdy;
    process* RUN;
    int time_slice;
    int Num_of_jobs;
    
    void Add_process(process *data); //add data in the linkedlist of the Rdy list
    void  schedulalgo();

   void schedulago()
   {

    if (Rdy.Isempty())
    {
      return;
    }
    else
   {

    RUN=rdy.front(RUN);

    //case 1
    if(times)

   }

   }




 
   
};