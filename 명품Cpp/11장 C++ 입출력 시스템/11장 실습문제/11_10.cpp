/* 10. prompt 조작자를 작성하여 프로그램을 완성하라 */
#include <iostream>
using namespace std;

istream& prompt(istream& ins) {
	cout << "암호?";
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