/*
* 주기억장치를 모델링하는 클래스 RAM
* 멤버변수: 데이터가 기록될 메모리공간(mem[100*1024])과 크기정보(size)
* 멤버함수:	생성자(매개변수X) 배열0, size=100*1024초기화
*			소멸자 "메모리제거됨" 출력
*			char read(int address) 해당 address의 메모리바이트 리턴
*			void write(주소, 문자) 해당 주소에 문자저장
* 
* * 숫자모양의 문자열을 문자로 인식하는게 무슨말이지?
* * char형 배열의 한 칸에 int값을 집어넣고
*	char형 배열을 + 하는데 int형으로 더하기계산이 되고
*	왜 그런지 모르겠다!_!
*/
#include <iostream>
#include "3_12_Ram.h"

using namespace std;

int main() {
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl;
	return 0;
}