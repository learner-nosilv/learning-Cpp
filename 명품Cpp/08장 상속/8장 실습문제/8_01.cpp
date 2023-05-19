/* 1, 2. Circle Ŭ������ ��ӹ޴� NamedCircle�� �ۼ��ϱ�
*/
#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return this->radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius, string name="") : Circle(radius) { this->name = name; }
	void show() { cout << "�������� " << getRadius() << "�� " << name << endl; }
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
};

int main() {
	NamedCircle waffle(3, "waffle");
	waffle.show();
	return 0;
}