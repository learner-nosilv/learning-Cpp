/* 1. add()�Լ��� ȣ���ϴ� main()�Լ��� ���� ���ÿ� �°� �ϼ��ϱ�
add(int�� �迭������, int ���Ҽ�)
add(int�� �迭������, int ���Ҽ�, int�� �迭������) (?)
(2) �� add�Լ��� default parameter�� �̿��Ͽ� �ϳ��� �ۼ��ϱ�
*/

#include <iostream>
using namespace std;


int add(int* arr1, int size, int* arr2 = nullptr) {
	int result = 0;
	if (arr2 == nullptr) {
		for (int i = 0; i < size; i++)
			result += arr1[i];
	}
	else {
		for (int i = 0; i < size; i++)
			result += (arr1[i] + arr2[i]);
	}
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