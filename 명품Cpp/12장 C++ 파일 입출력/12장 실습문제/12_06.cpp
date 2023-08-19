/* ������ �����ϴ� ���� 10%�� ������ ������ '.'�� ����Ʈ ũ�⸦ ������ ���� ����ϴ� ���α׷� */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// 1. ���Ͽ���: ��/�� �����Ͱ� ���� �����̰� �ִٴ� ���� �����ϱ�
	const char* read = "c:\\windows\\system.ini";																						// ���� ������ ��ġ
	const char* writeOn = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\12_06_system.txt";	// �� ������ ��ġ
	ifstream fin(read, ios::binary);			// ���� ����
	ofstream fout(writeOn, ios::binary);		// �� ����
	if (!fin || !fout) {
		cout << "���Ͽ������" << endl;
		return 0;
	}

	// 2. ���������͸� �̿��Ͽ� ����ũ�� �˾Ƴ���
	fin.seekg(0, ios::end);				// get(�б�)������ �̵�: EOF = ũ��(byte)
	int length = (int)fin.tellg();		// ũ�� ����
	cout << read << " ũ��: " << length << "Byte" << endl;
	int i = length / 10;				// 10%�� �ش��ϴ� ����Ʈ �� (�Ҽ��� ��������, ���� 10%����)
	cout << "�� 10%: " << i << "Byte\n" << endl;
	char* buf = new char[i];			// �ش� ����Ʈ��ŭ�� ���ڸ� ������ ���

	// 3. ���� ������ �� 10%���� ���� ���Ͽ� ���� * 10ȸ
	fin.seekg(0, ios::beg);
	cout << "���� ����...\n";
	for (int j = 0; j < 10; j++) {
		fin.read(buf, i);										// ���Ͽ��� 10%(����)�� �ش��ϴ� ������ �б�
		fout.write(buf, i);										// �ش� ���ڿ���ŭ ���
		cout << '.' << i << "B " << (j + 1) << "0%" << endl;	// ������Ȳ �ܼ����
	}

	// 4. ���� �� ���� �����Ͱ� �ִٸ�, ���������� ���� ���Ͽ� ����
	if (!fin.eof()) {											// ���� �� ���� �ʾҴٸ�,
		fin.read(buf, i);										// ���Ͽ��� 10%(����)�� �ش��ϴ� ������ �б�
		fout.write(buf, fin.gcount());										// �ش� ���ڿ���ŭ ���
	}

	// 5. ���� ���Ⱑ �Ϸ���� �˸���
	cout << "���� ũ��: " << length << "Byte / ���� " << ((i * 10) + fin.gcount()) << "Byte ���� �Ϸ�" << endl;

	delete[] buf;

	return 0;
}