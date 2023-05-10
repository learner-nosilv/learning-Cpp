/* 6. (1)
* 2���� ����� �߻�ȭ �� Matrix Ŭ������ �ۼ��ϰ�,
* show() ����Լ��� ���� ������ �����ϵ��� �����ڸ� ��� �����϶�.
* (1) ����Լ��� (2) �������Լ��� �����϶�.
*/

#include <iostream>
using namespace std;

class Matrix {
	int a, b, c, d;
public:
	Matrix() { this->a = this->b = this->c = this->d = 0; }
	Matrix(int a, int b, int c, int d) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	void show() {
		cout << "Matrix = { " << this->a << ' ' << this->b << ' ' 
			<< this->c << ' ' << this->d << " }" << endl;
	}
	Matrix operator+(Matrix a) {
		a.a += this->a;
		a.b += this->b;
		a.c += this->c;
		a.d += this->d;
		return a;
	}
	Matrix& operator+=(Matrix a) {
		this->a += a.a;
		this->b += a.b;
		this->c += a.c;
		this->d += a.d;
		return *this;
	}
	bool operator==(Matrix a) {
		if (a.a == this->a && a.b == this->b && a.c == this->c && a.d == this->d)
			return true;
		else return false;
	}

};

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c)
		cout << "a and c are the same" << endl;
	return 0;
}