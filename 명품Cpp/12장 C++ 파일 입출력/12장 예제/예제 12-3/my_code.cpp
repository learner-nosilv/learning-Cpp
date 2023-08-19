/* P.605	����12-03	get()�� �̿��� �ؽ�Ʈ ���� �б� */
#include <iostream>		// ǥ�� ����� ���̺귯��
#include <fstream>		// ǥ�� ���� ����� ���̺귯��
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";	// ���� ���ϸ�
	ifstream fin(file, ios::in);					// ���� �б� ��Ʈ�� ��ü ���� & �б� �������� ���� ����

	if (!fin) {										// ���� �б� ���� ��,
		cout << file << " ���� ����" << endl;
		return 0;
	}

	int count = 0;		// ����: ���� ���� ����
	int c;				// ����: ���� ���� ����

	while ((c = fin.get()) != EOF) {	// ���� ���� ���ڰ� ������(=������ ���� �ƴϸ�) �ݺ� (������ ���̸� Ż��)
		cout << (char)c;				// ���� ���� ���� �ܼ����
		count++;						// ���� ���� ���� ī��Ʈ
	}

	cout << "���� ����Ʈ ���� " << count << endl;
	fin.close();		// ���� �ݱ�

	return 0;
}