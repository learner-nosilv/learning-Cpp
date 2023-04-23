/*
FILE NAME : Family.cpp
AUTHOR : ----학과 -학년 A123456 홍길동
YYYYMMDD : 20230413
PURPOSE :
수업시간에 언급한 것과 같이,
1.	4장의 정답이 공개된 실습문제 4-1를 스스로 학습 하시오. (제출하지 않음)
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

#include "Family.h"									// Family 클래스 선언 헤더파일 include
#include <iostream>									// 입출력을 위한 iostream include	
#include <string>									// string 타입 사용

Family::Family(string name, int size) {				// 가족 이름과 배열 사이즈를 매개변수로 받아 가족 이름은 멤버변수에 저장하고, size만큼의 Person형 객체 배열을 동적 생성하는 생성자
	famName = name;									// 가족이름 저장
	this->size = size;								// size 저장
	p = new Person[size];							// size만큼의 요소를 갖는 Person 형 객체 배열을 동적 할당해 주소를 p에 저장
}
void Family::setName(int index, string name) {		// p의 요소들의 name 값을 변경하는 함수
	p[index].set(name);
}
void Family::show() {								// 가족구성원 출력 맴버함수
	cout << famName << "가족은 다음과 같이 " << size << "명입니다" << endl;
	for (int i = 0; i < size; i++)					// 배열에 저장된 이름 출력
		cout << p[i].getName() << '\t';				
	cout << endl;
}
Family::~Family() {									// 객체가 삭제될 때 동적할당된 p의 메모리 해제
	delete[] p;
}