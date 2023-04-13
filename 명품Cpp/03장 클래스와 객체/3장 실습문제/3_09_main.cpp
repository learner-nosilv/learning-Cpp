/*
* Oval 클래스는 주어진 사각형에 내접하는 타원을 추상화한 클래스이다.
* Oval 클래스를 선언부와 구현부로 나누어 작성하라.
*
* 멤버변수:	int형 width, height;
* 멤버함수:	생성자(1. 매개변수X: 전부 1초기화)(2. 매개변수2: 멤버변수 채워줌)
*			소멸자: 멤버변수를 출력
*			멤버변수를 리턴 함수 2개(getWidth, getHeight)
*			멤버변수를 변경하는 함수(set(int w, int h))
*			show() 멤버변수를 출력
*/
#include <iostream>
#include "3_9_Oval.h"
using namespace std;

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getWidth() << ", " << b.getHeight() << endl;
	return 0;
}