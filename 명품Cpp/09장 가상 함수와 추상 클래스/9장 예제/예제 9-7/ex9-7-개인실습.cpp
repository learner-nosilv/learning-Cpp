/* 455p.�߻� Ŭ���� ���� ����
* �߻�Ŭ����(Calculator)�� ��ӹ��� Ŭ����(Adder, Subtractor) �����ϱ�
* �߻� Ŭ����: "�����ϴ�" ��� �������̽� ����
* �Ļ� Ŭ����: "�����ϴ�" �� ����/�������� Over-riding
*/

#include <iostream>
using namespace std;

class Calculator {							// Abstract class
	void input() {
		cout << "���� 2 ���� �Է��ϼ���>> ";
		cin >> a >> b;						// ���� ����Ǿ �򰥸�����, protected�� �ִ� �������
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;		// pure virtual function: ���� ��
public:
	void run() {
		input();
		cout << "���� ���� " << calc(a, b) << endl;		// �Ļ� Ŭ������ Overriding�� �䱸��
	}
};

class Adder : public Calculator {
	virtual int calc(int a, int b) { return a + b; }
};

class Subtractor : public Calculator {
	virtual int calc(int a, int b) { return a - b; }
};

int main() {
	Adder adder;
	Subtractor subtractor;

	adder.run();
	subtractor.run();
	return 0;
}