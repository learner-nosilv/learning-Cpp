#ifndef MYSTACK_H
#define MYSTACK_H
class MyStack {
	int data[100];
	int tos;		// top of stack: ºó °÷
public:
	MyStack() { tos = 0; }
	void push(int n) throw(char*);
	int pop() throw(char*);
};
#endif // !MYSTACK_H