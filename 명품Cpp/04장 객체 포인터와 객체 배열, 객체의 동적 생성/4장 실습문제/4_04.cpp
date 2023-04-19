/* 4.
* ���� main() �Լ��� ����ǵ��� Sample Ŭ������ �ϼ��϶�.
* 
* Sample Ŭ����
* 0) �������: �迭 ������ ���� p, �迭�� ũ�� size
* 1) �Ű������� 1���� ������ : int�� �迭 p ��������
* 2) ����Լ� void read() : Ű����� �����迭 �Է¹޾Ƽ� �迭 p�� ���ҿ� �Ҵ��ϱ�
* 3) ����Լ� void write() : �迭�� ��� ���� ȭ�� ���
* 4) ����Լ� int big() : ���� �� ���� ū �� ����
* 5) �Ҹ��� : ���������� �迭 p ��ȯ
*/

#include <iostream>
using namespace std;

class Sample {
	int* p;
	int size;
public:
	Sample(int n) {			// 1) �Ű������� 1���� ������ : int�� �迭 p ��������
		size = n;
		p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++)
		cin >> *(p + i);
}

void Sample::write() {
	for (int i = 0; i < size; i++)
		cout << *(p + i)<< ' ';
	cout << endl;
}

int Sample::big() {
	int biggest = *(p);
	for (int i = 1; i < size; i++) {
		if (biggest < *(p + i))
			biggest = *(p + i);
	}
	return biggest;
}

Sample::~Sample() {
	delete[] p;
}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "���� ū ���� " << s.big() << endl;
	return 0;
}