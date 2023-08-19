/* ���� 13-5		���� �� ����� ����ó���ڵ�� ���ۼ� */
#include <iostream>
using namespace std;

int getExp(int base, int exp) {
	if (base < 0 || exp < 0) {	// ���� �˻�
		throw "���� ��� �Ұ�";	// ���� �߻�
	}
	else {
		int value = 1;
		for (int i = 0; i < exp; i++)
			value *= exp;
		return value;			// ��� ����
	}
}

int main() {
	int v = 0;
	try {
		v = getExp(2, 3);								// ���� X
		cout << "2�� 3���� " << v << "�Դϴ�." << endl;
		v = getExp(2, -3);								// ���� O -> throw "���� ��� �Ұ�"
		cout << "2�� 3���� " << v << "�Դϴ�." << endl;	// catch������ ����
	}
	catch (const char* s) {
		cout << "���� �߻� !! " << s << endl;
	}
	return 0;
}