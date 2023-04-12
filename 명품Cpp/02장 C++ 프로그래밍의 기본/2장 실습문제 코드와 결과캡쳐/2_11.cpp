// C프로그램 C++로 수정하기
// 숫자N를 입력받아서 1~N까지의 합 출력

#include <iostream>		// <stdio.h>와 비슷
using namespace std;	// namespace 개념 도입

int main() {
	int k, n = 0;
	int sum = 0;

	cout << "끝 수를 입력하세요>>";	// printf()
	cin >> n;						// scanf("%d", &n)
	for (k = 1; k <= n; k++) {		// k: 1 ~ n 루프
		sum += k;					// 1 ~ n 합산
	}
	cout << "1에서 " << n << "까지의 합은 " << sum << " 입니다." << endl;
	return 0;
}

/* SOLUTION of BOOK
* #include <iostream>
using namespace std;

int main() {
	int n=0;
	cout << "끝 수를 입력하세요>>";
	cin >> n;
	if(n <= 0) {
		cout << "양수를 입력하세요!" << endl;
		return 0;
	}
	int k, sum=0;
	for(k=1; k<=n; k++) {
		sum += k;
	}
	cout << "1에서 " << n << "까지의 합은 " << sum << "입니다." << endl;
	return 0;
}
*/