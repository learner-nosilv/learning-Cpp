/*1. int cin.get() �Լ��� �̿��Ͽ� �� ������ �а� a �� �� ������ ����ϴ� ���α׷�*/
#include <iostream>
using namespace std;

int main() {
	int ch;
	int count = 0;
	cout << "�Է�>> ";
	while ((ch = cin.get()) != '\n') {
		if (ch == 'a') count++;
	}
	cout << "a�� ����>> " << count;

	return 0;
}

// �ַ���̶� ���� : EOFó�� ���� ���ؼ�... 