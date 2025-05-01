#ifndef STACK_H
#define STACK_H
	
	class Stack{
		private:
			int top;
			int arr[100];
		public:
			Stack();
			bool push(int x);
			int pop();
			int peek(int& result);
			bool isEmpty();
			void printStack();
	};	

#endif