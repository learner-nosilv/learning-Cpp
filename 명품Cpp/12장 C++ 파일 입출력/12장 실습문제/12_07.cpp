/* ������ ����Ʈ������ �Ųٷ� �纻�� �����ϴ� ���α׷�
	* �� �� ����Ͽ� ���α׷��� ������ ������ Ȯ���� �� */

#include <iostream>
#include <fstream>
using namespace std;

// ������ �Ųٷ� �������ִ� �Լ�
void reverseCopy(const char* srcFile, const char* destFile) {
	// 1. ���Ͽ���
	ifstream fin(srcFile, ios::binary);
	ofstream fout(destFile, ios::binary);
	if (!fin || !fout) {
		cout << "�������: ���� ���� ����\n";
		return;
	}

	// 2. ��->������ ����; �б� ������(get pointer) �ڿ������� ������ �Űܰ���
	fin.seekg(-1, ios::end);			// ������ �� ���� ����: EOF ����
	int size = (int)fin.tellg() + 1;	// ���� ũ�� �ľ� = EOF

	for (int i = 0; i < size; i++) {
		int c = fin.get();			// �б� ( ������ �� ĭ ���� )
		fout.put(c);				// ����
		fin.seekg(-2, ios::cur);	// �б� �����͸� �б� ������ ������ġ�� �̵�
	}
	fin.close();
	fout.close();
	cout << "����Ϸ�\n";
	return;
}

// ���ϳ����� textI/O�� �̿��Ͽ� �ֿܼ� ����ϴ� �Լ�
void show(const char* srcFile) {
	// 1. ���Ͽ���
	ifstream fin(srcFile, ios::binary);
	if (!fin) {
		cout << "��½���: ���� ���� ����\n";
		return;
	}

	// 2. ȭ�����
	char buf[32];
	while (!fin.eof()) {
		fin.read(buf, 32);
		cout.write(buf, fin.gcount());
	}
	fin.close();
	return;
}

int main() {
	// 1. ���� ����
	const char* file[3] = { "c:\\windows\\system.ini",																					// ���� ������ ��ġ		[��]
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\12_07_system.txt",					// �� ������ ��ġ			[��]
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\12_07_systemRE.txt" };				// �ٽ� �� ������ ��ġ		[��]

	// 2. ���� ������
	for (int i = 0; i < 2; i++)
		reverseCopy(file[i], file[(i + 1)]);

	// 3. ���� ���� �ܼ����
	for (int i = 0; i < 3; i++) {
		cout << "\n[ ����" << (i + 1) << " ]\n";
		show(file[i]);
		cout << endl;
	}

	return 0;
}