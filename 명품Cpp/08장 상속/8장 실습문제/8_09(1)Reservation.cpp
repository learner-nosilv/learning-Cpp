#include "8_09(1)Reservation.h"

int Reservation::chooseMenu() {
	int menu;
	while (true) {
		cout << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
		cin >> menu;
		if (menu == 1 || menu == 2 || menu == 3 || menu == 4)
			return menu;
		cout << "[바르지 않은 입력]" << endl;
		cin.clear();
		cin.ignore(99, '\n');
	}
}
int Reservation::choosePlain() {
	int plainIdx;
	while (true) {
		for (int i = 0; i < plainNum; i++)				// 비행기 선택지 출력
			cout << (this->plain[i]).getTime() << ':' << (i + 1) << ", ";
		cout << '\b' << '\b' << ">> ";
		cin >> plainIdx;								// 비행기 선택
		if (0 < plainIdx && plainIdx <= plainNum)		// 유저의 1 → 실제비행기인덱스 0
			return (plainIdx - 1);
		cout << "[바르지 않은 입력]" << endl;
		cin.clear();
		cin.ignore(99, '\n');
	}
}
int Reservation::chooseSeat(int plainIdx) {
	int seat;
	while (true) {
		cout << "좌석 번호>> ";
		cin >> seat;

		if (0 < seat && (seat <= (plain[plainIdx].getSize())))
			return (seat - 1);
		cout << "[바르지 않은 입력]" << endl;
		cin.clear();
		cin.ignore(99, '\n');
	}
}
string Reservation::chooseName() {
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

void Reservation::showSeat(int plainIdx) {
	cout << plain[plainIdx].getTime() << ':';
	for (int i = 0; i < plain[plainIdx].getSize(); i++)
		cout << '\t' << plain[plainIdx].getName(i);
	cout << endl;
}
bool Reservation::modifySeat(int plainIdx, int seatIdx, string seatName, string newName) {
	if ((this->plain[plainIdx]).getName(seatIdx) == seatName) {		// seatName과 동일하다면
		(this->plain[plainIdx]).setName(seatIdx, newName);			// newName으로 수정
		return true;												// 수정완료
	}
	else return false;												// 수정실패
}

void Reservation::start() {
	cout << "*****" << airName << "에 오신 것을 환영합니다 *****" << endl << endl;
	while (true) {
		int menu = chooseMenu();
		switch (menu) {
			case 1: {	// 예약
				int plainIdx = choosePlain();						// 예약할 비행기 선택
				showSeat(plainIdx);									// 해당 비행기 예약현황 콘솔출력
				int seatIdx = chooseSeat(plainIdx);					// 좌석 입력
				string name = chooseName();							// 이름 입력
				if (!modifySeat(plainIdx, seatIdx, "---", name))	// 좌석현황 변경
					cout << "!!!예약실패!!!" << endl;
				break;
			}
			case 2: {	// 예약취소
				int plainIdx = choosePlain();						// 취소할 비행기 선택
				showSeat(plainIdx);									// 해당 비행기 예약현황 콘솔출력
				int seatIdx = chooseSeat(plainIdx);					// 좌석 입력
				string name = chooseName();							// 이름 입력
				if (!modifySeat(plainIdx, seatIdx, name, "---"))
					cout << "!!!취소실패!!!" << endl;
				break;
			}
			case 3:		// 예약현황
				for (int i = 0; i < plainNum; i++) showSeat(i);
				break;
			case 4:		// 끝내기
				cout << "예약 시스템을 종료합니다." << endl;
				return;
		}
		cout << endl;
	}
}