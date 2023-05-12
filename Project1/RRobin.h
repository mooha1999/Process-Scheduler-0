#pragma once
#include "processor.h"
#include"process.h"
#include"Queue.h"

//fffff
class RRobin 
{
public:

    Queue<process> Rdy;
    process* RUN;
    int time_slice;
    int Num_of_jobs;

   void schedulago()
   {

      RUN=Rdy.Pop();   //return the value of the firt process in rdy list
   
       //case 1  if the execution time is equal to time slice

       if (RUN->getEX()== time_slice)
       {
           Rdy.Push(RUN);
       }
       // case 2
       else  (RUN->getEX() != time_slice|| RUN->getEX() < time_slice)
       {
           RUN->incEX();

       }


     

   }




 
   
};
