/*
   FILE NAME : NamedCircle.cpp
   AUTHOR : -
   YYYYMMDD : 2023.05.21
   PURPOSE :
	수업시간에 언급한 것과 같이,
	 1. 8장 ‘실습 문제’ 1,2에서 기술된 대로 수행하는 C++ 프로그램을 작성하고 그 출력결과를 제출하시오.
		① 1번 문제에서 요구하는 NamedCircle클래스를 2번 문제 솔루션 프로그램에서 사용하시오.
			1번 문제에서 제시하는 출력결과를 위한 코드는 작성하지 말고, 2번 문제로 가시오.
		② 2번 문제에서 제시하는 출력결과를 위한 솔루션 파일, NamedCircle.cpp을 작성하는 데 첨부된 다음 파일을 사용하시오
			: NamedCircle[TEMPLATE].cpp
		③ 프로젝트 파일 이름으로 NamedCircleApplication 을 사용하시오.
*/

#include <iostream>			// 표준 입출력 라이브러리
#include <string>			// 문자열 관련 라이브러리
using namespace std;		// C++ 표준 라이브러리의 namespace

class Circle {				// 원
	int radius;				// 반지름
public:
	Circle(int radius = 0) { this->radius = radius; }			// 생성자
	int getRadius() { return radius; }						// 반지름 리턴
	void setRadius(int radius) { this->radius = radius; }	// 반지름 할당
	double getArea() { return 3.14 * radius * radius; };		// 원넓이 리턴
};

class NamedCircle : public Circle {			// 원을 상속받은 derived class 
	string name;							// 이름
public:
	NamedCircle(int radius, string name);	// 생성자: Base class Constructor 실행 후, 실행 됨
	void set(int radius, string name) {		// 멤버변수(반지름과 이름) 할당
		this->setRadius(radius);			// 반지름 할당: Base 클래스의 private 멤버이므로 setRadius 사용
		this->name = name;					// 이름 할당
	}
	string getName() { return name; }		// 이름 리턴
	void show();							// 콘솔 출력 (반지름이 radius인 name)
};

NamedCircle::NamedCircle(int radius = 0, string name = "NONAME") : Circle(radius) {
	this->name = name;						// Base class Constructor 실행 후, 해당 생성자 실행
}

void NamedCircle::show() {
	cout << "반지름이 " << getRadius() << "인 " << name << endl;	// 반지름은 Base 클래스의 private 멤버이므로 getRadius 사용
}

string biggest(NamedCircle p[], int n) {	// 원소 수가 n개인 NamedCircle 배열에서 가장 넓은 원의 이름 리턴
	if (n <= 0)								// 배열의 원소 수가 0인 경우(=오류)
		return "";							// 오류

	int big = 0;							// 원의 배열 중 가장 큰 원의 Index
	//Find the biggest pizza
	for (int i = 1; i < n; i++) {					// 가장 큰 반지름을 가진 원의 Index 찾기
		if (p[big].getRadius() < p[i].getRadius())	// 반지름의 크기만 비교해도, 가장 넓은 원을 판단할 수 있다.
			big = i;								// 가장 큰 반지름 보다 더 큰 반지름을 가진 원이 등장하면 big 업데이트 
	}
		return p[big].getName();					// 원의 배열에서 가장 큰 원의 이름 리턴
}

int main() {
	NamedCircle c[5];								// 5개의 원 객체 베열 선언
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {					// 5개의 원 객체 배열 입력받기
		int r;										// 반지름
		string name;								// 이름
		cout << i + 1 << ">> ";
		cin >> r;									// 반지름 입력받기
		getline(cin, name);							// 이름 입력받기
		if (r <= 0) {								// 입력받은 반지름의 값에 오류가 있는 경우(0, 음수)
			cout << "다시 입력하세요" << endl;
			i--;									// 루프가 재시작되면 i가 1증가하므로, 다시 입력받기위해 i 수정
			continue;								// 루프 재시작
		}

		c[i].set(r, name);							// 입력받은 반지름과 이름으로 원 객체 할당
	}
	cout << "가장 면적이 큰 피자는 " << biggest(c, 5) << "입니다" << endl;
}