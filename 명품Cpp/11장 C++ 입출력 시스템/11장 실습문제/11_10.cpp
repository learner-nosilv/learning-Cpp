/* 10. prompt �����ڸ� �ۼ��Ͽ� ���α׷��� �ϼ��϶� */
#include <iostream>
using namespace std;

istream& prompt(istream& ins) {
	cout << "��ȣ?";
	return ins;
}

int main() {
	string password;
	while (true) {
		cin >> prompt >> password;
		if (password == "C++") {
			cout << "login success!!" << endl;
			break;
		}
		else
			cout << "login fail. try again!!" << endl;
	}
	return 0;
}