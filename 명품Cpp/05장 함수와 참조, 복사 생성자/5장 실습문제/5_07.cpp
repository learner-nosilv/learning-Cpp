/* 7.
* MyIntStack 클래스 구현하기 : 10개의 정수저장
* 멤버변수 : 10개의 정수를 저장할 수 있는 배열, int TopOfStack
* 멤버함수 : 생성자, Push, Pop ( Top에 저장, Top을 pop )
*/

#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];		// stack
	int tos;		// top을 가리키는 인덱스
public:
	MyIntStack();
	bool push(int n);	// stack top에 n을 push + 정상푸시true / push실패false
	bool pop(int& n);	// stack top을 pop하여 n에 저장 + 정상팝true / pop실패false
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
		if (a.push(i)) cout << i << ' ';							// push(i)를 성공하면, 출력하기
		else cout << endl << i + 1 << " 번째 stack full" << endl;	// push(i)를 실패하면, i+1 번째
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
	return 0;
}

// [BookSolution]과의 차이점: 솔루션은 stack의 top에 자리가 비어있다.