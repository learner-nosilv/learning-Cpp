/* 1, 2. Circle 클래스를 상속받는 NamedCircle를 작성하기
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
	void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }
	void setName(string name) { this->name = name; }
	string getName() { return this->name; }
};

int main() {
	NamedCircle pizza[5];
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
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
	cout << "가장 면적이 큰 피자는 " << pizza[widest].getName() << "입니다" << endl;
	return 0;
}