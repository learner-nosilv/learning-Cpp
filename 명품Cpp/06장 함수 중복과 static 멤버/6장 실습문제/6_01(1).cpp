/* 1. add()�Լ��� ȣ���ϴ� main()�Լ��� ���� ���ÿ� �°� �ϼ��ϱ�
add(int�� �迭������, int ���Ҽ�)
add(int�� �迭������, int ���Ҽ�, int�� �迭������) (?)
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