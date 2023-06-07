/* 14. 암호 관리 응용프로그램을 map을 이용하여 작성하라. */
#include <iostream>
#include <map>
#include <string>
using namespace std;

class WHO {
	map<string, string> password;
public:
	bool isError() {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(99, '\n');
			return true;
		}
		else return false;
	}
	void insertData();
	void checkData();
	void run();
};

void WHO::insertData() {
	string name, pwd;
	cout << "이름 암호>> ";
	cin >> name >> pwd;
	if (password.find(name) != password.end()) {
		char answer;
		cout << "이미 암호가 등록되어있는 사용자입니다. 변경하시겠습니까?\n'y'를 누르면 변경됩니다. >> ";
		cin >> answer;
		if (answer != 'y') return;
	}
	password.insert(make_pair(name, pwd));
}

void WHO::checkData() {
	string name, pwd;
	cout << "이름? ";
	cin >> name;
	if (password.find(name) == password.end()) {
		cout << "해당 사용자의 암호는 등록되어 있지 않습니다.\n";
		return;
	}
	while (true) {
		cout << "암호? ";
		cin >> pwd;
		if (password[name] == pwd) {
			cout << "통과!!\n";
			return;
		}
		cout << "실패~~\n";
	}
}

void WHO::run() {
	cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****\n";
	while (true) {
		int menu;
		cout << "삽입:1, 검사:2, 종료:3>> ";
		cin >> menu;
		if (isError()) {
			cout << "[입력오류] 1, 2, 3 중에 입력하세요.\n";
			continue;
		}
		switch (menu) {
			case 1:
				insertData();
				break;
			case 2:
				checkData();
				break;
			case 3:
				cout << "프로그램을 종료합니다...\n";
				return;
		}
	}
}

int main() {
	WHO mark1;
	mark1.run();
	return 0;
}