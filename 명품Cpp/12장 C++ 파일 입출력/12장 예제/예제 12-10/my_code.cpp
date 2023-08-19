/* p.619	����12-10	int �迭�� double ������ ���̳ʸ� ���Ͽ� �����ϰ� �ٽ� �б�
	������ �迭, Ȥ�� ������ ������ �״�� �����ϱ� ���ؼ��� ���̳ʸ� I/O�� �ݵ�� ����ؾ� �Ѵ�.
		���̳ʸ� I/O�� �̿��ϹǷ� ����� ������ ���̳ʸ� ������ �ȴ�. */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// ���� ������ �̸�
	const char* destFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-10\\data.dat";

	// ���Ͼ��⽺Ʈ����ü ���� & ���� ���� ����
	ofstream fout(destFile, ios::out | ios::binary);
	if (!fout) {
		cout << "���� ���� ����";
		return 0;
	}

	// ���Ͽ� �� �迭�� ���� ����
	cout << "1. ���Ͽ� �� �迭�� ���� ����\n";
	int n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };	// 0~9�� ����� ������ �迭
	double d = 3.15;							// ũ�Ⱑ 8byte�� �Ǽ��� ����
	cout << "n[]\t: ";
	for (int i = 0; i < (sizeof(n)/sizeof(int)); i++) cout << *(n + i) << ' ';
	cout << endl << "d\t: " << d << endl;

	// �������Ͽ� int �迭�� double ������ ���̳ʸ� ���Ͽ� ����
	fout.write((char*)n, sizeof(n));			// char* ������ ��ȯ�� int�� �迭 n�� �����ּҿ� ����, �迭ũ���� byte��ŭ�� �а� fout�� ����� ���Ͽ� ����
	fout.write((char*)&d, sizeof(d));			// char* ������ ��ȯ�� double�� ����d�� �ּҿ� ����, ����dũ�⸸ŭ�� byte��ŭ�� �а� fout�� ����� ���Ͽ� ����
	fout.close();								// ���� ���� ����

	// ���Ͼ��⿡ ���� �迭�� ������ �� ����
	cout << "\n2. ���Ͽ� �� �迭�� ���� ����\n";
	for (int i = 0; i < 10; i++)	n[i] = 99;	// �迭 n�� ��� ���Ұ��� 99�� ����
	d += 5;										// �Ǽ� d�� �� 8.15�� ����
	cout << "n[]\t: ";
	for (int i = 0; i < (sizeof(n) / sizeof(int)); i++) cout << *(n + i) << ' ';
	cout << endl << "d\t: " << d << endl;

	// ���� ���⿡ ���� ������ �о �迭�� ������ ���Ҵ�
	cout << "\n3. ���Ͼ��⿡ ���� ������ �о �迭�� ������ ���Ҵ�\n";
	ifstream fin(destFile, ios::in | ios::binary);	// ���� �б� ��Ʈ����ü ���� �� ���⿡ ���Ǿ��� ������ �б� �������� �翬��
	if (!fin) {
		cout << "���� ���� ����";
		return 0;
	}
	fin.read((char*)n, sizeof(n));				// �迭ũ���� byte��ŭ�� ���ۿ��� �о� n�� �Ҵ�
	fin.read((char*)&d, sizeof(d));				// doubleũ���� byte��ŭ�� ���ۿ��� �о� d�� �Ҵ�
	cout << "n[]\t: ";
	for (int i = 0; i < (sizeof(n) / sizeof(int)); i++) cout << *(n + i) << ' ';
	cout << endl << "d\t: " << d << endl;
	fin.close();

	cout << "\n4. ���ϳ��� binary�������� �б�" << endl;
	fin.open(destFile, ios::in | ios::binary);
	if (!fin) {
		cout << "���� ���� ����";
		return 0;
	}
	
	char buf;				// ����: 1byte ����
	int j = 0;				// ī��Ʈ�ϴ� ����: 4byte ���� ������ ����
	int k = 0;				// ī��Ʈ�ϴ� ����: �迭index
	while (!fin.eof()) {	// ������ ������ ������ �б�
		fin.read(&buf, 1);	// 1byte��ŭ�� �����б�
		for (int i = 7; i >= 0; i--) {			// 1byte�� 1��Ʈ�� ���
			int result = (buf >> i) & 1;		// 00000001 ���� and �������� �� �պ�Ʈ�� ���
			cout << result;
			cout << ' ';
		}
		j++;									// 1byte����� ������ +1
		cout << ' ';							// 1byte����� ������ ����
		if (j % 4 == 0) {						// 4byte����� ������
			if (k < 10) {						// �迭: 10�������� ���� �� ��� �� ����
				cout << '\t' << n[k] << endl;
				k++;
			}
			else cout << '\t' << d << endl;		// ����: 10�������� ���� �� ��� �� ����
		}
	}
}