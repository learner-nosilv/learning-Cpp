/* 5, 6�� ����Ǵ� BaseArray Ŭ������ ��ӹ޴� MyQueue, MyStack Ŭ������ �ۼ��ϰ� ���α׷� �ϼ��ϱ�
	�迭 �� ť, ����
	MyQueue ��� :
		������(int size) : �迭(size) {}
		void enqueue(int n) : ť�� ����
		int capacity() : ť �뷮
		int length() : ť ���� ��뷮
		int dequeue() : ť���� ���� & ���
	MyStack ��� :
		������(int size) : �迭(size) {}
		void push(int n) : ���ؿ� ����
		int capacity() : ���� �뷮
		int length() : ���� ���� ��뷮
		int pop() : ���ؿ��� ���� & ���
*/
#include <iostream>
#include <string>
using namespace std;

class BaseArray {
private:
	int capacity;	// �迭 ũ��
	int* mem;		// �迭 ������
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }	// Ư�� index�� �� �Ҵ�
	int get(int index) { return mem[index]; }			// Ư�� index�� �� ����
	int getCapacity() { return capacity; }				// �迭ũ�� ����
};

class MyQueue : virtual public BaseArray {
	int qlength;	// ���� ��뷮 (�� ���� ��)			// length�� �ϰ������ �̸��� �ʹ� ��ġ�� ������...
	int front;		// Blanked HEAD : POP��� ��	,��ĭ	
	int rear;		// Blanked TAIL : PUSH���	,��ĭ	
public:
	MyQueue(int size = 100) : BaseArray(size) {			// ������
		this->qlength = this->rear = 0;
		this->front = -1;
	}
	int capacity() { return this->getCapacity(); }		// ť �ִ� �뷮
	int length() { return this->qlength; }				// ť ���� ��뷮
	void enqueue(int n) {								// ť ����
		int capacity = getCapacity();
		if (this->qlength >= capacity) {
			cout << "!!FULLED!!" << endl;
			return;
		}
		put(this->rear, n);
		rear++;		// ��index(Empty) 1����
		if (this->rear >= capacity) rear -= capacity;
		qlength++;	// ���� ��뷮 1����
	}
	int dequeue() {										// ť���� �����Ͽ� ���
		int capacity = getCapacity();
		if (qlength <= 0) {
			cout << "!!EMPTY!!" << endl;
			return -1;
		}
		qlength--;
		front++;	// ��index���� �� ĭ Empty
		if (front >= capacity) front -= capacity;
		return (get(front));
	}
};

class MyStack :virtual public BaseArray {
	int slength;		// ���� ��뷮 (�� ���� ��)		// length�� �ϰ������ �̸��� �ʹ� ��ġ�� ������...
	int rear;		// PUSH / POP��� (�������)
public:
	MyStack(int size = 100) : BaseArray(size) { this->slength = this->rear = 0; }
	int capacity() { return this->getCapacity(); }		// ���� �ִ� �뷮
	int length() { return this->slength; }				// ���� ���� ��뷮
	void push(int n) {									// ���� ����
		int capacity = getCapacity();
		if (rear >= capacity) {
			cout << "!!FULLED!!" << endl;
			return;
		}
		put(rear, n);
		rear++;		// ��index(Empty) 1����
		if (rear >= capacity) rear -= capacity;
		slength++;	// ���� ��뷮 1����
	}
	int pop() {										// ť���� �����Ͽ� ���
		if (rear <= 0) {
			cout << "!!EMPTY!!" << endl;
			return -1;
		}
		rear--;	// ��index���� �� ĭ Empty
		slength--;
		return get(rear);
	}
};

int main() {
	// 5.
	MyQueue mQ(100);
	int n;
	std::cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);	// ť�� ����
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;

	cout << endl;

	// 6.
	MyStack mStack(100);
	int m;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> m;
		mStack.push(m);	// ���ÿ� Ǫ��
	}
	cout << "���� �뷮:" << mStack.capacity() << ", ������ ũ��:" << mStack.length() << endl;
	cout << "������ ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;


	return 0;
}