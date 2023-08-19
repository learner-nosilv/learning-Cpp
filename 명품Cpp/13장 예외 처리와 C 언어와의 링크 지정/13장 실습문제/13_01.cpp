/* �������� 1. sum(int a, int b): a�ּ� b������ ������ ����
	����1: a>b
	����2: �� �� �ϳ��� ������ ���
	���� ���ܸ� ó���� �� �ִ� sum()�Լ� �����*/
#include <iostream>
using namespace std;

int sum(int a, int b) throw(const char*) {
	if (a < 0 || b < 0) throw "���� ó�� �� ��";
	if (a > b) throw "�߸��� �Է�";
	int result = a;
	while (a < b) {
		a++;
		result += a;
	}
	return result;
}

int main() {
	try {
		cout << sum(2, 5) << endl;	// ����
		cout << sum(-1, 5) << endl;	// ����
	}
	catch (const char* s) {
		cout << s << endl;
	}
	return 0;
}
// const�� �ƴ� char* �� �ϸ� ����� ������