/* 예제 13-7		예외처리를 가진 int형 스택 클래스 제작
	용량: int형 100개 */

#include <iostream>
#include "MyStack.h"
using namespace std;

int main() {
	MyStack intStack;
	try {
		intStack.push(100);
		intStack.push(200);
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;		// 예외: throw 발생할 예정
	}
	catch (const char* s) {
		cout << "예외 발생: " << s << endl;
	}
	return 0;
}