/* �������� 5. ���ܸ� ����� ������ ������α׷� */
#include <iostream>
using namespace std;

int main() {
	int n;
	while (true) {
		try {
			cout << "��� �Է�>> ";
			cin >> n;
			if (cin.fail()) {			// �����Է� -> ����
				cin.clear();
				cin.ignore(99, '\n');
				throw 1;
			}
			if (n < 1 || n>9) throw 2;	// 0~9�� ����� �Է� -> ����
			for (int i = 1; i <= 9; i++)
				cout << n << 'x' << i << '=' << n * i << ' ';
			cout << endl;
		}
		catch (int n) {
			if (n == 1) {
				cout << "�Է� ������ �߻��Ͽ� �� �̻� �Էµ��� �ʽ��ϴ�. ���α׷��� �����մϴ�" << endl;
				return 0;
			}
			else if (n == 2)
				cout << "�߸��� �Է��Դϴ�. 1~9 ������ ������ �Է��ϼ���" << endl;
		}
	}
	return 0;
}