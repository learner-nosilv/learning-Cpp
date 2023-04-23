/* 9.
Ŭ���� Accumulator�� add()�Լ��� ���� ��� ���� �����ϴ� Ŭ���� - �����ϱ�
*/

#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value) { this->value = value; }
	Accumulator& add(int n);
	int get() { return value; }
};

Accumulator& Accumulator::add(int n) {
	value += n;		// �� ��ü�� value ����
	return *this;	// �� ��ü ����
}

int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7);	// add()�� �� ��ü�� �����ؾ���
	cout << acc.get();
	return 0;
}

// solution�̶� ���� ���� ���� 