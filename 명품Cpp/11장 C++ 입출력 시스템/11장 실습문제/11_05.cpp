/* 5. ���� 11-3�� �ڵ带 string ���� ���ۼ��ϱ�*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string cmd;
	cout << "cin.get(char*, int)�� ���ڿ��� �н��ϴ�." << endl;
	while (true) {
		cout << "�����Ϸ��� exit�� �Է��ϼ��� >> ";
		getline(cin, cmd);
		if (cmd=="exit") {
			cout << "���α׷��� �����մϴ�....";
			return 0;
		}
		// else
		//	cin.ignore(1);	// getline�� delimiter������ �Ҵ��ϰ�, delimiter�� ����
	}
	return 0;
}