/* �������� 4. getFileSize() �Լ��� �Ű������� NULL�� �Ѿ���� -1��, ������ �� �� ������ -2�� �����ϰ�, �������� ��� ����ũ�� ����
	�� ���α׷��� �����Ͽ� try-throw-catch ������� ���� ó���ϰ� ���α׷� �ϼ��ϱ�*/
#include <iostream>
#include <fstream>
using namespace std;

int getFileSize(const char* name) throw (const char*) {
	if (name == NULL) throw "���ϸ��� NULL �Դϴ�.";
	ifstream fin(name, ios::in | ios::binary);
	if (!fin) throw "���Ͽ��⸦ �����Ͽ����ϴ�.";
	fin.seekg(0, ios::end);			// ���� ������ ������ �̵�
	int size = (int)fin.tellg();	// ���� ���� index = ����ũ�� (byte)
	return size;
}

int main() {
	try {
		int n = getFileSize("C:\\windows\\system.ini");
		cout << "����ũ�� = " << n << endl;
		n = getFileSize(NULL);
		cout << "����ũ�� = " << n << endl;
	}
	catch (const char* msg) {
		cout << "���� �߻� : " << msg << endl;
	}
	return 0;
}