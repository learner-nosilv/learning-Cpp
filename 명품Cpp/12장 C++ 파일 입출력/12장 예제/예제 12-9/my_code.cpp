/* p.618	����12-09	read()/write()�� �̹��� ���� ���� */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// �ҽ� ���ϰ� ���� ������ �̸�
	const char* srcFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\��ǰCPP��ǥ��-1-scaled.jpg";
	const char* destFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-9\\copy.jpg";

	// �ҽ� ���� ����
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {	// ���� ���� �˻�
		cout << srcFile << " ���� ����" << endl;
		return 0;
	}

	// ���� ���� ����
	ofstream fdest(destFile, ios::out | ios::app | ios::binary);
	if (!fdest) {	// ���� ���� �˻�
		cout << destFile << " ���� ����" << endl;
		return 0;
	}

	// �ҽ����Ͽ��� �������Ϸ� ���� �����ϱ�
	char buf[1024];					// ���ۺ��: 1024����Ʈ
	while (!fsrc.eof()) {			// ������ ���� �� ���, ����Ż��
		fsrc.read(buf, 1024);		// fsrc�� ���̳ʸ��ڵ带 ���� �б� ��Ʈ�����ۿ� �ְ�, �ִ� 1024����Ʈ��ŭ�� ���̳ʸ��ڵ常 buf�� �Ҵ�
		int n = fsrc.gcount();		// ���ۿ��� ���� ���� ����Ʈ �� �Ҵ�
		fdest.write(buf, n);		// buf�迭�� ����� ���̳ʸ� �� �� ���ۿ��� ���� ���� ����Ʈ��ŭ �������Ͽ� ����
	}
	cout << srcFile << "�� " << destFile << "�� ���� �Ϸ�" << endl;
	fsrc.close();
	fdest.close();

	return 0;
}