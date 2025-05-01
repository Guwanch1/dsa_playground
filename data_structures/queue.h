#ifndef QUEUE_H
#define QUEUE_H

#include <vector>

class Queue {
	private:
	    std::vector<int> q;

	public: 
	    bool isEmpty();
	    void enqueue(int x);
	    bool dequeue();  
	    bool getFront(int& val); 
	    void display();
};

#endif
