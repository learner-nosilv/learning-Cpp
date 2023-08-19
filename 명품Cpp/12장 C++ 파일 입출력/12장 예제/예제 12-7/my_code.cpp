/* p.614	����12-07	get()�� put()�� �̿��� �̹��� ���� ���� */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// �ҽ� ���ϰ� ���� ������ �̸�
	const char* srcFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\��ǰCPP��ǥ��-1-scaled.jpg";
	const char* destFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-7\\copy.jpg";

	// �ҽ� ���� ����
	ifstream sourceFile(srcFile, ios::in | ios::binary);		// binary �������� ������ ���� �б�
	if (!sourceFile) {											// ���� ���� �˻�
		cout << srcFile << "���� ����" << endl;
		return 0;
	}

	// ���� ���� ����
	ofstream destinationFile(destFile, ios::out | ios::app | ios::binary);	// binary �������� ������ ���� ����
	if (!destinationFile) {
		cout << destFile << "���� ����" << endl;
		return 0;
	}

	// �ҽ� ���� �а� -> �������� ����� ���� ����
	int c;	// int�� 4byte����, ���� �ϳ�(1byte)�� �б�
	while ((c = sourceFile.get()) != EOF) {	// ����: ���� ���� ���� ���� �ƴ� ���� (���� ���̸� ����Ż��)
		destinationFile.put(c);				// ���Ͽ� ����
	}
	
	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	sourceFile.close();						// ���� ���� �ݱ�
	destinationFile.close();				// �� ���� �ݱ�

	return 0;
}