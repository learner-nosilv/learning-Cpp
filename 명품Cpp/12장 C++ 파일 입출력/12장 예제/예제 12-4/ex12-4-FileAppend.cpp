#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "C:\Users\renee\source\repos\learning-Cpp\��ǰCpp\����\student.txt";
	const char* secondFile = "C:\Users\renee\source\repos\learning-Cpp\��ǰCpp\����\system.ini";

	fstream fout(firstFile, ios::out | ios::app); // ���� ���� ���� ����
	if(!fout) { // ���� ���� �˻�
		cout << firstFile << " ���� ����";
		return 0;
	}

	fstream fin(secondFile, ios::in); // �б� ���� ���� ����
	if(!fin) { // ���� ���� �˻�
		cout << secondFile << " ���� ����";
		return 0;
	}

	int c;
	while((c=fin.get()) != EOF) { // ���� ������ ���� �б�
		fout.put(c); // ���� ���� ���
	}

	fin.close(); // �Է� ���� �ݱ�
	fout.close(); // ��� ���� �ݱ�
}