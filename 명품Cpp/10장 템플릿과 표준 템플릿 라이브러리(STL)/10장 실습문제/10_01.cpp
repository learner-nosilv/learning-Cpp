/* 525p. 1. 배열을 받아 가장 큰 값을 리턴하는 제네릭 함수 biggest() 작성하기 & 사용
*/
#include <iostream>
using namespace std;

template <class T> T biggest(T arr[], int size) {	// 배열에서 가장 값이 큰 원소의 value 리턴
	int biggest = 0;				// 가장 큰 원소의 index 저장
	for (int i = 1; i < size; i++)	// 검사
		if (arr[biggest] < arr[i])		// 더 큰 원소가 발견되면
			biggest = i;			// 해당 인덱스로 재할당
	return arr[biggest];				// 가장 큰 원소의 값 리턴
}

int main() {
	int x[] = { 1, 2, 3, 4, 5 };
	double y[] = { 1.1, 2.2, 5.5, 100, 2, 13.8, 12.5 };
	char z[] = { 'a', 'd', 'e', 'w', 'l' };

	cout << "1, 2, 3, 4, 5 -> " << biggest<int>(x, 5) << '\n'
		<< "1.1, 2.2, 5.5, 100, 2, 13.8, 12.5 -> " << biggest(y, 7) << '\n'
		<< "a, d, e, w, l -> " << biggest(z, 5) << endl;
	return 0;
}
/*
   solution과의 차이점:
	1. solution은 size에 0이하의 값이 들어온 경우도 고려하였고 나는 안 했다.
		-> solution이 더 괜찮음
	2. solution은 biggest에 가장 큰 값을 할당했고, 나는 인덱스만 할당했다.
		-> solution이 더 괜찮음
	3. solution은 biggest()로 나는 biggest<int>()로 호출
*/