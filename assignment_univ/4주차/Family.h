/*
   FILE NAME : Family.h
   AUTHOR : 
   YYYYMMDD : 2023.04.06
   PURPOSE :
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
// Family 클래스의 선언부
#ifndef FAMILY_H		// 해당 헤더파일이 한번만 include되도록 설정
#define FAMILY_H

#include <string>		// 문자열 객체
#include "Person.h"		// Family class는 Person class를 사용한다

// 가족을 의미하는 Family 클래스 선언부
class Family {
	std::string name;	// 가족 이름
	Person* p;		// Person형 배열을 가리키는 포인터: 각 가족구성원을 Person형 객체로 구현
	int size;		// Person형 배열 p의 크기: 가족구성원 수
public:
	Family(std::string name, int size);	// 생성자: 가족이름과 가족구성원의 수를 입력값으로 갖는다
	void setName(int index, std::string person_name);	// 가족구성원의 이름을 기입하는 함수
	void show();	// 가족의 총 인원(size)과 가족구성원의 이름을 전부 출력하는 함수
	~Family() {};	// 소멸자

};

#endif

/*
* #ifndef FAMILY_H							// 중복 include 방지
#define FAMILY_H

#include "Person.h"							// Person 해더파일 include
#include <string>							// string 해더파일 include 
using namespace std;

class Family {								// Family 클래스 선언부
	Person* p;								// Person형 객체배열을 생성할때 받을 포인터
	int size;								// 배열의 사이즈
	string famName;							// 가족 이름
public:
	Family(string name, int size);			// 생성자
	void setName(int index, string fn);		// 가족 구성원 이름 저장
	void show();							// 구성원 출력
	~Family();								// 소멸자
};

#endif
*/