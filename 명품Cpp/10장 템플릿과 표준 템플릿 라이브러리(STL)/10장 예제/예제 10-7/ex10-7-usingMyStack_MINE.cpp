/* ���� 10-7. ���� �߻�ȭ�� Ŭ���� ���� & Stack Ŭ������ �ڷ������� �� Ŭ������ �پ��� �����͸� ����غ��� */
#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { cout << '(' << this->x << ", " << this->y << ')' << endl; }
};

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
		return NULL;
	}								// ������� ���� ������ ���
	T element = data[tos];			// pop�ؾ��� ���Ҹ� ����
	tos--;							// ������ top �ε��� ����
	return element;					// pop�ؾ��� ���� ����
}

// 3. Using Generic Class & Function
int main() {

	// 1) ���׸� Ÿ���� �������� ��� 
	MyStack<int*> ipStack;			// ������ Ÿ���� int�� �������� ���� ����
	int* p = new int[3];			// ũ�Ⱑ 3�� ������ �迭 �����Ҵ�
	for (int i = 0; i < 3; i++) p[i] = i * 10;	// ���� [10, 20, 30]���� �ʱ�ȭ
	ipStack.push(p);				// �� �迭�� ����Ű�� ������ push

	int* q = ipStack.pop();			// ���ο� int�� �����Ϳ� ipStack���� pop�� ���� �Ҵ�
	for (int i = 0; i < 3; i++) cout << q[i] << ' ';
	cout << endl;					// 10, 20, 30 
	delete[] q;						// ũ�Ⱑ 3�� ������ �迭 �����Ҵ� ����

	// 2) ���׸� Ÿ���� Ư�� Ŭ������ ���

	MyStack<Point> pointStack;
	Point a(2, 3), b;				// �� �� ����
	pointStack.push(a);				// ���ÿ� �� a Ǫ��
	b = pointStack.pop();			// �� b�� ���� pop ���� �Ҵ�
	b.show();						// �� b ��� (2, 3)

	MyStack<Point*> pStack;			// ������ Ÿ���� Point�� �������� pStack ���� ����
	pStack.push(new Point(10, 20));	// �� ��ü �����Ҵ�
	Point* pPoint = pStack.pop();	// ���� �� �����͸� pPoint�� �Ҵ�
	pPoint->show();					// Point�� �����Ͱ� ����Ű�� Point�� ��ü show (10, 20)
	delete pPoint;					// �����Ҵ� ����

	MyStack<string> stringStack;	// ������ Ÿ���� string �� ���� ����
	string s = "c++";
	stringStack.push(s);				// ������ Ǫ���� �� ����
	stringStack.push("java");			// ����� Ǫ���� �� ����
	cout << stringStack.pop() << ' ';	// java
	cout << stringStack.pop() << endl;	// c++

	return 0;
}