/* �������� 2. ���� -> ���� ��� ���α׷�
	����: 0~100���� ����� ������ ����ó�� */
#include <iostream>
using namespace std;

int main() {
	int score;
	while (true) {
		cout << "0-100�� ������ ������ �Է��ϼ��� >> ";
		cin >> score;
		try {
			if (cin.fail()) throw "������ �ƴ� �����Է¿���";
			if (score < 0 || score>100) throw "0-100�� ���� �����Է¿���";
			cout << "���� >> ";
			if (score < 60) cout << 'F' << endl;
			else if (score < 70) cout << 'D' << endl;
			else if (score < 80) cout << 'C' << endl;
			else if (score < 90) cout << 'B' << endl;
			else cout << 'A' << endl;
		}
		catch (const char* msg) {
			if (msg == "������ �ƴ� �����Է¿���") {
				cin.clear();
				cin.ignore(99, '\n');
			}
			cout << msg << endl;
		}
	}
	

	return 0;
}