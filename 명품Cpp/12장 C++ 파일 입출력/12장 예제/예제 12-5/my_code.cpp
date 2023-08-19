/* p.610	����12-05	istream�� getline()�� �̿��Ͽ� �ؽ�Ʈ ������ �а� ȭ�� ��� */
#include <iostream>	// C++ ǥ�� ����� ���̺귯��
#include <fstream>	// C++ ǥ�� ���� ����� ���̺귯��
using namespace std;

int main() {
	const char* firstFile = "c:\\windows\\system.ini";
	ifstream fileIn(firstFile);		// �ش� ������ ��� �о���̴� ���� �б� ��Ʈ�� ��ü ����
	if (!fileIn) {					// ���� ���Ⱑ ������ ���
		cout << firstFile << " ���� ����" << endl;
		return 0;
	}

	char buf[81];						// 80�� + '/0'
	while (fileIn.getline(buf, 81)) {	// ����: �� �پ� �б� (���� ���, ����Ż��)
		cout << buf << endl;			// ���� �� �� ��� + ����(LF, CR)
	}

	fileIn.close();						// fileIn�� ����� ���� �ݱ�

	return 0;
}