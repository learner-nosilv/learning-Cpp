#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>
using namespace std;

class Seat {		// �ϳ��� �¼�
	string name;	// ������
public:
	Seat(string name = "---") { this->name = name; }	// ������
	string getName() { return this->name; }				// ������ ����
	void setName(string name) { this->name = name; }		// ������ ����
};

#endif