/* 3, 4에 적용되는 Point 클래스를 상속받는 ColorPoint 작성하고 프로그램 완성하기
	2차원 상의 한 점 ⊃ 2차원 상의 한 색깔 점
	ColorPoint 멤버 :
		생성자(int x, int y, string color)
		setPoint(int x, int y)
		setColor(string color)
		show()
*/
#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x, int y, string color) : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { move(x, y); }
	void setColor(string color) { this->color = color; }
	void show() { cout << this->color << "색으로 (" << getX() << ',' << getY() << ")에 위치한 점입니다." << endl; }
};

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();

	return 0;
}