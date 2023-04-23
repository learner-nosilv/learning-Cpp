#include <iostream>
using namespace std;

// 원형 선언
void f(char c = ' ', int line = 1);	// 디폴트 있음

// 함수 구현
void f(char c, int line) {
	for (int j = 0; j < line; j++) {
		for (int i = 0; i < 10; i++)
			cout << c;
		cout << endl;
	}
}

int main() {
	f();
	f('%');
	f('@', 5);
}