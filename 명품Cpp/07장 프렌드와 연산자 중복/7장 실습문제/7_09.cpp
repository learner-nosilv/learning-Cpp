/* 9. 8���� Circle ��ü�� 1+��ü ������ �����ϵ��� ������ ���� */

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << this->radius << " �� ��" << endl; }
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