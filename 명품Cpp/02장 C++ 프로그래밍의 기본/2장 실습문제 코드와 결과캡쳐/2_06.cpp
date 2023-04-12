/*
해당 프로그램은 두 문자열을 입력받아서 같은지, 다른지 결과를 출력하는 프로그램이다.
문자열을 비교할 때는 두 가지 방법을 사용한다.
첫번째로, string 객체와 = 연산자로 비교해보고
두번째는 c-string 방식으로, 문자열 배열과 strcmp로 비교해볼 것이다.

이에 따라, 헤더파일도 두 가지(string, cstring)를 모두 추가하였다.
*/

#include <iostream>
#include <string>		// 방법1: string 객체 이용
#include <cstring>		// 방법2: strcmp 사용
using namespace std;

int main() {

	// 방법1. string 객체와 = 연산자로 비교
	string pw1, check1;

	// 방법1-1. 입력받기
	cout << "새 암호를 입력하세요>>";
	cin >> pw1;
	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> check1;

	// 방법1-2. 비교하고 출력하기
	if (pw1 == check1)	// 같다면 "같습니다" 출력
		cout << "같습니다" << endl;
	else                // 다르다면 "같지 않습니다" 출력
		cout << "같지 않습니다" << endl;
//----------------------------------------------------

	// 방법2. c-string 방식과 strcmp로 비교
	char pw2[50], check2[50];	// 입력크기가 정해져있다는 단점

	cout << "새 암호를 입력하세요>>";
	cin >> pw2;					// cin.getline을 사용하지 않은 이유는 공백이 없음을 가정했기 때문이다.
	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> check2;

	if (strcmp(pw2, check2))	// 다른 경우, (strcmp는 다를 때, 1이나 -1을 출력하므로)
		cout << "같지 않습니다" << endl;
	else						// 같은 경우,
		cout << "같습니다" << endl;


	return 0;
}

/* BOOK SOLUTION

#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char password1[100];
	char password2[100];
	cout << "새 암호를 입력하세요>>";
	cin >> password1;
	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> password2;
	if(strcmp(password1, password2) == 0)
		cout << "같습니다";
	else
		cout << "같지 않습니다";
	cout << endl;
}
*/