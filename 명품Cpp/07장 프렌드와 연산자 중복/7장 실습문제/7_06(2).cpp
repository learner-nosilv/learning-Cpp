/* 6. (2) 배열
* 2차원 행렬을 추상화 한 Matrix 클래스를 작성하고,
* show() 멤버함수와 다음 연산이 가능하도록 연산자를 모두 구현하라.
* (1) 멤버함수로 (2) 프렌드함수로 구현하라.
*/

#include <iostream>
using namespace std;

class Matrix {
	int arr[4];
public:
	Matrix() { for (int i = 0; i < 4; i++) arr[i] = 0; }
	Matrix(int a, int b, int c, int d) {
		arr[0] = a; arr[1] = b; arr[2] = c; arr[3] = d;
	}

	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++) cout << this->arr[i] << ' ';
		cout << '}' << endl;
	}
	friend Matrix operator+(Matrix a, Matrix b);
	friend Matrix& operator+=(Matrix& a, Matrix b);
	friend bool operator==(Matrix a, Matrix b);
};

Matrix operator+(Matrix a, Matrix b) {
	for (int i = 0; i < 4; i++) a.arr[i] += b.arr[i];
	return a;
}

Matrix& operator+=(Matrix& a, Matrix b) {
	for (int i = 0; i < 4; i++) a.arr[i] += b.arr[i];
	return a;
}

bool operator==(Matrix a, Matrix b) {
	for (int i = 0; i < 4; i++) {
		if (a.arr[i] != b.arr[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
	return 0;
}