#include "process.h"
class LinkedList {
public:
    process* head;
    LinkedList();
    void insertprocess(int val);
    void displayList();
    void movenode(process** destination, process** source);
};
