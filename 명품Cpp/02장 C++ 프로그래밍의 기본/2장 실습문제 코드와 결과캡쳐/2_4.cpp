#include <iostream>
#define N 5
using namespace std;

// main함수: 5개의 실수를 입력받고 그 중 제일 큰 수를 화면에 출력하는 함수
int main() {
	float num[N];
	
	// 1. 입력: 값 5개 입력받기 (순차)
	cout << N << " 개의 실수를 입력하라>>";
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	// 2. 값 비교하기	(순차)
	for (int i = 1; i < N; i++) {				// 순차검색
		if (num[0] < num[i]) num[0] = num[i];	// 제일 큰 수 = num[0]
	}
	
	/* 1, 2의 과정이 비슷하기때문에 하나의 반복문으로 입력과 비교를 동시에 진행해도 될 듯 하지만,
	* 한 번에 5개를 입력할 가능성도 있어서 반복문을 따로 돌렸다.
	*/

	// 3. 출력: 가장 큰 값
	cout << "제일 큰 수 = " << num[0];

	return 0;
}
