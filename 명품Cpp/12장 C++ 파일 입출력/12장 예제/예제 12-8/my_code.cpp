/* p.616	����12-08	read()�� �̿��Ͽ� ��� ������ �ؽ�Ʈ ���� �б� */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "c:\\windows\\system.ini";

	ifstream fin(firstFile, ios::in | ios::binary);
	if (!fin) {			// ���� ���� ���� ��
		cout << "���� ���� ����";
		return 0;
	}

	int count = 0;					// ���۷κ��� ���� ���� ����(=����Ʈ) ��
	char blockBuf[32];				// ��� ������ �о���� ����
	while (!fin.eof()) {			// ���� �� ���� ������ ���� ��� ����Ż��
		fin.read(blockBuf, 32);		// �ִ� 32byte�� �о ���ۿ� ����
		int n = fin.gcount();		// ��Ʈ�����ۿ��� ������ ó���� ����Ʈ �� �Ҵ�
		cout.write(blockBuf, n);	// ���� ��ŭ�� ���̳ʸ���(�ִ� 32byte)�� �ֿܼ� ��� (1byte=16���� 2�ڸ�, 32byte = 64�ڸ�)
		count += n;					// ���� ���̳ʸ����� ���� ����
	}

	cout << "���� ����Ʈ ���� " << count << endl;
	fin.close();					// ���� �ݱ�

	return 0;
}