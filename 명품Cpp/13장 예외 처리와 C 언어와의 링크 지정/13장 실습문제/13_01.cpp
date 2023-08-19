/* 연습문제 1. sum(int a, int b): a애서 b까지의 정수합 리턴
	예외1: a>b
	예외2: 둘 중 하나라도 음수인 경우
	위의 예외를 처리할 수 있는 sum()함수 만들기*/
#include <iostream>
using namespace std;

int sum(int a, int b) throw(const char*) {
	if (a < 0 || b < 0) throw "음수 처리 안 됨";
	if (a > b) throw "잘못된 입력";
	int result = a;
	while (a < b) {
		a++;
		result += a;
	}
	return result;
}

int main() {
	try {
		cout << sum(2, 5) << endl;	// 정상
		cout << sum(-1, 5) << endl;	// 오류
	}
	catch (const char* s) {
		cout << s << endl;
	}
	return 0;
}
// const가 아닌 char* 로 하면 디버그 에러남