/* 2.
* 정수 5개 동적할당
* 입력받기
* 평균구하고 출력하기
* 동적할당-소멸
*/

#include <iostream>
using namespace std;

int main() {
	// 1. 크기가 5인 정수형 배열 동적할당
	int* p = new int[5];			

	// 2. 정수 5개 입력받기
	cout << "정수 5개 입력>> ";		// 정수
	for (int i = 0; i < 5; i++)		// 5번 입력받기
		cin >> *(p + i);

	// 3. 평균 구하여 출력하기
	double average = *(p);
	for (int i = 1; i < 5; i++)
		average += *(p + i);
	average /= 5;
	cout << "평균 " << average << endl;

	// 4. 동적할당 -> 소멸
	delete[]p;

	return 0;
}