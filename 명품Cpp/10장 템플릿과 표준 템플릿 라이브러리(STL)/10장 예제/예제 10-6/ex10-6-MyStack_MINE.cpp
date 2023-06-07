/* ���� 10-6. Stack Ŭ������ Template�� ����Ͽ� Generic�ϰ� �ۼ��ϱ� */
#include <iostream>
using namespace std;

// 1. Generic Class Declaration
template <class T>					// Ÿ���� T�� ������ ���ø�
class MyStack {						//	: Ŭ������ �����
	int tos;						// Top of Stack
	T data[100];					// TŸ���� �迭, ũ��� 100
public:
	MyStack();
	void push(T element);			// T type�� ���Ҹ� data[]�� ����
	T pop();						// T type�� �����͸� data[]���� �����ϰ� ����
};

// 2. Generic function Implementation
template <class T>					// Ÿ���� T�� ������ ���ø�
MyStack<T>::MyStack() {				// ���ø����� ������ MyStackŬ������ :: MyStack() �Լ� ����
	tos = -1;						// ����ִ� ����
}

template <class T>					// Ÿ���� T�� ������ ���ø�
void MyStack<T>::push(T element) {	// ���ø����� ������ MyStackŬ������ :: push() �Լ� ����
	if (tos == 99) {				// �������ִ� ������ ���
		cout << "stack full";
		return;
	}								// ���������� ���� ������ ���
	tos++;							// ������ top �ε��� ����
	data[tos] = element;			// ������ top�� ���� �Ҵ�
}

template <class T>					// Ÿ���� T�� ������ ���ɸ�
T MyStack<T>::pop() {				// ���ø����� ������ MyStackŬ������ :: pop() �Լ� ����
	if (tos == -1) {				// ����ִ� ������ ���
		cout << "stack Empty";
		return -1;
	}								// ������� ���� ������ ���
	T element = data[tos];			// pop�ؾ��� ���Ҹ� ����
	tos--;							// ������ top �ε��� ����
	return element;					// pop�ؾ��� ���� ����
}

// 3. Using Generic Class & Function
int main() {
	MyStack<int> iStack;			// T�� int�� ��üȭ�� MyStack Ŭ������ ��ü ����
	iStack.push(1);
	cout << iStack.pop() << endl;
	cout << iStack.pop() << endl;

	MyStack<double> dStack;			// T�� double�� ��üȭ�� MyStack Ŭ������ ��ü ����
	dStack.push(1.1);
	cout << dStack.pop() << endl;

	MyStack<char>* pCStack = new MyStack<char>();			// T�� char�� ��üȭ�� MyStack Ŭ������ �����Ϳ� ��ü �����Ҵ�
	pCStack->push('a');
	cout << pCStack->pop() << endl;
	return 0;
}