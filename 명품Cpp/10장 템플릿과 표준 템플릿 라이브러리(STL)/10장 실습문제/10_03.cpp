/* 배열의 원소를 반대 순서로 뒤집는 제네릭 함수 reverseArray */
#include <iostream>
using namespace std;

template <class T> void reverseArray(T arr[], int size) {
	int mid = (size / 2);	// 3이면 1[012], 4이면 2[0123], 5이면 2[01234]
	T temp;
	for (int i = 0; i < mid; i++) {
		temp = arr[i];
		arr[i] = arr[(size - 1 - i)];
		arr[(size - 1 - i)] = temp;
	}
}

int main() {
	int x[] = { 1, 2, 3, 4, 5 };
	char y[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	
	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';
	cout << '\n';

	for (int i = 0; i < 6; i++)
		cout << y[i] << ' ';
	cout << endl;

	reverseArray<int>(x, 5);
	reverseArray<char>(y, 6);

	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';
	cout << '\n';

	for (int i = 0; i < 6; i++)
		cout << y[i] << ' ';
	cout << endl;

	return 0;
}