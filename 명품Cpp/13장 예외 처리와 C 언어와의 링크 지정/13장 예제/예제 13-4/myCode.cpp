/* ���� 13-4. �հ� �ο����� �Է¹޾� ����� ���� ���ѷ��� ���α׷� �ۼ��ϱ� */
#include <iostream>
using namespace std;

int main() {
	int n, sum, average;
	while (true) {
		cout << "���� �Է��ϼ���>>";
		cin >> sum;					// �� �Է¹ޱ�
		if (cin.fail()) {			// ���ڸ� �Է��� ���
			cin.clear();
			cin.ignore(99, '\n');
			cout << "[ERROR] '����'�� �Է��ϼ���.\n";
			continue;
		}
		cout << "�ο����� �Է��ϼ���>>";
		cin >> n;					// �ο��� �Է¹ޱ�
		try {
			if (n <= 0)				// ���ܹ߻� �� �Է�: 0���ϸ� �Է��� ���
				throw n;			// ����ó��
			else					// ������ �Է�
				average = sum / n;	// ����ó��: ��/�ο���
		}
		catch (int x) {
			cout << "���� �߻�!! " << x << "(��)�� ���� �� ����\n" << endl;
			continue;
		}
		cout << "��� = " << average << '\n' << endl;
	}
	return 0;
}