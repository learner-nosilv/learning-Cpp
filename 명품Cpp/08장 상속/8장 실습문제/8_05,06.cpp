/* 5, 6에 적용되는 BaseArray 클래스를 상속받는 MyQueue, MyStack 클래스를 작성하고 프로그램 완성하기
	배열 ⊃ 큐, 스텍
	MyQueue 멤버 :
		생성자(int size) : 배열(size) {}
		void enqueue(int n) : 큐에 삽입
		int capacity() : 큐 용량
		int length() : 큐 실제 사용량
		int dequeue() : 큐에서 제거 & 출력
	MyStack 멤버 :
		생성자(int size) : 배열(size) {}
		void push(int n) : 스텍에 삽입
		int capacity() : 스텍 용량
		int length() : 스텍 실제 사용량
		int pop() : 스텍에서 제거 & 출력
*/
#include <iostream>
#include <string>
using namespace std;

class BaseArray {
private:
	int capacity;	// 배열 크기
	int* mem;		// 배열 포인터
protected:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }	// 특정 index에 값 할당
	int get(int index) { return mem[index]; }			// 특정 index의 값 리턴
	int getCapacity() { return capacity; }				// 배열크기 리턴
};

class MyQueue : virtual public BaseArray {
	int qlength;	// 실제 사용량 (총 원소 수)			// length로 하고싶지만 이름이 너무 겹치니 에러남...
	int front;		// Blanked HEAD : POP장소 옆	,빈칸	
	int rear;		// Blanked TAIL : PUSH장소	,빈칸	
public:
	MyQueue(int size = 100) : BaseArray(size) {			// 생성자
		this->qlength = this->rear = 0;
		this->front = -1;
	}
	int capacity() { return this->getCapacity(); }		// 큐 최대 용량
	int length() { return this->qlength; }				// 큐 실제 사용량
	void enqueue(int n) {								// 큐 삽입
		int capacity = getCapacity();
		if (this->qlength >= capacity) {
			cout << "!!FULLED!!" << endl;
			return;
		}
		put(this->rear, n);
		rear++;		// 끝index(Empty) 1증가
		if (this->rear >= capacity) rear -= capacity;
		qlength++;	// 실제 사용량 1증가
	}
	int dequeue() {										// 큐에서 제거하여 출력
		int capacity = getCapacity();
		if (qlength <= 0) {
			cout << "!!EMPTY!!" << endl;
			return -1;
		}
		qlength--;
		front++;	// 앞index보다 한 칸 Empty
		if (front >= capacity) front -= capacity;
		return (get(front));
	}
};

class MyStack :virtual public BaseArray {
	int slength;		// 실제 사용량 (총 원소 수)		// length로 하고싶지만 이름이 너무 겹치니 에러남...
	int rear;		// PUSH / POP장소 (비어있음)
public:
	MyStack(int size = 100) : BaseArray(size) { this->slength = this->rear = 0; }
	int capacity() { return this->getCapacity(); }		// 스텍 최대 용량
	int length() { return this->slength; }				// 스텍 실제 사용량
	void push(int n) {									// 스텍 삽입
		int capacity = getCapacity();
		if (rear >= capacity) {
			cout << "!!FULLED!!" << endl;
			return;
		}
		put(rear, n);
		rear++;		// 끝index(Empty) 1증가
		if (rear >= capacity) rear -= capacity;
		slength++;	// 실제 사용량 1증가
	}
	int pop() {										// 큐에서 제거하여 출력
		if (rear <= 0) {
			cout << "!!EMPTY!!" << endl;
			return -1;
		}
		rear--;	// 앞index보다 한 칸 Empty
		slength--;
		return get(rear);
	}
};

int main() {
	// 5.
	MyQueue mQ(100);
	int n;
	std::cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n);	// 큐에 삽입
	}
	cout << "큐의 용량:" << mQ.capacity() << ", 큐의 크기:" << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;

	cout << endl;

	// 6.
	MyStack mStack(100);
	int m;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> m;
		mStack.push(m);	// 스택에 푸시
	}
	cout << "스택 용량:" << mStack.capacity() << ", 스택의 크기:" << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' ';
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;


	return 0;
}