/* 7. 0-127���� ASCII �ڵ�� �ش� ���ڸ� ������ ���� ���, ��ºҰ��� ASCII�ڵ�� '.'���� ��� */
#include <iostream>
#include <iomanip>	// �Ű������� �ִ� ������
#include <cctype>	// ��°����� �������� �˷��ִ� �Լ� bool isprint()
using namespace std;

int main() {
	cout.setf(ios::left);
	for (int i = 0; i < 4; i++)
		cout << "dec    hexa    char    ";
	cout << '\n';
	for (int i = 0; i < 4; i++)
		cout << "---    ----    ----    ";
	cout << '\n';
	for (int i = 0; i < 128;) {
		for (int j = 0; j < 4; j++) {
			cout << setw(7) << dec << i;
			cout << setw(8) << hex << i;
			if (isprint(i))
				cout << setw(8) << (char)i;
			else
				cout << setw(8) << '.';
			i++;
		}
		cout << '\n';
	}
	return 0;
}