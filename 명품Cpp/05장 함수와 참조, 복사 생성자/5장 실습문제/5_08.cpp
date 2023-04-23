/* 8.
* MyIntStack 클래스 구현하기 (문제 7번 변형): size를 사용자가 설정가능한 stack의 정수저장
* 멤버변수 : 10개의 정수를 저장할 수 있는 배열, int TopOfStack
* 멤버함수 : 생성자, Push, Pop ( Top에 저장, Top을 pop )
*/

#include <iostream>
using namespace std;

class MyIntStack {
	int* p;			// stack 배열의 시작포인터
	int size;		// stack 배열의 사이즈
	int tos;		// top을 가리키는 인덱스 (top은 비어있음)
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
	bool push(int n);	// stack top에 n을 push + 정상푸시true / push실패false
	bool pop(int& n);	// stack top을 pop하여 n에 저장 + 정상팝true / pop실패false
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
	if (tos <= 0) return false;	// stack[0]도 비어있으면 더이상 pop불가
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
	MyIntStack b = a;	// 복사생성자
	b.push(30);

	int n;
	a.pop(n);
	cout << "스택 a에서 팝한 값 " << n << endl;
	b.pop(n);
	cout << "스택 b에서 팝한 값 " << n << endl;

	return 0;
}