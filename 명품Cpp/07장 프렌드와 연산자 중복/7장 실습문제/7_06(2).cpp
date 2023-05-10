/* 6. (2) �迭
* 2���� ����� �߻�ȭ �� Matrix Ŭ������ �ۼ��ϰ�,
* show() ����Լ��� ���� ������ �����ϵ��� �����ڸ� ��� �����϶�.
* (1) ����Լ��� (2) �������Լ��� �����϶�.
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