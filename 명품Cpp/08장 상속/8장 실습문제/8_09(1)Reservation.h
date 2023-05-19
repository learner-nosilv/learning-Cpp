#ifndef RESERVE_H
#define RESERVE_H

#include <iostream>
#include <string>
#include "8_09(1)Plain.h"

using namespace std;

class Reservation {
	string airName;		// 항공사명
	Plain* plain;		// 항공사 보유 비행기 배열
	int plainNum;		// 항공사 보유 비행기 갯수

	int chooseMenu();											// 예약메뉴 선택
	int choosePlain();											// 비행기 선택
	int chooseSeat(int plainIdx);								// 좌석 입력
	string chooseName();										// 이름 입력

	void showSeat(int plainIdx);								// 특정 비행기 예약현황 콘솔출력
	bool modifySeat(int plainIdx, int seatIdx, string seatName, string newName);	// 특정 비행기 예약수정

public:
	Reservation(string airName, int plainNum) {					// Parameter: 항공사명, 비행기갯수
		this->airName = airName;
		this->plainNum = plainNum;
		plain = new Plain[plainNum];
	}
	~Reservation() { delete[] plain; }							// 소멸자
	void setPlain(int plainIdx, string time, int seatSize) {	// 비행기 하나의 비행시간과 좌석 수 설정
		plain[plainIdx].setTime(time);
		plain[plainIdx].setSeat(seatSize);
	}
	void start();												// 예약개시
};

#endif // !RESERVE_H
