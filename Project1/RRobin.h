#pragma once
#include "processor.h"
#include <string>
#include"process.h"
#include"cicularqueue.h"
//fffff
class RRobin 
{
public:

    Circularqueue Rdy;
    process* RUN;
    int time_slice;
    int Num_of_jobs;

   void schedulago()
   {

    if (Rdy.Isempty())
    {
      return;
    }
    else
    {

      RUN=Rdy.front(RUN);
       Rdy.pop();
       //case 1  if the execution time is equal to time slice

       if (RUN->getEX()== time_slice)
       {
           rdy.rear(RUN);
       }
       else if (RUN->getCT() != time_slice|| RUN->getCT() < time_slice)
       {
           RUN->incEX();

       }


     }

   }




 
   
};