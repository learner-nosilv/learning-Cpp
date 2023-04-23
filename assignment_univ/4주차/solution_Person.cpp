/*
FILE NAME : Person.cpp
AUTHOR : ----학과 -학년 A123456 홍길동
YYYYMMDD : 20230413
PURPOSE : 
수업시간에 언급한 것과 같이,
1. 4 장의 정답이 공개된 실습문제 4-1 를 스스로 학습 하시오. (제출하지 않음)
2. 4 장의 실습문제 4-9,4-10 은 서로 연관이 되어있는 문제들이니, 다음의 과정들을 따라 소스코드를
작성하고 그 실행결과를 보이시오.
1) 실습문제 4-9,4-10 모두에서 사용되는 Person class 의 member variables & functions 을
모두 합쳐서 통합된 Person class 를 작성하시오.
2) 4-9 의 출력결과가 나올 수 있도록 Person class 와 main() 함수를 작성하시오.
3) 실습문제 4-10 에서 제시한 main()가 작동되도록 Person class 와 Family class 에 필요한
member 들을 추가하여 코드를 완성하시오.
4) 1)~3)에서 작성 한 코드의 출력결과는 4-9 와 4-10 의 출력결과 모두를 순서대로 동일하게
출력할 수 있어야 합니다.
5) 3 장 예제 3-11 에서 보여준 것 같이, 위의 1)~3)에서 작성 한 코드를 다음과 같은 header
파일과 cpp 파일들로 분리하여 재작성하시오:
 Person.h, Family.h, Person.cpp, Family.cpp, main.cpp
*/

#include "Person.h"									// Person 클래스 선언 헤더파일 include

#include <string>									// string 헤더파일 include
using namespace std;

Person::Person() : Person("", "") { }				// name 과 tel을 ""로 초기화하는 기본 생성자
Person::Person(string name, string tel) {			// name 과 tel에 매개변수 값을 대입하는 생성자
	this->name = name;								// 매개변수와 멤버 변수 값의 이름이 같으므로 this 포인터 사용
	this->tel = tel;
}
string Person::getName() {							// 멤버 변수 name을 리턴하는 멤버 함수
	return name;
}
string Person::getTel() {							// 멤버 변수 tel을 리턴하는 멤버 함수
	return tel;
}
void Person::set(string name, string tel) {			// 멤버 변수에 접근해 값을 변경하는 멤버 함수
	this->name = name;								// 매개변수와 멤버변수의 이름이 같으므로 this 포인터 사용
	this->tel = tel;
}
void Person::set(string name) {						// 멤버 변수 name에 접근해 값을 변경하는 멤버 함수
	this->name = name;								// 매개변수와 멤버변수의 이름이 같으므로 this 포인터 사용
}