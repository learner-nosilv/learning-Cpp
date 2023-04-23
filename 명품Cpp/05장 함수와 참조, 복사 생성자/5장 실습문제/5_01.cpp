/* 1.
두 개의 Circle 객체를 교환하는 swap() 함수를 call by reference 로 작성
*/

#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) {
		this->radius = radius; }
	int getRadius() { return radius; }
};

void swap(Circle& a, Circle& b) {
	Circle temp = a;
	a = b;				// Swallow Copy
	b = temp;			// Swallow Copy
}

int main() {
	Circle ball;
	Circle orange(100);
	cout << "ball: " << ball.getRadius() << "  orange: " << orange.getRadius() << endl;
	swap(ball, orange);
	cout << "ball: " << ball.getRadius() << "  orange: " << orange.getRadius() << endl;
	return 0;
}