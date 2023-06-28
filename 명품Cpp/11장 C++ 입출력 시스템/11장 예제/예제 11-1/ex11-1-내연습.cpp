#include<iostream>
using namespace std;

int main() {
	char ch = '\n';
	cout.put('H');	// 상수 리터럴
	cout.put('i');
	cout.put(33);	// ASCII 코드값
	cout.put(ch);	// 변수
	cout.flush();	// 스트림 버퍼에 남아있는 문자를 강제출력하는 flush (무엇이 출력되나 궁금한데)
	// flush로 출력된 것은 없다. 542p의 설명이 많이 모호하다.

	cout.put('C').put('+').put('+').put(' ');
	// put()함수는 리턴타입이 ostream& 라는 참조리턴이기때문에 연결사용이 가능하다.

	char str[] = "I love programming";
	cout.write(str, 6);	// 6글자만 출력
	cout.flush();

	return 0;
}