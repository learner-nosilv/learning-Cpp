#include <iostream>
#include <string>
using namespace std;

int main(void) {
	cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�." << endl;

	char coffee[100];	// Ŀ���̸�
	int num;			// �� ��
	int order = 0;		// �ֹ��ݾ�
	int total = 0;		// �� ����

	while (total < 20000) {	// �� ������ 20000�� �̸��� ���� �ݺ�
		// 1. �ֹ� �ޱ�
		cout << "�ֹ�>>";
		cin >> coffee >> num;	// Ŀ���̸��� �ܼ��� �Է¹޴´�.

		// 2. �ֹ� �ݾ� ����ϰ� ����ϱ�
		if (strcmp(coffee, "����������") == 0)
			order = 2000 * num;
		else if (strcmp(coffee, "�Ƹ޸�ī��") == 0)
			order = 2300 * num;
		else if (strcmp(coffee, "īǪġ��") == 0)
			order = 2500 * num;
		cout << order << "���Դϴ�. ���ְ� �弼��." << endl;

		// 3. �� ���⿡ �ݿ��ϱ�
		total += order;
	}

	// 4. �� ������ 20000�� �̻��� �� ����
	cout << "���� " << total << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~~~" << endl;
	return 0;
}
