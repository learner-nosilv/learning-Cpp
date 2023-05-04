/* 1. add()함수를 호출하는 main()함수를 보고 지시에 맞게 완성하기
add(int형 배열포인터, int 원소수)
add(int형 배열포인터, int 원소수, int형 배열포인터) (?)
*/

#include <iostream>
using namespace std;


int add(int* arr1, int size) {
	int result = 0;
	for (int i = 0; i < size; i++)
		result += arr1[i];
	return result;
}

int add(int* arr1, int size, int* arr2) {
	int result = 0;
	for (int i = 0; i < size; i++)
		result += (arr1[i] + arr2[i]);
	return result;
}

int main() {
	int a[] = { 1, 2, 3, 4, 5 };
	int b[] = { 6, 7, 8, 9, 10 };
	int c = add(a, 5);
	int d = add(a, 5, b);
	cout << c << endl;
	cout << d << endl;

	return 0;
}