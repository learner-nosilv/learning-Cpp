/* 5.
* 문제의 예시처럼하면 목적대로 실행되지 않는다.
* 함수원형: void increaseBy(Circle a, Circle b);
* 함수호출: increaseBy(x, y); 
* Circle x객체 즉 인자가 call by value로 호출되어 매개변수 a객체에 그저 값이 복사된 것 뿐이다.
*	increaseBy 함수 내에선 x가 아닌 a 객체가 변형되었다가 함수종료와 함께 사라졌으므로
*	x객체 멤버변수의 변형이라는 목적이 실행되지 않는다.
*/

#include <iostream>
using namespace std;

class Circle {								// swallow copy 가능
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};

void increaseBy(Circle& a, Circle b) {		// call by reference
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();

	return 0;
}