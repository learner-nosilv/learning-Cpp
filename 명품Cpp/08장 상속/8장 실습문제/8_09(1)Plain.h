#ifndef PLAIN_H
#define PLAIN_H
#include <string>
using namespace std;

class Plain {
	string time;				// ���� �ð�
	int size;					// �¼� ����
	string* seat;				// �¼� ������ �̸�
public:
	Plain(string time = "", int size = 0) {		// ������
		this->time = time;
		this->size = size;
		seat = new string[size];
	}
	~Plain() { delete[]seat; }					// �Ҹ���
	
	void setTime(string time) { this->time = time; }							// ����� ���� ����
	void setSeat(int size) {													// ����� �¼� �� ����
		delete[] seat;
		this->size = size;
		seat = new string[size];
		for (int i = 0; i < size; i++) (this->seat)[i] = "---";
	}
	void setName(int seatIdx, string name) { (this->seat)[seatIdx] = name; }	
	string getTime() { return this->time; }										// ����� ���� ����
	int getSize() { return this->size; }										// ����� �¼��� ����
	string getName(int seatIdx) { return ((this->seat)[seatIdx]); }				// Ư�� �¼��� ������ �̸� ����
};

#endif // !PLAIN_H
