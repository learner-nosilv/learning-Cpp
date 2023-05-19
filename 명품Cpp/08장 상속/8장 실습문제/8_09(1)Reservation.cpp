#include "8_09(1)Reservation.h"

int Reservation::chooseMenu() {
	int menu;
	while (true) {
		cout << "����:1, ���:2, ����:3, ������:4>> ";
		cin >> menu;
		if (menu == 1 || menu == 2 || menu == 3 || menu == 4)
			return menu;
		cout << "[�ٸ��� ���� �Է�]" << endl;
		cin.clear();
		cin.ignore(99, '\n');
	}
}
int Reservation::choosePlain() {
	int plainIdx;
	while (true) {
		for (int i = 0; i < plainNum; i++)				// ����� ������ ���
			cout << (this->plain[i]).getTime() << ':' << (i + 1) << ", ";
		cout << '\b' << '\b' << ">> ";
		cin >> plainIdx;								// ����� ����
		if (0 < plainIdx && plainIdx <= plainNum)		// ������ 1 �� ����������ε��� 0
			return (plainIdx - 1);
		cout << "[�ٸ��� ���� �Է�]" << endl;
		cin.clear();
		cin.ignore(99, '\n');
	}
}
int Reservation::chooseSeat(int plainIdx) {
	int seat;
	while (true) {
		cout << "�¼� ��ȣ>> ";
		cin >> seat;

		if (0 < seat && (seat <= (plain[plainIdx].getSize())))
			return (seat - 1);
		cout << "[�ٸ��� ���� �Է�]" << endl;
		cin.clear();
		cin.ignore(99, '\n');
	}
}
string Reservation::chooseName() {
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

void Reservation::showSeat(int plainIdx) {
	cout << plain[plainIdx].getTime() << ':';
	for (int i = 0; i < plain[plainIdx].getSize(); i++)
		cout << '\t' << plain[plainIdx].getName(i);
	cout << endl;
}
bool Reservation::modifySeat(int plainIdx, int seatIdx, string seatName, string newName) {
	if ((this->plain[plainIdx]).getName(seatIdx) == seatName) {		// seatName�� �����ϴٸ�
		(this->plain[plainIdx]).setName(seatIdx, newName);			// newName���� ����
		return true;												// �����Ϸ�
	}
	else return false;												// ��������
}

void Reservation::start() {
	cout << "*****" << airName << "�� ���� ���� ȯ���մϴ� *****" << endl << endl;
	while (true) {
		int menu = chooseMenu();
		switch (menu) {
			case 1: {	// ����
				int plainIdx = choosePlain();						// ������ ����� ����
				showSeat(plainIdx);									// �ش� ����� ������Ȳ �ܼ����
				int seatIdx = chooseSeat(plainIdx);					// �¼� �Է�
				string name = chooseName();							// �̸� �Է�
				if (!modifySeat(plainIdx, seatIdx, "---", name))	// �¼���Ȳ ����
					cout << "!!!�������!!!" << endl;
				break;
			}
			case 2: {	// �������
				int plainIdx = choosePlain();						// ����� ����� ����
				showSeat(plainIdx);									// �ش� ����� ������Ȳ �ܼ����
				int seatIdx = chooseSeat(plainIdx);					// �¼� �Է�
				string name = chooseName();							// �̸� �Է�
				if (!modifySeat(plainIdx, seatIdx, name, "---"))
					cout << "!!!��ҽ���!!!" << endl;
				break;
			}
			case 3:		// ������Ȳ
				for (int i = 0; i < plainNum; i++) showSeat(i);
				break;
			case 4:		// ������
				cout << "���� �ý����� �����մϴ�." << endl;
				return;
		}
		cout << endl;
	}
}