/* 예제 10-7. 점을 추상화한 클래스 생성 & Stack 클래스의 자료형으로 점 클래스와 다양한 포인터를 사용해보기 */
#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) { this->x = x; this->y = y; }
	void show() { cout << '(' << this->x << ", " << this->y << ')' << endl; }
};

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
		return NULL;
	}								// 비어있지 않은 스택의 경우
	T element = data[tos];			// pop해야할 원소를 저장
	tos--;							// 스택의 top 인덱스 감소
	return element;					// pop해야할 원소 리턴
}

// 3. Using Generic Class & Function
int main() {

	// 1) 제네릭 타입이 포인터인 경우 
	MyStack<int*> ipStack;			// 원소의 타입이 int형 포인터인 스택 생성
	int* p = new int[3];			// 크기가 3인 정수형 배열 동적할당
	for (int i = 0; i < 3; i++) p[i] = i * 10;	// 원소 [10, 20, 30]으로 초기화
	ipStack.push(p);				// 위 배열을 가리키는 포인터 push

	int* q = ipStack.pop();			// 새로운 int형 포인터에 ipStack에서 pop한 원소 할당
	for (int i = 0; i < 3; i++) cout << q[i] << ' ';
	cout << endl;					// 10, 20, 30 
	delete[] q;						// 크기가 3인 정수형 배열 동적할당 해제

	// 2) 제네릭 타입이 특정 클래스인 경우

	MyStack<Point> pointStack;
	Point a(2, 3), b;				// 두 점 생성
	pointStack.push(a);				// 스택에 점 a 푸시
	b = pointStack.pop();			// 점 b에 스택 pop 원소 할당
	b.show();						// 점 b 출력 (2, 3)

	MyStack<Point*> pStack;			// 원소의 타입이 Point형 포인터인 pStack 스택 생성
	pStack.push(new Point(10, 20));	// 점 객체 동적할당
	Point* pPoint = pStack.pop();	// 스택 속 포인터를 pPoint에 할당
	pPoint->show();					// Point형 포인터가 가리키는 Point형 객체 show (10, 20)
	delete pPoint;					// 동적할당 해제

	MyStack<string> stringStack;	// 원소의 타입이 string 인 스택 생성
	string s = "c++";
	stringStack.push(s);				// 변수를 푸시할 수 있음
	stringStack.push("java");			// 상수를 푸시할 수 있음
	cout << stringStack.pop() << ' ';	// java
	cout << stringStack.pop() << endl;	// c++

	return 0;
}