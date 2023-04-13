/* 10.
* 다수의 클래스를 선언하고 활용
* (1) SKIP
* (2) 선언부와 구현부를 헤더와 cpp파일로 분리하기
* 클래스명: Add, Sub, Mul, Div
* 공통 멤버변수: int a, b: operand
* 공통 멤버함수: void setValue(int x, int y): 매개변수xy -> 멤버변수ab
*				int calculate(): 결과값 리턴
* 
* main: 무한루프
*/

#include <iostream>
#include "3_10_Calculator.h"
using namespace std;

int main() {
	int x, y;
	char oper;

	while (1) {
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> x >> y >> oper;
		switch (oper) {
			case '+':
				Add a;
				a.setValue(x, y);
				cout << a.calculate() << endl;
				break;
			case '-':
				Sub b;
				b.setValue(x, y);
				cout << b.calculate() << endl;
				break;
			case '*':
				Mul c;
				c.setValue(x, y);
				cout << c.calculate() << endl;
				break;
			case '/':
				Div d;
				d.setValue(x, y);
				cout << d.calculate() << endl;
				break;
		}
	}
	return 0;
}