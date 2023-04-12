// C프로그램 C++로 수정하기
// 숫자N를 입력받아서 1~N까지의 합 출력

#include <iostream>		// <stdio.h>와 비슷
using namespace std;	// namespace 개념 도입

int sum(int, int);		// 함수 원형 선언

int main() {
	int n = 0;
	cout << "끝 수를 입력하세요>>";	// printf()
	cin >> n;						// scanf("%d", &n)
	cout << "1에서 " << n << "까지의 합은 " << sum(1,n) << " 입니다." << endl;

	return 0;
}

// 함수sum: a부터 b까지의 합산값을 반환한다.
int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {		// k: a ~ b 루프
		res += k;					// k ~ n 합산
	}
	return res;
}