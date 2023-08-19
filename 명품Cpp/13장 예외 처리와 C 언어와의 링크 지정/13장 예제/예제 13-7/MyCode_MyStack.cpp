#include "MyStack.h"
void MyStack::push(int n) {
	if (tos == 100)	// �� �� ����
		throw "Stack Full";
	data[tos] = n;	// push
	tos++;			// tos ����
}

int MyStack::pop() {
	if (tos == 0)
		throw "Stack Empty";
	tos--;			// tos ����
	return data[tos];
}