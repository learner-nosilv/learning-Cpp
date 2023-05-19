/* 9. 비행기 예약 프로그램 :
	1. 3가지의 비행시간으로 비행기구분 -> 비행기 객체
	2. 비행기 당 좌석 8개 구분 : 좌석번호, 이름 저장
	3. 예약 / 취소 / 보기 / 끝내기
	비행기 클래스 : 멤버 좌석(string 배열)
	예약 클래스 : 비행기 3 배열
	*/
#include <iostream>
#include <string>
#include "8_09(1)Reservation.h"
using namespace std;

int main() {
	Reservation hansung("한성항공", 3);			// 한성항공, 비행기 3대
	hansung.setPlain(0, "07시", 8);				// 비행기[0]: 시간, 좌석수
	hansung.setPlain(1, "12시", 8);				// 비행기[1]: 시간, 좌석수
	hansung.setPlain(2, "17시", 8);				// 비행기[2]: 시간, 좌석수
	hansung.start();

	return 0;
}