/* 14. ������������� �������ٹ���� �̿����� �ʰ� read �Լ��� �̿��Ͽ� ������ ũ�⸦ ȭ�鿡 ����ϴ� �Լ�
	get(), seekg(), tellg() ���X
	�� ������ ũ�⸦ ��Ȯ�ϰ� �����ؾ��ϹǷ� ios::binary�� �а�, read()�� .eof()�� gcount() ����ϱ� */
#include <iostream>
#include <fstream>
#include <Windows.h>	// �緮���� Sleep�Լ� ����غ�����
using namespace std;

int main() {
	// 1. ���Ͽ���
	const char* srcFile = "c:\\windows\\system.ini";		// ũ�⸦ ������ ����
	ifstream fin(srcFile, ios::in | ios::binary);			// �б� & ���̳ʸ�I/O ������� ���Ͽ���(����)
	if (!fin) {												// ������н�, �˸��� ���α׷� ����
		cout << "�����б����\n";
		return 0;
	}
	cout << "���� [" << srcFile << "] �� �о����ϴ�.\n";

	// 2. �����а� ũ������
	cout << "����ũ�� ���� ��";
	char buf[32];				// �迭: ���ϳ����� �д� ����(32byte��)
	int size = 0;				// ����: ����ũ��
	while (!fin.eof()) {		// ������ ���� ���� ������
		fin.read(buf, 32);		// 32����Ʈ�� �а�
		Sleep(300);				//	(����: 1ms �����̹Ƿ� 1�ʴ� 1000)
		size += fin.gcount();	// ���� ���� ����Ʈ ���� �����ջ�
		cout << '.';
	}

	// 3. ����ũ�� ���
	cout << "\n����ũ��: " << size << "Byte\n";
	fin.close();
	return 0;
}