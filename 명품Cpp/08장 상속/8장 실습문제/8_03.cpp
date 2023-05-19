/* 3, 4�� ����Ǵ� Point Ŭ������ ��ӹ޴� ColorPoint �ۼ��ϰ� ���α׷� �ϼ��ϱ�
	2���� ���� �� �� �� 2���� ���� �� ���� ��
	ColorPoint ��� :
		������(int x, int y, string color)
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
	void show() { cout << this->color << "������ (" << getX() << ',' << getY() << ")�� ��ġ�� ���Դϴ�." << endl; }
};

int main() {
	ColorPoint cp(5, 5, "RED");
	cp.setPoint(10, 20);
	cp.setColor("BLUE");
	cp.show();

	return 0;
}