/* 6. ���� AbstractStack�� ���� ����Ŭ�����μ� �߻�Ŭ�����̴�. �̸� ��ӹ޾� ������ Ǫ��, �� �ϴ� IntStack Ŭ������ ����� ��ʸ� ������*/
#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;	// ���ÿ� nǪ��	full�̸� false ����
	virtual bool pop(int& n) = 0;	// pop�� ���� n�� ����	empty�̸� false ���� (�����Ű�����alias)
	virtual int size() = 0;			// ���� ���ÿ� ����� ������ ���� ����
};

class IntStack :public AbstractStack {
	int* stack;
	int capacity;
	int top;		// ����ִ� ��
	int count;
public:
	IntStack(int capacity) {
		this->capacity = capacity;
		stack = new int[capacity];	// ���� �����Ҵ�
		top = count = 0;				// ����ִ� top�� index�� ����� ������ ���� 0
		cout << "�뷮�� " << capacity << "�� stack�� �����մϴ�." << endl;
	}
	~IntStack() { delete[] stack; }
	
	virtual bool push(int n) {
		if (top == capacity)
			return false;	// �� �� ���
		else {									// Push�� ������ ���
			stack[top] = n;
			top++;
			count++;
			return true;
		}
	}

	virtual bool pop(int& n) {
		if (top == 0) return false;				// �� �� ���
		else {									// Pop�� ������ ���
			top--;
			n = stack[top];
			count--;
			return true;
		}
	}

	virtual int size() { return this->count; }
	
};

int main() {
	IntStack stack(3);	// �뷮�� 3�� stack��ü
	cout << "[4ȸ PUSH]\t";
	for (int i = 0; i < 4; i++) {				// 4ȸ push
		cout << i;
		if (stack.push(i))
			cout << "Ǫ��\t";
		else
			cout << "����\t";
	}
	cout << endl;
	cout << "[4ȸ POP]\t";
	for (int i = 0; i < 4; i++) {				// 4ȸ pop
		int n;
		if (stack.pop(n))
			cout << n << "��\t";
		else 
			cout << "����\t";
	}
	cout << endl;

	return 0;
}


// ������ ����: 0Ǫ�� > 1Ǫ�� > 2Ǫ�� > 2�� > 1�� > 0�� 