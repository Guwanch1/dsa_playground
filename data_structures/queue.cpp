#include "queue.h"
#include<iostream>

bool Queue::isEmpty() {
	return q.empty();
}

void Queue::enqueue(int x) {
	q.push_back(x);
}

bool Queue::dequeue() {
	if(q.empty()) return false;
	q.erase(q.begin());
	return true;
}

bool Queue::getFront(int& val) {
	if(q.empty()) return false;
	val = q.front();
	return true;
}

void Queue::display() {
	for(int i=0; i<q.size(); i++) std::cout << q[i] << " ";
	std::cout << "\n";
}