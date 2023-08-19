/* 4. �ǽ�����3������ �빮�ڷ� ��ȯ�Ͽ� ����Ͽ���. �ǽ�����4������ ��ȯ�Ͽ� �� ���Ͽ� ������ ��, ����Ͽ� �׽�Ʈ�ϱ� */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// 1. ���Ͽ���: ��/�� �����Ͱ� ���� �����̰� �ִٴ� ���� �����ϱ�
	const char* file = "c:\\windows\\system.ini";	// ����� ������ ��ġ
	ifstream fin(file);								// �б�������� ���Ͽ���(����)
	if (!fin) {
		cout << "IN: ���� ���� ����" << endl;
		return 0;
	}
	ofstream fout("text.txt");						// ����������� ���Ͽ���(����)
	if (!fout) {
		cout << "OUT: ���� ���� ����" << endl;
		return 0;
	}

	// 2. ���Ϻ�ȯ
	int n;
	while ((n = fin.get()) != EOF) {				// �� ���� �б�
		if (n >= 'a' && n <= 'z')					// �ҹ����� ��� -> �빮��
			n = n - 'a' + 'A';						// n = toupper(n);
		fout.put((char)n);							// ����
	}
	fin.close();
	fout.close();

	// 3. �����ܼ����
	fin.open("text.txt", ios::in);					// �б�������� ���Ͽ���(����)
	string line;
	while (getline(fin,line)) {
		cout << line << endl;
	}
	return 0;
}