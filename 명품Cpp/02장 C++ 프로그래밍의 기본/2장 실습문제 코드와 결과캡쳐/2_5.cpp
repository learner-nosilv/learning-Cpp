#include <iostream>
using namespace std;

// main: 100�� �̸��� ���ڿ��� �Է¹��� �� x�� ������ ���� ����ϴ� �Լ�
int main() {
	// 1. �ִ� 99���� ���� �Է¹ޱ�
	char str[100];
	cout << "���ڵ��� �Է��϶�(100�� �̸�).\n";
	cin.getline(str, 100, '\n');	// �Է½�Ʈ����ü�� �޼ҵ�getline�� ���

	// 2. ���������� �˻��ϸ� x ���� ī��Ʈ
	int count = 0;
	for (int i = 0; i < 99; i++) {	// �˻������� str[0]~str[98]�̴�. str[99]�� �ݵ�� '\0' �̹Ƿ�
		if (str[i] == 'x') count++;	// str[0~98]�� ����x�� ������, count�� 1�� ����
	}

	// 3. x ���� ���
	cout << "x�� ������ " << count << endl;

	return 0;
}