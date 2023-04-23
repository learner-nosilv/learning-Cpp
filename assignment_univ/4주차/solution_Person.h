//#pragma once
/*
FILE NAME : Person.h
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

#ifndef PERSON_H					// 중복 include 방지
#define PERSON_H
#include <string>					// string 해더파일 include
using namespace std;

class Person {						// Person 클래스 선언부
	string name;					// 맴버변수 : 이름 
	string tel;						// 맴버변수 : 전화번호
public:
	Person();							// 생성자
	Person(string name, string tel);	// 생성자
	string getName();					// 맴버변수 name 리턴
	string getTel();					// 맴버변수 tel 리턴
	void set(string name, string tel);	// 멤버변수에 접근해 name과 tel 값을 모두 변경하는 함수
	void set(string name);				// 멤버변수에 접근해 name 값 만을 변경하는 함수 (함수 오버로딩을 이용함)
};

#endif