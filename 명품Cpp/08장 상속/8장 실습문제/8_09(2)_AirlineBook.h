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
	AirlineBook() {								// ������ : 3���� ����� ��ü �����Ҵ�
		this->size = 3;
		plain = new Schedule[3];
		plain[0].setTime("07��");
		plain[1].setTime("12��");
		plain[2].setTime("17��");
	}
	~AirlineBook() { delete[] plain; }			// �Ҹ��� : plain �����Ҵ� ��ü
	void book();								// ���� �ý��� �۵�
};

#endif // !AIR_H