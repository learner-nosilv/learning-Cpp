#include"Console.h"

int Console::chooseMenu() {
	int menu;
	while (true) {
		cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
		cin >> menu;
		if (menu == 1 || menu == 2 || menu == 3 || menu == 4) return menu;
		else if (cin.fail()) {
			cout << "[바르지 않은 입력]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else cout << "[바르지 않은 입력]" << endl;
	}
}
int Console::chooseTime() {
	int time;
	while (true) {
		cout << "07시:1, 12시:2, 17시:3>> ";
		cin >> time;

		if (time == 1 || time == 2 || time == 3) return time;
		else if (cin.fail()) {
			cout << "[바르지 않은 입력]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else cout << "[바르지 않은 입력]" << endl;
	}
}
int Console::chooseSeat() {
	int seat;
	while (true) {
		cout << "좌석 번호>> ";
		cin >> seat;

		if (seat == 1 || seat == 2 || seat == 3 || seat == 4
			|| seat == 5 || seat == 6 || seat == 7 || seat == 8) return seat;
		else if (cin.fail()) {
			cout << "[바르지 않은 입력]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else cout << "[바르지 않은 입력]" << endl;
	}
}
string Console::chooseName() {
	string name;
	while (true) {
		cout << "이름 입력>> ";
		cin >> name;

		if (cin.fail()) {
			cout << "[바르지 않은 입력]" << endl;
			cin.clear();
			cin.ignore(99, '\n');
		}
		else return name;
	}
}
