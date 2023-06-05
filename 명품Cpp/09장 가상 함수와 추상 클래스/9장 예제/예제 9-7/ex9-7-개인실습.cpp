/* 455p.추상 클래스 구현 연습
* 추상클래스(Calculator)를 상속받은 클래스(Adder, Subtractor) 구현하기
* 추상 클래스: "구동하다" 라는 인터페이스 제공
* 파생 클래스: "구동하다" 를 덧셈/뺄셈으로 Over-riding
*/

#include <iostream>
using namespace std;

class Calculator {							// Abstract class
	void input() {
		cout << "정수 2 개를 입력하세요>> ";
		cin >> a >> b;						// 먼저 선언되어서 헷갈리지만, protected에 있는 멤버변수
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;		// pure virtual function: 정수 합
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;		// 파생 클래스의 Overriding이 요구됨
	}
};

class Adder : public Calculator {
	virtual int calc(int a, int b) { return a + b; }
};

class Subtractor : public Calculator {
	virtual int calc(int a, int b) { return a - b; }
};

int main() {
	Adder adder;
	Subtractor subtractor;

	adder.run();
	subtractor.run();
	return 0;
}