/* 7. (2) 
* main()�Լ��� �ְܼ���� ���� 2���� ����� �߻�ȭ �� Matrix Ŭ������ �ۼ��ϱ�
* <<, >> ������ �Լ��� (1) ����Լ��� (2) �������Լ��� �����϶�.
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
	a >> x;	// a�� �� ���Ҹ� �迭 x�� ����
	b << y; // �迭 y�� ���Ұ��� b�� �� ���ҿ� ����

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();

	return 0;
}