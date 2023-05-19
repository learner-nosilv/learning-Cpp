#ifndef RESERVE_H
#define RESERVE_H

#include <iostream>
#include <string>
#include "8_09(1)Plain.h"

using namespace std;

class Reservation {
	string airName;		// �װ����
	Plain* plain;		// �װ��� ���� ����� �迭
	int plainNum;		// �װ��� ���� ����� ����

	int chooseMenu();											// ����޴� ����
	int choosePlain();											// ����� ����
	int chooseSeat(int plainIdx);								// �¼� �Է�
	string chooseName();										// �̸� �Է�

	void showSeat(int plainIdx);								// Ư�� ����� ������Ȳ �ܼ����
	bool modifySeat(int plainIdx, int seatIdx, string seatName, string newName);	// Ư�� ����� �������

public:
	Reservation(string airName, int plainNum) {					// Parameter: �װ����, ����ⰹ��
		this->airName = airName;
		this->plainNum = plainNum;
		plain = new Plain[plainNum];
	}
	~Reservation() { delete[] plain; }							// �Ҹ���
	void setPlain(int plainIdx, string time, int seatSize) {	// ����� �ϳ��� ����ð��� �¼� �� ����
		plain[plainIdx].setTime(time);
		plain[plainIdx].setSeat(seatSize);
	}
	void start();												// ���ళ��
};

#endif // !RESERVE_H
