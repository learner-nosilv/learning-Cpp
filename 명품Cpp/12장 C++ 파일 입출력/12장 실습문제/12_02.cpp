/* 638p. system.ini ������ �а� ���� ��ȣ�� ������ ���� �ٿ� ȭ�鿡 ���
	�ָŸ�ȣ�ϰ� Ǯ���ٸ�, 610p. ���� */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";	// ����� ������ ��ġ
	ifstream fin(file);								// �б�������� ���Ͽ���(����)
	if (!fin) {
		cout << "IN: ���� ���� ����" << endl;
		return 0;
	}

	string line;
	int n = 0;
	while (getline(fin, line))	// �� ������ �а�, fin ��������: ()�����ڰ� fin�� ���� ����(fail, badbit) üũ�ϰ� �������
		cout << (++n) << " : " << line << endl;

	return 0;
}