#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>
using namespace std;

class Seat {		// 하나의 좌석
	string name;	// 예약자
public:
	Seat(string name = "---") { this->name = name; }	// 생성자
	string getName() { return this->name; }				// 예약자 리턴
	void setName(string name) { this->name = name; }		// 예약자 수정
};

#endif