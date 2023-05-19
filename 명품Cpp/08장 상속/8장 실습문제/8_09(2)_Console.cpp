#include"Console.h"

int Console::chooseMenu() {
	int menu;
	while (true) {
		cout << "����:1, ���:2, ����:3, ������:4>> ";
		cin >> menu;
		if (menu == 1 || menu == 2 || menu == 3 || menu == 4) return menu;
		else if (cin.fail()) {
			cout << "[�ٸ��� ���� �Է�]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else cout << "[�ٸ��� ���� �Է�]" << endl;
	}
}
int Console::chooseTime() {
	int time;
	while (true) {
		cout << "07��:1, 12��:2, 17��:3>> ";
		cin >> time;

		if (time == 1 || time == 2 || time == 3) return time;
		else if (cin.fail()) {
			cout << "[�ٸ��� ���� �Է�]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else cout << "[�ٸ��� ���� �Է�]" << endl;
	}
}
int Console::chooseSeat() {
	int seat;
	while (true) {
		cout << "�¼� ��ȣ>> ";
		cin >> seat;

		if (seat == 1 || seat == 2 || seat == 3 || seat == 4
			|| seat == 5 || seat == 6 || seat == 7 || seat == 8) return seat;
		else if (cin.fail()) {
			cout << "[�ٸ��� ���� �Է�]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else cout << "[�ٸ��� ���� �Է�]" << endl;
	}
}
string Console::chooseName() {
	string name;
	while (true) {
		cout << "�̸� �Է�>> ";
		cin >> name;

		if (cin.fail()) {
			cout << "[�ٸ��� ���� �Է�]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else return name;
	}
}
