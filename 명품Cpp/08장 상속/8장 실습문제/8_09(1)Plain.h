#ifndef PLAIN_H
#define PLAIN_H
#include <string>
using namespace std;

class Plain {
	string time;				// 비행 시간
	int size;					// 좌석 갯수
	string* seat;				// 좌석 예약자 이름
public:
	Plain(string time = "", int size = 0) {		// 생성자
		this->time = time;
		this->size = size;
		seat = new string[size];
	}
	~Plain() { delete[]seat; }					// 소멸자
	
	void setTime(string time) { this->time = time; }							// 비행기 일정 변경
	void setSeat(int size) {													// 비행기 좌석 수 변경
		delete[] seat;
		this->size = size;
		seat = new string[size];
		for (int i = 0; i < size; i++) (this->seat)[i] = "---";
	}
	void setName(int seatIdx, string name) { (this->seat)[seatIdx] = name; }	
	string getTime() { return this->time; }										// 비행기 일정 리턴
	int getSize() { return this->size; }										// 비행기 좌석수 리턴
	string getName(int seatIdx) { return ((this->seat)[seatIdx]); }				// 특정 좌석의 예약자 이름 리턴
};

#endif // !PLAIN_H
