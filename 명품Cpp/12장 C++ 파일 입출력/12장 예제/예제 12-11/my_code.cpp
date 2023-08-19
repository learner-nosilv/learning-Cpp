/* p.623	����12-11	��Ʈ�� ���� �˻� */
#include <iostream>
#include <fstream>
using namespace std;

// State bit�� ���� ���
void showStreamState(ios& stream) {					// ios���� �����Ű�����
	cout.setf(ios::boolalpha);						// bool�� ���� true/false �������� ���
	cout << "eof()\t" << stream.eof() << endl;		// end of file bit = 1 : ������ �� 
	cout << "fail()\t" << stream.fail() << endl;	// failbit �� bad bit = 1 : ������ ����or������ �ջ���ؿ����� ��ȿ�������� ��� 
	cout << "bad()\t" << stream.bad() << endl;		// bad bit = 1 : �����ͼջ����, ��ȿ���� ���� ��ɿ���
	cout << "good()\t" << stream.good() << endl;
}

int main() {
	// ���� ������ �̸�
	const char* noExistFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-10\\datad.dat";
	const char* existFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-10\\data.dat";

	ifstream fin(noExistFile);	// �������� ���� ���ϰ� ����
	if (!fin) {
		cout << noExistFile << " ���� ����" << endl;		// ���� ���
		showStreamState(fin);							// ��Ʈ�� ���� ���
	}

	cout << existFile << " ���� ����" << endl;			// �����ϴ� ���� ����
	fin.open(existFile);
	showStreamState(fin);								// ��Ʈ�� ���� ���

	// ��Ʈ���� ������ �а� ���� ���
	int c;
	while ((c = fin.get()) != EOF)						// ����: ���� 1byte �б� (������ ���̸� ����Ż��)
		cout.put(char(c));

	cout << endl << "- ���� ������ ���� ��: ��Ʈ�� ����\n";
	showStreamState(fin);

	fin.close();
	return 0;
}