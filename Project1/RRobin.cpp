#include <iostream>
using namespace std;
#include"RRobin.h"


void RRobin::settimeSlice(int TS)
{
	time_slice = TS;
}
void RRobin::Add_process(process * data)  //insert the process in te rdy list 
{
	Rdy.insertprocess(data);
}
void RRobin::schedulealgo() //here i need to calculate num_of_jobs that will done
{
	

}


//Circular queue
   
	

