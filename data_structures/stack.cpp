#include "stack.h"
#include<iostream>

Stack::Stack() {
	top = -1;
}
bool Stack::push(int x) {
	if(top >= 99) {
		return false;	
	}
	arr[++top] = x;
	return true;
}

int Stack::pop() {
	if(top < 0) return false;
	return arr[top--];
}

int Stack::peek(int& result) {
	if(top < 0) return false;
	result = arr[top];
	return true;
}

bool Stack::isEmpty() {
	return (top < 0);
}

void Stack::printStack() {
	for(int i=0; i<=top; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}