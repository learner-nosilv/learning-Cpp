#include <iostream>
#include <string>
using namespace std;

int main() {
	string names[5];

	for (int i = 0; i < 5; i++) {
		cout << "�̸� >> ";
		getline(cin, names[i], '\n');
	}

	string letter = names[0];
	for (int i = 0; i < 5; i++) {
		if (letter < names[i]) {
			letter = names[i];
		}
	}
	cout << "�������� ���� �ڿ� ������ ���ڿ��� " << letter << endl;
	return 0;
}