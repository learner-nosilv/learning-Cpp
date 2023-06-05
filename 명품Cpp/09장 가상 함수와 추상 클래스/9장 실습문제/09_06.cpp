/* 6. 다음 AbstractStack는 정수 스택클래스로서 추상클래스이다. 이를 상속받아 정수를 푸시, 팝 하는 IntStack 클래스를 만들고 사례를 보여라*/
#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;	// 스택에 n푸시	full이면 false 리턴
	virtual bool pop(int& n) = 0;	// pop한 정수 n에 저장	empty이면 false 리턴 (참조매개변수alias)
	virtual int size() = 0;			// 현재 스택에 저장된 정수의 갯수 리턴
};

class IntStack :public AbstractStack {
	int* stack;
	int capacity;
	int top;		// 비어있는 곳
	int count;
public:
	IntStack(int capacity) {
		this->capacity = capacity;
		stack = new int[capacity];	// 스텍 동적할당
		top = count = 0;				// 비어있는 top의 index와 저장된 정수의 갯수 0
		cout << "용량이 " << capacity << "인 stack을 생성합니다." << endl;
	}
	~IntStack() { delete[] stack; }
	
	virtual bool push(int n) {
		if (top == capacity)
			return false;	// 다 찬 경우
		else {									// Push가 가능한 경우
			stack[top] = n;
			top++;
			count++;
			return true;
		}
	}

	virtual bool pop(int& n) {
		if (top == 0) return false;				// 다 빈 경우
		else {									// Pop이 가능한 경우
			top--;
			n = stack[top];
			count--;
			return true;
		}
	}

	virtual int size() { return this->count; }
	
};

int main() {
	IntStack stack(3);	// 용량이 3인 stack객체
	cout << "[4회 PUSH]\t";
	for (int i = 0; i < 4; i++) {				// 4회 push
		cout << i;
		if (stack.push(i))
			cout << "푸시\t";
		else
			cout << "실패\t";
	}
	cout << endl;
	cout << "[4회 POP]\t";
	for (int i = 0; i < 4; i++) {				// 4회 pop
		int n;
		if (stack.pop(n))
			cout << n << "팝\t";
		else 
			cout << "실패\t";
	}
	cout << endl;

	return 0;
}


// 스텍의 순서: 0푸시 > 1푸시 > 2푸시 > 2팝 > 1팝 > 0팝 