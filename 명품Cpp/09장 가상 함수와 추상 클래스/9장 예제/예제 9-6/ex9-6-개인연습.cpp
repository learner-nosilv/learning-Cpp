/* 454p.�߻� Ŭ���� ���� ����
* �߻�Ŭ����(Calculator)�� ��ӹ��� Ŭ����(GoodCalc) �����ϱ�
*/
#include <iostream>
using namespace std;

class Calculator {									// Abstract class 
public:
	virtual int add(int a, int b) = 0;				// pure virtual function ���� ��
	virtual int subtract(int a, int b) = 0;			// pure virtual function ���� ��
	virtual double average(int a[], int size) = 0;	// pure virtual function �迭 ���
};

class GoodCalc : public Calculator {
	virtual int add(int a, int b) { return a + b; }			// pure virtual function ����
	virtual int subtract(int a, int b) { return a - b; }	// pure virtual function ����
	virtual double average(int a[], int size) {				// pure virtual function ����
		int total = 0;
		for (int i = 0; i < size; i++) total += a[i];
		return (double)total / size;
	}
};

int main() {
	Calculator* p = new GoodCalc();		// Upcasting
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	int a[] = { 1, 2, 3, 4, 5 };
	cout << p->average(a, 5) << endl;
	delete p;
	return 0;
}