#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include "Seat.h"

using namespace std;

class Schedule {	// 하나의 비행기 스케쥴
	string time;	// 비행시간
	Seat* seat;		// 좌석
	int size;		// 좌석 수
public:
	Schedule() { this->size = 8; seat = new Seat[8]; }			// 생성자 : 8개의 Seat객체 동적할당
	~Schedule() { delete[] seat; }								// 소멸자 : Seat 동적할당 해제
	void setTime(string time) { this->time = time; }
	string getName(int idx) { return seat[idx].getName(); }
	void showReservation() {
		cout << time << ':';
		for (int i = 0; i < size; i++)	cout << '\t' << seat[i].getName();
		cout << endl;
	}
	void reservation(int idx, string name) {														// 예약진행
		if (seat[idx].getName() == "---") seat[idx].setName(name);
		else cout << "[예약실패] 이미 예약된 좌석입니다." << endl;
	}
	void cancle(int idx, string name) {																// 예약취소
		if (seat[idx].getName() == name) seat[idx].setName("---");
		else cout << "[취소실패] 예약자 이름이 다릅니다." << endl;
	}
};

#endif // !SCHEDULE_H
