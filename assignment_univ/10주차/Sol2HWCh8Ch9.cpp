/*
   FILE NAME : Sol2HWCh8Ch9.cpp
   AUTHOR : -
   YYYYMMDD : 2023.05.14
   PURPOSE :
   수업시간에 언급한 것과 같이,
	1. 8 장 ‘실습 문제’ 1,2 에서 기술된 대로 수행하는 C++ 프로그램을 작성하고 그 출력결과를 제출하시오.

*/

/* 1, 2. Circle 클래스를 상속받는 NamedCircle를 작성하기
*/
#include <iostream>												// 표준 입출력 라이브러리
#include <string>												// 문자열 라이브러리
using namespace std;											// C++ 표준

class Circle {													// 원 클래스
	int radius;													// 반지름
public:
	Circle(int radius = 0) { this->radius = radius; }			// 생성자: 멤버변수 radius 할당
	int getRadius() { return this->radius; }					// Return 멤버변수radius
	void setRadius(int radius) { this->radius = radius; }		// Assign 멤버변수radius
	double getArea() { return 3.14 * radius * radius; }			// Return 원 넓이
};

class NamedCircle : public Circle {								// 원 클래스를 상속받는 이름있는 원 클래스
	string name;												// 이름
public:
	NamedCircle(int radius=0, string name = "") : Circle(radius) { this->name = name; }	// 생성자: 멤버변수 name 할당
	void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }			// 콘솔출력: 반지름이 radius인 name
	void setName(string name) { this->name = name; }									// Assign 멤버변수 name
	string getName() { return this->name; }												// Return 멤버변수 name
};

int main() {
	NamedCircle waffle(3, "waffle");							// 반지름이 3, 이름이 "waffle"인 NamedCircle클래스 객체 waffle 생성
	waffle.show();												// 콘솔출력: 반지름이 3인 waffle
	cout << "---P8.1----------------------------------------------" << endl;

	NamedCircle pizza[5];										// NamedCircle클래스 객체배열 pizza 생성, 크기 5개
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;	// 입력받기
	for (int i = 0; i < 5; i++) {								// 5회
		int radius;						// 반지름
		string name;					// 이름
		cout << i + 1 << ">> ";			// 1>>
		cin >> radius;					// 반지름 입력받기
		cin >> name;					// 이름 입력받기(공백사용X)
		pizza[i].setRadius(radius);		// Assign 멤버변수radius
		pizza[i].setName(name);			// Assign 멤버변수 name
	}

	int widest = 0;													// 객체베열 pizza의 원소 중 가장 넓은 원인 원소의 INDEX
	for (int i = 1; i < 5; i++) {									// 모든 원소 살펴보기
		if (pizza[widest].getRadius() < pizza[i].getRadius())		//	반지름이 큰 원소의 INDEX를
			widest = i;												//	widest에 할당
	}
	cout << "가장 면적이 큰 피자는 " << pizza[widest].getName() << "입니다" << endl;	// 가장 넓은 원 출력
	cout << "---P8.2----------------------------------------------" << endl;
	return 0;
}