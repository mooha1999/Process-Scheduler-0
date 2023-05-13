#include "process.h"
class LinkedList {
public:
	Process* head;
	LinkedList();
	void insertprocess(int val);
	void displayList();
	void movenode(Process** destination, Process** source);
};
