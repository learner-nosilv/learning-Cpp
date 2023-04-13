/* 10.
* �ټ��� Ŭ������ �����ϰ� Ȱ��
* (1) SKIP
* (2) ����ο� �����θ� ����� cpp���Ϸ� �и��ϱ�
* Ŭ������: Add, Sub, Mul, Div
* ���� �������: int a, b: operand
* ���� ����Լ�: void setValue(int x, int y): �Ű�����xy -> �������ab
*				int calculate(): ����� ����
* 
* main: ���ѷ���
*/

#include <iostream>
#include "3_10_Calculator.h"
using namespace std;

int main() {
	int x, y;
	char oper;

	while (1) {
		cout << "�� ������ �����ڸ� �Է��ϼ���>>";
		cin >> x >> y >> oper;
		switch (oper) {
			case '+':
				Add a;
				a.setValue(x, y);
				cout << a.calculate() << endl;
				break;
			case '-':
				Sub b;
				b.setValue(x, y);
				cout << b.calculate() << endl;
				break;
			case '*':
				Mul c;
				c.setValue(x, y);
				cout << c.calculate() << endl;
				break;
			case '/':
				Div d;
				d.setValue(x, y);
				cout << d.calculate() << endl;
				break;
		}
	}
	return 0;
}