/* P.600	ifstream�� >> �����ڸ� �̿��� �ؽ�Ʈ ���� �б� */
#include <iostream>		// ǥ�� ����� ���̺귯��
#include <fstream>		// ǥ�� ���� ����� ���̺귯��
using namespace std;

int main() {
	ifstream fin;
	fin.open("C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-1\\student.txt");
	if (!fin) {
		cout << "������ �� �� ����";
		return 0;
	}

	char name[10], dept[20];	// C-string��: �̸�(9��+\0), �а�(19��+\0)
	int sid;					// �й�: Student ID

	// ���� �б� -> ��Ʈ������-> ���� �Ҵ�
	fin >> name;				// �̸�: ���ϳ��� �� ������(���⳪ ����)�������� ���� -> ���α׷��� name����
	fin >> sid;					// �й�: ���ϳ��� �� ������(���⳪ ����)�������� ���� -> ���ڷ� ��ȯ�Ͽ� -> ���α׷��� sid����
	fin >> dept;				// �а�: ���ϳ��� �� ������(���⳪ ����)�������� ���� -> ���α׷��� dept����


	// ���� �ؽ�Ʈ ������ ������ ȭ�鿡 ���
	cout << name << endl;	// �̸��� ����
	cout << sid << endl;	// �й��� ���� (���� -> ���ڷ� ��ȯ)
	cout << dept << endl;	// �а��� ����

	fin.close();			// ���ϴݱ�, ��������
	
	return 0;
}