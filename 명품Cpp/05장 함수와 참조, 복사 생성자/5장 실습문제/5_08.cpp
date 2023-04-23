/* 8.
* MyIntStack Ŭ���� �����ϱ� (���� 7�� ����): size�� ����ڰ� ���������� stack�� ��������
* ������� : 10���� ������ ������ �� �ִ� �迭, int TopOfStack
* ����Լ� : ������, Push, Pop ( Top�� ����, Top�� pop )
*/

#include <iostream>
using namespace std;

class MyIntStack {
	int* p;			// stack �迭�� ����������
	int size;		// stack �迭�� ������
	int tos;		// top�� ����Ű�� �ε��� (top�� �������)
public:
	MyIntStack(int size = 10) {
		this->p = new int[size];
		this->size = size;
		this->tos = 0;
	}
	MyIntStack(const MyIntStack& stack) {
		this->size = stack.size;
		this->p = new int[size];
		this->tos = stack.tos;
	}
	~MyIntStack() { delete[] p; }
	bool push(int n);	// stack top�� n�� push + ����Ǫ��true / push����false
	bool pop(int& n);	// stack top�� pop�Ͽ� n�� ���� + ������true / pop����false
};

bool MyIntStack::push(int n) {
	if (tos > size) return false;
	else {
		p[tos] = n;
		tos++;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	if (tos <= 0) return false;	// stack[0]�� ��������� ���̻� pop�Ұ�
	else {
		tos--;
		n = p[tos];
		return true;
	}
}

int main() {
	MyIntStack a(10);
	a.push(10);
	a.push(20);
	MyIntStack b = a;	// ���������
	b.push(30);

	int n;
	a.pop(n);
	cout << "���� a���� ���� �� " << n << endl;
	b.pop(n);
	cout << "���� b���� ���� �� " << n << endl;

	return 0;
}