#pragma once
#include "processor.h"
#include <string>
#include"process.h"
//fffff
class RRobin 
{
public:

    Cirularqueue Rdy;
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

      RUN=rdy.front(RUN);
       rdy.pop();
       //case 1  if the CT is equal to time slice 
       if (RUN->getCT()== time_slice)
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