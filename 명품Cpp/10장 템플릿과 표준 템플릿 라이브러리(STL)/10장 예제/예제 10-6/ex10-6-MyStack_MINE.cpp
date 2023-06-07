/* 예제 10-6. Stack 클래스를 Template를 사용하여 Generic하게 작성하기 */
#include <iostream>
using namespace std;

// 1. Generic Class Declaration
template <class T>					// 타입을 T로 설정한 템플릿
class MyStack {						//	: 클래스의 선언부
	int tos;						// Top of Stack
	T data[100];					// T타입의 배열, 크기는 100
public:
	MyStack();
	void push(T element);			// T type의 원소를 data[]에 삽입
	T pop();						// T type의 데이터를 data[]에서 삭제하고 리턴
};

// 2. Generic function Implementation
template <class T>					// 타입을 T로 설정한 템플릿
MyStack<T>::MyStack() {				// 템플릿으로 설정된 MyStack클래스의 :: MyStack() 함수 구현
	tos = -1;						// 비어있는 스택
}

template <class T>					// 타입을 T로 설정한 템플릿
void MyStack<T>::push(T element) {	// 템플릿으로 설정된 MyStack클래스의 :: push() 함수 구현
	if (tos == 99) {				// 가득차있는 스택의 경우
		cout << "stack full";
		return;
	}								// 가득차있지 않은 스택의 경우
	tos++;							// 스택의 top 인덱스 증가
	data[tos] = element;			// 스택의 top에 원소 할당
}

template <class T>					// 타입을 T로 설정한 텦믈릿
T MyStack<T>::pop() {				// 템플릿으로 설정된 MyStack클래스의 :: pop() 함수 구현
	if (tos == -1) {				// 비어있는 스택의 경우
		cout << "stack Empty";
		return -1;
	}								// 비어있지 않은 스택의 경우
	T element = data[tos];			// pop해야할 원소를 저장
	tos--;							// 스택의 top 인덱스 감소
	return element;					// pop해야할 원소 리턴
}

// 3. Using Generic Class & Function
int main() {
	MyStack<int> iStack;			// T가 int로 구체화된 MyStack 클래스의 객체 생성
	iStack.push(1);
	cout << iStack.pop() << endl;
	cout << iStack.pop() << endl;

	MyStack<double> dStack;			// T가 double로 구체화된 MyStack 클래스의 객체 생성
	dStack.push(1.1);
	cout << dStack.pop() << endl;

	MyStack<char>* pCStack = new MyStack<char>();			// T가 char로 구체화된 MyStack 클래스의 포인터에 객체 동적할당
	pCStack->push('a');
	cout << pCStack->pop() << endl;
	return 0;
}