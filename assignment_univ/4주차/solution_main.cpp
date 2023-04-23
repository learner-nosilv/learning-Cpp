/*
FILE NAME : main.cpp
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

#include "Family.h"						// 헤더파일 include
#include "Person.h"						

#include <iostream>						// 입출력을 위한 iostream 헤더파일 include 
#include <string>						// string 헤더파일 include
using namespace std;

int main() {
	Person p[3];						// 객체 배열 생성
	cout << "이름과 전화 번호를 입력해 주세요" << endl;
	for (int i = 0; i < 3; i++) {		// 이름과 전화 번호를 입력
		string n = ""; string t = "";
		cout << "사람 " << i + 1 << ">> ";
		cin >> n >> t;
		p[i].set(n, t);					// Person 클래스 멤버 함수를 사용해 name과 tel 값 변경
	}
	cout << "모든 사람의 이름은 ";			// 이름 출력
	for (int i = 0; i < 3; i++) {
		cout << p[i].getName() << ' ';	// getName 맴버함수는 name 을 리턴함
	}
	cout << endl << "전화번호 검색합니다. 이름을 입력하세요>> ";
	string sn = ""; int count = 0;			// 검색할때 쓸 string 변수 sn과 오류검출을 위한 변수 count 생성 및 초기화
	cin >> sn;
	for (int i = 0; i < 3; i++) {
		if (sn == p[i].getName()) {			// 검색
			cout << "전화 번호는 " << p[i].getTel() << endl << endl << endl;
			count++;						// count == 0 이면 검색결과 없음
		}
	}
	if (count == 0)							// count == 0 이면 검색결과 없음
		cout << "이름을 잘 못 입력했거나 없는 이름입니다." << endl;

	Family* simpson = new Family("Simpson", 3); // 생성자는 p가 Person 오브젝트 3개를 요소로 가지는 배열로 초기화하고 new 함수를 통해 그만큼의 메모리를 동적할당 해 simpson 포인터에 주소값 리턴 
	simpson->setName(0, "Mr. Simpson");			// index 0 번째 요소에 저장
	simpson->setName(1, "Mrs. Simpson");		// index 1 번째 요소에 저장
	simpson->setName(2, "Bart Simpson");		// index 2 번째 요소에 저장
	simpson->show();							// 가족 구성원 출력
	delete simpson;								// 동적으로 할당된 메모리 해제
}