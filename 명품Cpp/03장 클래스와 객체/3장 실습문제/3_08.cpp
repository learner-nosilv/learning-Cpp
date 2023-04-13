/*
* int Ÿ���� ������ ��üȭ�� Integer Ŭ������ �ۼ��϶�
* ��� ����Լ��� �ڵ� �ζ������� �ۼ��϶�(inline Ű���带 ������� ����)
* �������: int integer;
* ����Լ�: int get(), set(), int isEven()
*/

#include <iostream>
#include <string>
using namespace std;

class Integer {
	int integer;
public:
	// ������: (�ڵ��ζ���) ���� ���� integerŸ������ ���� 1. ���ڷ� ���� �� �ִ� ���ڸ� �Է¹��� ���
	Integer(string num) { integer = stoi(num); }
	// ������: (�ڵ��ζ���) ���� ���� integerŸ������ ���� 2. integer������ �Է¹��� ���
	Integer(int num) { integer = num; }

	// integer �� ���
	int get() { return integer; }
	
	// integer �� ����
	void set(int num) { integer = num; }

	// integer ���� ¦���̸� 1, ¦���� �ƴϸ� 0���
	int isEven() {
		return (integer + 1) % 2;
	}
};

int main() {
	Integer n(30);
	cout << n.get() << ' ';	// get() return 30
	n.set(50);
	cout << n.get() << ' ';	// get() return 50

	Integer m("300");		// string type(stoi�ʿ�)
	cout << m.get() << ' ';	// get() return 300
	cout << m.isEven();		// return 0 or 1
}