/* 8. ���� �߻�ȭ�� Circle Ŭ������ �����ϰ�
���� ������ �����ϵ��� �����ڸ� ������ �Լ��� �ۼ��ϱ�
++a, a++ */

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << this->radius << " �� ��" << endl; }
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