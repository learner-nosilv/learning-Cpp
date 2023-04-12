/*
   FILE NAME : Person.h
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
// Person 클래스의 선언부 (+ 인라인 함수사용)

#ifndef PERSON_H		// 해당 헤더파일이 한번만 include되도록 설정
#define PERSON_H

#include <string>		// Person클래스의 멤버들이 string 클래스를 사용하므로 string 헤더파일을 추가 https://kldp.org/node/163194
// using namespace std;	string은 std namespace내에 속해있으므로 해당구문을 사용하려 했으나
// " C++ using namespace를 헤더 파일에 사용하지 말자 " 라는 글을 읽고 개별지정(std::)을 하기로 하였다 https://linkmemo.tistory.com/200

class Person {
	std::string name;	// 이름
	std::string tel;	// 전화번호
public:
	Person() {};		// 생성자로 이름과 전화번호를 할당하지 않는다 -> set 멤버함수 이용
	std::string getName() { return name; }	// 멤버변수 이름 반환
	std::string getTel() { return tel; }	// 멤버변수 전화번호 반환
	void setName(std::string name);	// 이름 값을 멤버변수(name)에 할당하는 멤버함수
	void set(std::string name, std::string tel);	// 이름과 전화번호 값을 각 멤버변수에 할당하는 멤버함수
};

#endif