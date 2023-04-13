#include <iostream>
using namespace std;

class Rectangle {
	int width, height;
public:
	Rectangle();
	Rectangle(int length);
	Rectangle(int a, int b);
	~Rectangle();
	bool isSquare() {
		return width == height;
	}
};

Rectangle::Rectangle() : Rectangle(1) {}
Rectangle::Rectangle(int l) : Rectangle(l , l) {}
Rectangle::Rectangle(int w, int h) : width(w), height(h) {}
Rectangle::~Rectangle() {
	cout << "�Ҹ�!" << endl;
}

int main(void){
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	if (rect1.isSquare()) cout << "rect1�� ���簢���̴�." << endl;
	if (rect2.isSquare()) cout << "rect2�� ���簢���̴�." << endl;
	if (rect3.isSquare()) cout << "rect3�� ���簢���̴�." << endl;

		return 0;
}
/*
���蹮�����
*/