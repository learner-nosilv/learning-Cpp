/* P.598	Ű����κ��� �Է� �޾� �ؽ�Ʈ ���� �����ϱ� */
#include <iostream>		// ǥ�� ����� ���̺귯��
#include <fstream>		// ǥ�� ���� ����� ���̺귯��
using namespace std;

int main() {
	char name[10], dept[20];	// C-string��: �̸�(9��+\0), �а�(19��+\0)
	int sid;					// �й�: Student ID

	// Ű����κ��� �Է¹ޱ� : iostream
	cout << "�̸�>>";
	cin >> name;				// �̸�: Ű����->�Է½�Ʈ��->���α׷��� name����
	cout << "�й�(���ڷ�)>>";
	cin >> sid;					// �й�: Ű����->�Է½�Ʈ��->���α׷��� sid����
	cout << "�а�>>";
	cin >> dept;				// �а�: Ű����->�Է½�Ʈ��->���α׷��� dept����

	// ���Ͽ��� : ����->������½�Ʈ��->���α׷�����
	ofstream fout("C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-1\\student.txt");	// \�� ������ \\�� �����
	if (!fout) {
		cout << "������ �� �� ����";
		return 0;
	}

	// ���Ͼ���
	fout << name << endl;	// �̸��� ����
	fout << sid << endl;	// �й��� ���� (���� -> ���ڷ� ��ȯ)
	fout << dept << endl;	// �а��� ����

	fout.close();			// ���ϴݱ�, ��������
	
	return 0;
}