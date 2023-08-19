#include "MyStack.h"
void MyStack::push(int n) {
	if (tos == 100)	// 다 찬 상태
		throw "Stack Full";
	data[tos] = n;	// push
	tos++;			// tos 증가
}

int MyStack::pop() {
	if (tos == 0)
		throw "Stack Empty";
	tos--;			// tos 감소
	return data[tos];
}