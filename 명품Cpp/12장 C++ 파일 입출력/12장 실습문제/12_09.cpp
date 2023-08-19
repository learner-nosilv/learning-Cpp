/* 9. vector�� �����Ͽ�, ���ϳ��� �� �Է¹��� ������ ������ ����ϴ� ���α׷� */
#include <iostream>	// ǥ�� ����� ���̺귯��
#include <fstream>	// ǥ�� ��������� ���̺귯��
#include <string>
#include <vector>	// �����迭
using namespace std;

// �Է¿����� �ִ��� �˻��ϴ� �Լ�
bool isError() {
	if (cin.fail()) {	// ���ڸ� �Է��Ͽ� ���۰� ���������� ���
		cin.ignore(99, '\n');
		cin.clear();
		return true;
	}
	return false;
}

int main() {
	// 1. ���� ����
	const char* srcFile = "c:\\windows\\system.ini";
	ifstream fin(srcFile, ios::in | ios::binary);
	if (!fin) {
		cout << "���Ͽ������\n";
		return 0;
	}

	// 2. ������ ���ٴ����� �����迭�� ����
	vector<string> content;
	string buf;
	while (getline(fin,buf,'\n'))			// �� �پ� �б�(�����ڴ� ����X ���ۿ��� ������)
		content.push_back(buf);
	cout << srcFile << " ���� �б� �Ϸ�\n";

	cout << "���� ��ȣ�� �Է��ϼ���. 1���� ���� ���� �Է��ϸ� ����\n";
	// 3. ������ �Է¹ް�, ����ϱ�
	while (true) {
		int answer;
		cout << ": ";
		cin >> answer;
		if (isError()) {					// ���1. �Է¿� ������ �ִ� ���
			cout << "[ERROR] ���� �ϳ��� �Է��ϼ���\n";
			continue;						// ���Է�
		}
		else if (answer < 1)				// ���2. 1���� ���� ���� �Է��� ���
			break;
		else if (answer > content.size()) {	// ���3. �䱸�ϴ� ������ ����ũ�⸦ �Ѿ ���
			continue;
		}
		else								// ���4. ����� �Է��� ���
			cout << content[(answer - 1)] << endl;
	}
	cout << "���� �մϴ�." << endl;
	return 0;
}