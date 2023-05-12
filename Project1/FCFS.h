#include "process.h"
class FCFS {
public:
    process* front;
    process* rear;

    FCFS();
    void enqueue(int data);
    int dequeue();
    void migrate(process x, int MaxW);
    //nouran was here 
};