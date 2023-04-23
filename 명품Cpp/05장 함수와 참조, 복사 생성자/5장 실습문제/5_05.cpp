/* 5.
* ������ ����ó���ϸ� ������� ������� �ʴ´�.
* �Լ�����: void increaseBy(Circle a, Circle b);
* �Լ�ȣ��: increaseBy(x, y); 
* Circle x��ü �� ���ڰ� call by value�� ȣ��Ǿ� �Ű����� a��ü�� ���� ���� ����� �� ���̴�.
*	increaseBy �Լ� ������ x�� �ƴ� a ��ü�� �����Ǿ��ٰ� �Լ������ �Բ� ��������Ƿ�
*	x��ü ��������� �����̶�� ������ ������� �ʴ´�.
*/

#include <iostream>
using namespace std;

class Circle {								// swallow copy ����
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "�������� " << radius << "�� ��" << endl; }
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