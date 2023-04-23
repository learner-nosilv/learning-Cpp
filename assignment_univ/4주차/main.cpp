/*
   FILE NAME : Person.h, Family.h, Person.cpp, Family.cpp, main.cpp
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

#include <iostream>	// 표준 입출력 라이브러리
#include "Family.h"	// Family 클래스의 선언부
#include "Person.h"	// Person 클래스의 선언부

#define N 3			// 문제 9의 Person 객체수와 문제 10의 Family 속 Person객체수 (현재 3개로 설정)

using namespace std;

// 오류처리함수: 입력버퍼상태가 오류인지 아닌지 반환하는 함수	*오류인 경우, 버퍼를 정상화하고 오류임을 알린다.
bool isError() {
	if (cin.fail()) {	// 입력스트림버퍼가 오류상태인 경우
		cin.clear();			// 버퍼의 상태를 초기화하고
		cin.ignore(100, '\n');	// 버퍼에 들어있는 값 100개 혹은 개행까지를 버린다
		cout << "Input Error" << endl;	// 입력오류임을 콘솔로 출력한다
		return true;
	}
	else
		return false;
}

// [9번]		3개의 Person 객체를 가지는 배열을 선언하고 다음과 같이 키보드에서 이름과 전화번호를 입력받아 출력하고 검색
// [10번]	3명의 Person 객체로 구성된 Simpson가족을 선언하고 모든 가족구성원을 출력
int main() {
	// -[9번]-----------------------
	// 1. 3개의 Person 객체 선언
	Person a[N];	// 크기가 3인 Person 배열 선언 (N=3)

	// 2. 이름과 전화번호를 사용자로부터 입력받은 후, 멤버함수 set()을 이용하여 각 객체의 멤버변수(name, tel)에 할당한다.
	cout << "이름과 전화 번호를 입력해 주세요" << endl;
	string temp_n, temp_tel;			// 사용자 입력을 저장할 변수
	for (int i = 0; i < N;) {			// 루프: 배열의 인덱스 < N이 될 때까지 돈다
		cout << "사람 " << i + 1 << ">> ";	// 입력받기
		cin >> temp_n >> temp_tel;
		if (!isError()) {					// 입력오류가 안 난 경우
			a[i].set(temp_n, temp_tel);		// 입력받은 이름과 전화번호 값을 실제 멤버변수(name, tel)에 할당한다.
			i++;							// 인덱스 1 증가로 다음원소객체에 접근
		}									// 입력오류가 난 경우, 인덱스 증가X
	}
	
	// 3. 모든 사람의 이름을 출력한다.
	cout << "모든 사람의 이름은";
	for (int i = 0; i < N; i++) {		// 루프: N회
		cout << ' ' << a[i].getName();	// public인 멤버함수 getName을 통해 name의 값을 출력한다 
	}
	cout << endl;

	// 4. 이름을 입력받으면 그에 맞는 전화번호를 출력한다
	// 4-1. 이름 임력받기
	cout << "전화번호 검색합니다. 이름을 입력하세요>>";
	do {							// 우선,
		cin >> temp_n;				// 입력을 1회 받은 후
	} while (isError() == true);	// 루프: 버퍼에 오류가 있다면 다시 입력을 받는다 (종료조건: 버퍼에 오류가 없으면)

	// 4-2. 사용자가 입력한 이름값과 동일한 name을 가진 객체를 찾고, 해당 객체의 전화번호 tel 출력
	for (int i = 0; i < N; i++) {		// 루프: N회 이하 (종료조건: 모든 객체(N개)를 비교한 경우 or 동일한 이름이 발견된 경우)
		if (temp_n == a[i].getName()) {	// 사용자가 입력한 이름이 Index가 i인 객체의 이름과 일치한다면
			cout << "전화 번호는 " << a[i].getTel() << endl;	// 해당 이름의 전화번호인 멤버변수 tel 를 출력한다
			break;											// 더 검색할 필요가 없으므로 [루프종료]
		}
		else if (i == N - 1) {			// 마지막 루프문에서도 사용자가 입력한 이름이 발견되지 않으면(=루프종료직전)
			cout << "해당 이름을 가진 Person은 없습니다." << endl;	// 없음을 알린다
		}
	}
	// -[10번]-----------------------
	// 1. 1개의 Family 객체(구성원 수가 3인) 선언
	Family* simpson = new Family("Simpson", N);		// size가 3인 person형 배열을 가진 Family 객체 포인터 simpson 을 메모리동적할당

	// 2. 구성원에 이름부여: Family형 객체의 멤버변수인 People형 배열의 각 원소에 이름할당
	simpson->setName(0, "Mr. Simpson");		// person형 배열의 0번 객체 이름을 "Mr.Sim.."으로 초기화
	simpson->setName(1, "Mrs. Simpson");	// person형 배열의 1번 객체 이름을 "Mrs.Sim.."으로 초기화
	simpson->setName(2, "Bart Simpson");	// person형 배열의 2번 객체 이름을 "Bart Sim.."으로 초기화

	// 3. Family 객체의 People형 구성원 총 원과 이름 전부 출력
	simpson->show();	// Family형 객체 멤버함수 show 호출	
	delete simpson;		// 메모리 해제

	return 0;
}


/*
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
	*/