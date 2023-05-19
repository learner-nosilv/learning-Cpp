/* 9. 비행기 예약 프로그램 : 힌트이용 + 파일분할
	1. 3가지의 비행시간으로 비행기구분 -> 비행기 객체
	2. 비행기 당 좌석 8개 구분 : 좌석번호, 이름 저장
	3. 예약 / 취소 / 보기 / 끝내기
	비행기 클래스 : 멤버 좌석(string 배열)
	예약 클래스 : 비행기 3 배열
	*/
#include <iostream>
#include <string>
#include "Seat.h"
#include "Schedule.h"
#include "Console.h"
#include "AirlineBook.h"

using namespace std;

int main() {
	AirlineBook hansung;				// 한성항공 예약 시스템 객체 생성
	hansung.book();

	return 0;
}