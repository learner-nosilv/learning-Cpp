/* ���� 13-7		����ó���� ���� int�� ���� Ŭ���� ����
	�뷮: int�� 100�� */

#include <iostream>
#include "MyStack.h"
using namespace std;

int main() {
	MyStack intStack;
	try {
		intStack.push(100);
		intStack.push(200);
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;		// ����: throw �߻��� ����
	}
	catch (const char* s) {
		cout << "���� �߻�: " << s << endl;
	}
	return 0;
}