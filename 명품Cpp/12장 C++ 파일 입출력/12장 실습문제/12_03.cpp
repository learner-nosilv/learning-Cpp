/* ������ �а� ���� ���ڸ� ��� �빮�ڷ� ����϶�. */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";	// ����� ������ ��ġ
	ifstream fin(file);								// �б�������� ���Ͽ���(����)
	if (!fin) {
		cout << "IN: ���� ���� ����" << endl;
		return 0;
	}

	char n;
	while ((n = fin.get()) != EOF) {	// �� ���� �б�
		if (n >= 'a' && n <= 'z')		// �ҹ��� -> �빮��
			cout << (char)(n - 'a' + 'A');
		else
			cout << n;
	}

	return 0;
}