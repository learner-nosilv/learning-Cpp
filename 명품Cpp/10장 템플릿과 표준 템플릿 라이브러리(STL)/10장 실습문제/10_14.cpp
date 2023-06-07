/* 14. ��ȣ ���� �������α׷��� map�� �̿��Ͽ� �ۼ��϶�. */
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
	cout << "�̸� ��ȣ>> ";
	cin >> name >> pwd;
	if (password.find(name) != password.end()) {
		char answer;
		cout << "�̹� ��ȣ�� ��ϵǾ��ִ� ������Դϴ�. �����Ͻðڽ��ϱ�?\n'y'�� ������ ����˴ϴ�. >> ";
		cin >> answer;
		if (answer != 'y') return;
	}
	password.insert(make_pair(name, pwd));
}

void WHO::checkData() {
	string name, pwd;
	cout << "�̸�? ";
	cin >> name;
	if (password.find(name) == password.end()) {
		cout << "�ش� ������� ��ȣ�� ��ϵǾ� ���� �ʽ��ϴ�.\n";
		return;
	}
	while (true) {
		cout << "��ȣ? ";
		cin >> pwd;
		if (password[name] == pwd) {
			cout << "���!!\n";
			return;
		}
		cout << "����~~\n";
	}
}

void WHO::run() {
	cout << "***** ��ȣ ���� ���α׷� WHO�� �����մϴ� *****\n";
	while (true) {
		int menu;
		cout << "����:1, �˻�:2, ����:3>> ";
		cin >> menu;
		if (isError()) {
			cout << "[�Է¿���] 1, 2, 3 �߿� �Է��ϼ���.\n";
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
				cout << "���α׷��� �����մϴ�...\n";
				return;
		}
	}
}

int main() {
	WHO mark1;
	mark1.run();
	return 0;
}