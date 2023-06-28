/* 4. 3의 문제에서 ; 이전에 입력된 문자열만 출력하기
3. 영어문장;한글문자 형식으로 입력될 때, ; 이후에 입력된 문자열만 출력, ctrl+Z는 ^Z로 입력종료를 나타낸다.
cin.ignore()와, cin.get() 사용하기 */
#include <iostream>
using namespace std;

int main() {
	int ch;
	while ((ch = cin.get()) != EOF) {
		if (ch == ';') {
			cin.ignore(100, '\n');
			cout << '\n'; 
			continue;
		}
		cout << (char)ch;
	}
}
