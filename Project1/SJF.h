
#include "processor.h"
#include <queue>

struct CompareCPUTime {
    bool operator()(process p1, process p2)
    {
        // return "true" if "p2" is ordered
        // before "p1", for example:
        return p1.getCT() > p2.getCT();
    }
};
class SJF : Processor
{
public:
    priority_queue<process, std::vector<process>, CompareCPUTime> RDY;
    void push(process p);
    void SchaduelAlgo();
};
