/* 5. c++ �ҽ����Ͽ��� //�� �����ϴ� �ּ����� ��� ����ϴ� ���α׷� �ۼ��ϱ� */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// 1. ���Ͽ���: ��/�� �����Ͱ� ���� �����̰� �ִٴ� ���� �����ϱ�
	const char* file = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\12_05_solution_ShowNoComment.cpp";
	ifstream fin(file);					// ���� ����
	ofstream fout("12_05_test.cpp");	// �� ����
	if (!fin || !fout) {
		cout << "���Ͽ������" << endl;
		return 0;
	}
	
	// 2. //�� �� �ּ��� ���� (Ư¡: // ���ķ� �ش� ���� ��� ����)
	string line;
	while (getline(fin,line,'\n')) {	// ���� : ���δ��� �б� (������ ������ �б� ������)
		int pos = line.find("//");		// �ּ�������ġ
		if (pos != -1)					// �ּ��� �����Ѵٸ�
			line.resize(pos);			// �ּ� �տ��� �ڸ��� (�ּ��� index 3������, �ּ� �ձ����� size�� 3byte)
		fout << line << endl;			// ����->���Ͼ���
	}
	fin.close();
	fout.close();

	// 3. �ۼ��� ���� �б�
	fin.open("12_05_test.cpp", ios::in);	// �б� �������� ���Ͽ���
	if (!fin) {
		cout << "���Ͽ������" << endl;
		return 0;
	}
	while (getline(fin, line, '\n'))
		cout << line << endl;
	return 0;
}