/*5. 두 배열을 연결한 새로운 배열을 동적할당받아서 리턴하는 concat 제네릭 함수 작성하기
*/
#include <iostream>
using namespace std;

template <class T> T* concat(T a[], int aSize, T b[], int bSize) {
	T* concated = new T[aSize + bSize];
	int i = 0;
	for (; i < aSize; i++)
		concated[i] = a[i];
	for (int j = 0; j < bSize; j++) {
		concated[i] = b[j];
		i++;
	}
	return concated;
}

int main() {
	char x[] = { 'H', 'e', 'l', 'l', 'o' };
	char y[] = { ',', ' ', 'b', 'u', 'd', 'd', 'y', '?' };
	char* z = concat<char>(x, 5, y, 8);		// size = 13
	for (int i = 0; i < 13; i++)
		cout << *(z + i) << ' ';
	cout << '\n';
	delete[] z;
	double a[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6 };
	double b[] = { 1.1, 2.2, 3.3, 4.4 };
	double* c = concat<double>(a, 6, b, 4);	// size=10
	for (int i = 0; i < 10; i++)
		cout << *(c + i) << ' ';
	cout << '\n';
	delete[] c;

	return 0;
}