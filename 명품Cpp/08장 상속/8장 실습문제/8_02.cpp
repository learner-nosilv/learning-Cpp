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
	NamedCircle(string name = "") : Circle() { this->name = name; }
	void show() { cout << "�������� " << getRadius() << "�� " << name << endl; }
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
};

int main() {
	NamedCircle pizza[5];
	cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int i = 0; i < 5; i++) {
		int radius;
		string name;
		cout << i + 1 << ">> ";
		cin >> radius;
		cin >> name;
		pizza[i].setRadius(radius);
		pizza[i].setName(name);
	}

	int widest = 0;
	for (int i = 1; i < 5; i++) {
		if (pizza[widest].getRadius() < pizza[i].getRadius())
			widest = i;
	}
	cout << "���� ������ ū ���ڴ� " << pizza[widest].getName() << "�Դϴ�" << endl;
	return 0;
}