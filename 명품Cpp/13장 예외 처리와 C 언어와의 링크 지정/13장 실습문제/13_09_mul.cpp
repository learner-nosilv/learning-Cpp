/* 연습문제 9. get.c와 mul.cpp 파일로 구성되는 프로젝트 작성하기 */
#include <iostream>
using namespace std;

extern "C" int get();
int main() {
	while (true) {
		int a = get();
		int b = get();
		cout << "곱은 " << a * b << "입니다." << endl;
	}
}