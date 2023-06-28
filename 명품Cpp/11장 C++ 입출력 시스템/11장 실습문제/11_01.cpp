/*1. int cin.get() 함수를 이용하여 한 라인을 읽고 a 가 몇 개인지 출력하는 프로그램*/
#include <iostream>
using namespace std;

int main() {
	int ch;
	int count = 0;
	cout << "입력>> ";
	while ((ch = cin.get()) != '\n') {
		if (ch == 'a') count++;
	}
	cout << "a의 갯수>> " << count;

	return 0;
}

// 솔루션이랑 차이 : EOF처리 나는 안해서... 