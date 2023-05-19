#include "AirlineBook.h"

void AirlineBook::book() {
	cout << "***** 한성항공에 오신 것을 환영합니다 *****" << '\n' << '\n';
	while(true){
		int menu = Console::chooseMenu();
		switch (menu) {
			case 1: {									// 1. 예약
				int time = Console::chooseTime();		// 시간 선택
				time--;
				plain[time].showReservation();			// 해당 시간의 스케줄
				int seat = Console::chooseSeat();		// 좌석 선택
				seat--;
				string name = Console::chooseName();	// 이름 입력
				plain[time].reservation(seat, name);	// 예약 진행
				break;
			}
			case 2: {									// 2. 취소
				int time = Console::chooseTime();		// 시간 선택
				time--;
				plain[time].showReservation();			// 해당 시간의 스케줄
				int seat = Console::chooseSeat();		// 좌석 선택
				seat--;
				string name = Console::chooseName();	// 이름 입력
				plain[time].cancle(seat, name);			// 취소 진행
				break;
			}
			case 3:										// 3. 보기
				for (int i = 0; i < 3; i++)
					plain[i].showReservation();
				break;
			case 4:										// 4. 끝내기
				cout << "예약 시스템을 종료합니다." << endl;
				return;
		}
		cout << endl;
	}
}