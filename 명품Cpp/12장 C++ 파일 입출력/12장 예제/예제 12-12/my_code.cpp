/* p.629	����12-12	���� ũ�� �˾Ƴ��� */
#include <iostream>
#include <fstream>
using namespace std;

// ����ũ�⸦ byte���� ���� (long���� ũ��� 16byte�̹Ƿ�, 2�� 15��-1 ������ ǥ������)
long getFileSize(ifstream& fin) {
	fin.seekg(0, ios::end);		// get pointer�� EOF���� 0��ŭ ���� = EOF
	return (fin.tellg());		// �Է� ��Ʈ���� ���� get pointer�� ������ġ ��ȯ
}

int main() {
	const char* file = "c:\\windows\\system.ini";	// ũ�⸦ �˰���� ������ ��ġ

	ifstream fin(file);		// �����Է� ��Ʈ����ü�� ����
	if (!fin) {
		cout << file << " ���� ����" << endl;
		return 0;
	}

	cout << file << "�� ũ��� " << getFileSize(fin) << "byte �Դϴ�." << endl;
	fin.close();

	return 0;
}