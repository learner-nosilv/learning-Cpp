/* 8. 원을 추상화한 Circle 클래스를 참고하고
다음 연산이 가능하도록 연산자를 프렌드 함수로 작성하기
++a, a++ */

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << this->radius << " 인 원" << endl; }
	friend Circle& operator++(Circle& circle);
	friend Circle operator++(Circle& circle, int i);
};

Circle& operator++(Circle& circle) {
	circle.radius++;
	return circle;
}

Circle operator++(Circle& circle, int i) {
	Circle temp = circle;
	circle.radius++;
	return temp;
}

int main() {
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();

	return 0;
}