/* function overloading -> default parameter�� �ϳ��� �Լ� �����*/

#include <iostream>
using namespace std;

class MyVector {
	int* mem;
	int size;
public:
	MyVector(int n, int val);
	~MyVector() { delete[] mem; }
	void showMem();
};

MyVector::MyVector(int n=100, int val=0) {
	this->size = n;
	mem = new int[size];
	for (int i = 0; i < size; i++)
		mem[i] = val;
}

// �׽�Ʈ �Լ�
void MyVector::showMem() {
	for (int i = 0; i < size; i++)
		cout << mem[i] << ' ';
	cout << endl;
}

int main() {
	MyVector a, b(5, 1);
	a.showMem();
	b.showMem();
	return 0;
}