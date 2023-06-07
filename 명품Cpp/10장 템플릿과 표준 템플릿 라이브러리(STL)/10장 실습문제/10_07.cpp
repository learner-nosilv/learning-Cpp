/* 7. �ڵ��� ������ �߰��ϰ�, �Ʒ��� ���� ��µǵ��� ���α׷� �����ϱ�*/
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator > (Circle a){ 				// ��ü �� > ������ �����ε� ����
		if ((this->radius) > a.getRadius()) return true;
		else return false;
	}
};

template <class T>
T bigger(T a, T b) {
	if (a > b) return a;
	else return b;
}

int main() {
	int a = 20, b = 50, c;
	c = bigger(a, b);		// bigger<int>
	cout << "20�� 50�� ū ���� " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);				// [�������߱���] ����: ��ü ���� > ������ �����Ǿ����� ����
	cout << "waffle�� pizza �� ū ���� �������� " << y.getRadius() << endl;
}