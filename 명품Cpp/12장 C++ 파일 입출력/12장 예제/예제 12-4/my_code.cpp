/* P.609	���� 12-4	�ؽ�Ʈ ���� ���� */
#include <iostream>		// ǥ�� ����� ���̺귯��
#include <fstream>		// ǥ�� ���� ����� ���̺귯��
using namespace std;

int main() {
	const char* firstFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-1\\student.txt";
	const char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);	// ��ü����: ���Ͽ���, ���Ͼ�����, �׻� �ڿ� �����Ӹ��
	if (!fout) {									// ���Ͽ��� �������� �˻�
		cout << firstFile << " ���� ����";
		return 0;
	}

	fstream fin(secondFile, ios::in);				// ��ü����: ���Ͽ���, �����б���
	if (!fin) {										// ���Ͽ��� �������� �˻�
		cout << secondFile << " �������";
		return 0;
	}
	fout.put('\n');		// Line Feed
	fout.put('\r');		// Carrage Return

	int c;											// ����: ���� ���� ���� �Ҵ�
	while ((c = fin.get()) != EOF) {				// ���� ���ڰ� �ִ� ��� �ݺ� (������ ���̶� ���� ���ڰ� ���� ��� ����Ż��)
		fout.put(c);								// ���Ͼ��⽺Ʈ����ü�� ���� ���Ͽ� ���ھ��� 
	}

	fout.close();									// �� ����(firstFile) �ݱ�
	fin.close();									// ���� ����(secondFile) �ݱ�

	fin.open(firstFile, ios::in);
	if (!fin) {										// ���Ͽ��� �������� �˻�
		cout << secondFile << " �������";
		return 0;
	}

	while((c = fin.get()) != EOF) {				// ���� ���ڰ� �ִ� ��� �ݺ� (������ ���̶� ���� ���ڰ� ���� ��� ����Ż��)
		cout << (char)c;						// ���� ���� ��� 
	}

	fin.close();								// ���� ����(firstFile) �ݱ�

	return 0;
}