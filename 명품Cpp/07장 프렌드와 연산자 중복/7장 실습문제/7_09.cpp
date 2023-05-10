/* 9. 8번의 Circle 객체에 1+객체 연산이 가능하도록 연산자 구현 */

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << this->radius << " 인 원" << endl; }
	friend Circle operator+(int a, Circle circle);
};

Circle operator+ (int a, Circle circle) {
	circle.radius += a;
	return circle;
}

int main() {
	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();

	return 0;
}