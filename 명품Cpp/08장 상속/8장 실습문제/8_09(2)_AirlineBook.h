#ifndef AIR_H
#define AIR_H

#include "Schedule.h"
#include "Console.h"
#include <iostream>
using namespace std;

class AirlineBook {
	Schedule* plain;
	int size;
public:
	AirlineBook() {								// 생성자 : 3개의 비행기 객체 동적할당
		this->size = 3;
		plain = new Schedule[3];
		plain[0].setTime("07시");
		plain[1].setTime("12시");
		plain[2].setTime("17시");
	}
	~AirlineBook() { delete[] plain; }			// 소멸자 : plain 동적할당 해체
	void book();								// 예약 시스템 작동
};

#endif // !AIR_H