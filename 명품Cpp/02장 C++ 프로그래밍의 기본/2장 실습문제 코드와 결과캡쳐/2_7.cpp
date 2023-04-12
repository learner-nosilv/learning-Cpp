/* BOOK PROBLEM
* 다음과 같이 "yes"가 입력될 때까지 종료하지 않는 프로그램을 작성하라.
* 사용자로부터의 입력은 cin.getline() 함수를 사용하라.
*/

/* 해당 프로그램은  "yes"가 입력될 때까지 종료하지 않는 프로그램이다.
* 사용자로부터 입력을 받아서 비교에 사용될 문자열은 c-string방식과 string객체방식으로 다룰 수 있다.
* 두 방식 중 문제 요구사항이 cin.getline() 이므로 c-string방식을 사용할 것이다.
* 
* c-string방식의 문자열을 비교 할 때에는 strcmp()가 필요하므로
* <cstring> 라이브러리를 사용할 것이다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char answer[50];		// 개행제외 49자를 입력받을 변수

	// 1. 입력 값이 "yes"가 아닌 동안 반복 (같아야 strcmp가 0을 리턴하며 루프를 나온다)
	while (strcmp("yes", answer)) {	// yes와 다르면 loop를 돈다, 탈출조건: yes인 경우
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(answer, 50, '\n');
	}
	cout << "종료합니다..." << endl;

	return 0;
}
	/* 고민의 흔적 & 버퍼를 원하는 느낌으로 비우는 것은 안 됐음ㅠㅠ
	char answer[5];			// yes와 비교할 것이므로, 4글자 다음의 문자부터는 검사할 필요가 없다.
							//answer[4]가 아닌 이유는 yes□를 입력한 경우, yes만 저장되어 yes와 '같음'으로 인식하는 논리적오류의 가능성때문이다.
	char key[4] = "yes";	// y, e, s, \0

	
	while (strcmp(key, answer)) {		// 두 문자열이 다른 상태인 동안 반복한다
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(answer, 5, '\n');	// 최대5자를 입력받아서, 개행문자 전까지를 문자열처리(마지막 글자 \0으로 overwriting)하여 answer에 할당
		cin.clear();					// 입력스트림의 상태를 good state로 초기화
		cin.ignore(999,'\n');			// 
	}
	*/


