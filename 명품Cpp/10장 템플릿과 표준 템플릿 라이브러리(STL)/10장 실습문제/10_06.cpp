/* 6. 배열A-배열B인 새로운 배열을 동적할당하여 리턴하는 remove() 제네릭함수*/
#include <iostream>
using namespace std;

template <class T> T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
	T* temp = new T[sizeSrc];		// 배열A-배열B인 새로운 배열의 임시저장소 (크기가 다름)
	int idx = 0;					// 배열A-배열B인 새로운 배열

	for (int i = 0; i < sizeSrc; i++) {
		bool isSame = false;
		for (int j = 0; j < sizeMinus; j++) {
			if (src[i] == minus[j]) {
				isSame = true;
				break;
			}
		}
		if (isSame == false)
			temp[(idx++)] = src[i];
	}
	T* result = new T[idx];				// 배열A-배열B인 새로운 배열 동적할당
	for (int i = 0; i < idx; i++)		// 임시저장소의 값 복사 
		result[i] = temp[i];
	delete[] temp;						// 임시저장소 할당해제
	retSize = idx;						// (idx 안 쓰고 retSize만 써도 충분하지만...)
	return result;
}

int main() {
	int zSize, cSize;
	char x[] = { 'H', 'e', 'l', 'l', 'o', '!' };						// size=6
	char y[] = { 'H', 'i', '!', ' ', 'b', 'u', 'd', 'd', 'y', '?'};		// size=10
	char* z = remove<char>(x, 6, y, 10, zSize);
	for (int i = 0; i < 6; i++) cout << x[i] << ' ';
	cout << '\n';
	for (int i = 0; i < 10; i++) cout << y[i] << ' ';
	cout << '\n';
	for (int i = 0; i < zSize; i++) cout << z[i] << ' ';
	cout << '\n';
	delete[] z;

	double a[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };		// size=6
	double b[] = { 1.1, 2.2, 3.3, 4.4 };				// size=4
	double* c = remove<double>(a, 6, b, 4, cSize);
	for (int i = 0; i < 6; i++) cout << a[i] << ' ';
	cout << '\n';
	for (int i = 0; i < 4; i++) cout << b[i] << ' ';
	cout << '\n';
	for (int i = 0; i < cSize; i++) cout << c[i] << ' ';
	cout << '\n';
	delete[] c;

	return 0;
}