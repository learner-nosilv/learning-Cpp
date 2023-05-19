#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include "Seat.h"

using namespace std;

class Schedule {	// �ϳ��� ����� ������
	string time;	// ����ð�
	Seat* seat;		// �¼�
	int size;		// �¼� ��
public:
	Schedule() { this->size = 8; seat = new Seat[8]; }			// ������ : 8���� Seat��ü �����Ҵ�
	~Schedule() { delete[] seat; }								// �Ҹ��� : Seat �����Ҵ� ����
	void setTime(string time) { this->time = time; }
	string getName(int idx) { return seat[idx].getName(); }
	void showReservation() {
		cout << time << ':';
		for (int i = 0; i < size; i++)	cout << '\t' << seat[i].getName();
		cout << endl;
	}
	void reservation(int idx, string name) {														// ��������
		if (seat[idx].getName() == "---") seat[idx].setName(name);
		else cout << "[�������] �̹� ����� �¼��Դϴ�." << endl;
	}
	void cancle(int idx, string name) {																// �������
		if (seat[idx].getName() == name) seat[idx].setName("---");
		else cout << "[��ҽ���] ������ �̸��� �ٸ��ϴ�." << endl;
	}
};

#endif // !SCHEDULE_H
