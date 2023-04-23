/* 7.
* MyIntStack Ŭ���� �����ϱ� : 10���� ��������
* ������� : 10���� ������ ������ �� �ִ� �迭, int TopOfStack
* ����Լ� : ������, Push, Pop ( Top�� ����, Top�� pop )
*/

#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];		// stack
	int tos;		// top�� ����Ű�� �ε���
public:
	MyIntStack();
	bool push(int n);	// stack top�� n�� push + ����Ǫ��true / push����false
	bool pop(int& n);	// stack top�� pop�Ͽ� n�� ���� + ������true / pop����false
};

MyIntStack::MyIntStack() {
	tos = -1;
}

bool MyIntStack::push(int n) {
	if (tos >= 9) return false;
	else {
		tos++;
		p[tos] = n;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	if (tos < 0) return false;
	else {
		n = p[tos];
		tos--;
		return true;
	}
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';							// push(i)�� �����ϸ�, ����ϱ�
		else cout << endl << i + 1 << " ��° stack full" << endl;	// push(i)�� �����ϸ�, i+1 ��°
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
	return 0;
}

// [BookSolution]���� ������: �ַ���� stack�� top�� �ڸ��� ����ִ�.