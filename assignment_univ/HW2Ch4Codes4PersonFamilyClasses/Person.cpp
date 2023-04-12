/*
   FILE NAME : Person.cpp
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
// Person 클래스의 구현부

#include "Person.h"

// setName 함수로 멤버변수 name값을 (재)초기화한다
void Person::setName(std::string name) {
	this->name = name;	// name파라미터의 값을 멤버변수 name에 할당
}
// set 함수로 멤버변수 name과 tel값을 초기화한다
void Person::set(std::string name, std::string tel) {
	this->name = name;	// 객체를 가리키는 포인터변수 this 사용
	this->tel = tel;	// 파라미터 tel의 값을 멤버변수 tel에 할당
}