/* 7. Shape 클래스를 상속받아 타원, 사각형, 삼각형을 표현하는 클래스 작성하기
*/

#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
	string name;
	int width, height;
public:
	Shape(string n = "", int w = 0, int h = 0) { name = n; width = w; height = h; }
	virtual double getArea() { return 0; }	// dummy
	string getName() { return name; }
};

class Oval :public Shape {
public:
	Oval(string n, int w, int h) :Shape(n, w, h) {}
	virtual double getArea() { return 3.14 * this->width * this->height * 0.25; }	// 장축*단축*파이
};

class Rect :public Shape {
public:
	Rect(string n, int w, int h) :Shape(n, w, h) {}
	virtual double getArea() { return this->width * this->height; }
};

class Triangular :public Shape {
public:
	Triangular(string n, int w, int h) :Shape(n, w, h) {}
	virtual double getArea() { return 0.5 * this->width * this->height; }
};

int main() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20);		// 교재오류?
	p[1] = new Rect("찰떡", 30, 40);
	p[2] = new Triangular("토스트", 30, 40);

	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;

	for (int i = 0; i < 3; i++)delete p[i];

	return 0;
}