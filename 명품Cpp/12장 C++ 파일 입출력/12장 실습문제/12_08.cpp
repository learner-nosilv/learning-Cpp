/* 8. ������ ������ 16���� �������� ���ڷ� 8�ھ� ������ ������ ����ϴ� ���α׷� �ۼ��ϱ�
 16���� ����� ������: hex �̿� 
 8���ڴ� ����� ����
 8���� �� �������� ����4ĭ ���� ����
 8���� �� �������� 16����/���ڷ� ����
 16���ڸ� �� ���ۿ� �־ �ѹ��� 16������ �ѹ��� ���ڷ� ����ϱ�

 ��Ʈ�� �� ���忡 �־�

*/
#include <iostream>
#include <fstream>
using namespace std;

void print16Byte(char* buf, int bufSize, int option) {	// option: 0�̸� hex, �� �ܸ� ����
	// ���ڷ� ���
	if (option) {
		for (int i = 0; i < 16; i++) {
			// �� ���� ���
			if (i < bufSize) {							// 1���� ��� : ��°��� �ִ� ���
				if (isprint(buf[i]))					//		��°����� ������ ��� ����� ���
					cout << buf[i];
				else									//		��ºҰ��� ������ ��� '.'���� ��ü ���				
					cout << '.';	
			}
			else										// 1���� ��� : ��°��� ���� ��� �������
				cout << ' ';
			// ������ ���
			if (i == 7 || i == 15)						// ������ ��� : 8, 16���ڴ����� �� ����
				cout << "    ";
			else										// ������ ��� : �⺻ ����
				cout << ' ';
		}
	}
	// 16������ ���
	else {
		for (int i = 0; i < 16; i++) {
			// �� ���� ���
			if (i < bufSize) {							// 1���� ��� : ��°��� �ִ� ��� ����� ���
				cout.width(2);
				cout.fill('0');
				cout << hex << (int)buf[i];
			}
			else										// 1���� ��� : ��°��� ���� ��� �������
				cout << "  ";
			// ������ ���
			if (i == 7 || i == 15)						// ������ ��� : 8, 16���ڴ����� �� ����
				cout << "    ";
			else										// ������ ��� : �⺻ ����
				cout << ' ';
		}
	}
}

int main() {
	// 1. ���� ����
	const char* srcFile = "c:\\windows\\system.ini";
	ifstream fin(srcFile, ios::in | ios::binary);
	if (!fin) {
		cout << "���Ͽ������\n";
		return 0;
	}
	// 2. ���� �а� ���
	char buf[16];						// ���ϳ����� ������ ����
	while (!fin.eof()) {
		fin.read(buf, 16);					// 16byte ������ �����б�
		int realCount = (int)fin.gcount();	// ���� ���� byte ��
		print16Byte(buf, realCount, 0);		// 16byte 16������ ���
		print16Byte(buf, realCount, 1);		// 16byte ���ڷ� ���
		cout << '\n';
	}
	return 0;
}