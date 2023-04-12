#include <iostream>		// cout, cin 객체가 필요하여, C++ 표준입출력라이브러리 헤더파일을 사용한다
using namespace std;	// std 이름공간에 선언된 모든 이름에 대해 std::를 생략한다 (모든 C++ 표준라이브러리는 std 이름공간에 만들어져있다)

int main() {
	for (int num = 1; num <= 100; num++) {
		cout << num;	// 1~100까지 쭉 출력 + 탭
		if (!(num % 10)) {
			cout << endl;		// 만일 10으로 떨어지면 개행하기
		}
		else
			cout << '\t';		// 안 떨어지면 탭으로 분리하기
	}
	return 0;
}

/* BOOK SOLUTION
int main() {
	for(int i=1; i<=100; i++) {
		cout << i;
		if(i%10 == 0) // 10의 배수인 경우
			cout << endl;
		else
			cout << '\t';
	}
}
*/
