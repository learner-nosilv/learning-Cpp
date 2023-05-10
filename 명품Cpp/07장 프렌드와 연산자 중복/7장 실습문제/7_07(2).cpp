/* 7. (2) 
* main()함수와 콘솔결과를 보고 2차원 행렬을 추상화 한 Matrix 클래스를 작성하기
* <<, >> 연산자 함수를 (1) 멤버함수로 (2) 프렌드함수로 구현하라.
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
	friend void operator<<(Matrix& a, int x[]);
	friend void operator>>(Matrix a, int x[]);
};

void operator<<(Matrix& a, int x[]) {	
	for (int i = 0; i < 4; i++) a.arr[i] = x[i]; // call by reference
	return;
}

void operator>>(Matrix a, int x[]) {	
	for (int i = 0; i < 4; i++) x[i] = a.arr[i]; // call by address
	return;
}


int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1, 2, 3, 4 };
	a >> x;	// a의 각 원소를 배열 x에 복사
	b << y; // 배열 y의 원소값을 b의 각 원소에 설정

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();

	return 0;
}