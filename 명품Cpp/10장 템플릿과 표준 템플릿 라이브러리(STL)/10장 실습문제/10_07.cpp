/* 7. 코드의 오류를 발견하고, 아래와 같이 출력되도록 프로그램 수정하기*/
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	bool operator > (Circle a){ 				// 객체 간 > 연산자 오버로딩 구현
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
	cout << "20과 50중 큰 값은 " << c << endl;
	Circle waffle(10), pizza(20), y;
	y = bigger(waffle, pizza);				// [오류유발구간] 이유: 객체 간의 > 연산은 지정되어있지 않음
	cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}