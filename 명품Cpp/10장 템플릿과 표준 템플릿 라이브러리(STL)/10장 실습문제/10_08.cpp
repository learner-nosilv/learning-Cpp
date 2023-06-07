/* 8. 문제 7을 푸는 다른 방법
	비교Comparable에 관한 Abstract class를 구현하기
	해당 클래스를 상속받은 Circle클래스 작성하기 */
#include <iostream>
using namespace std;

class Comparable {
public:
	virtual bool operator > (Comparable& op2) = 0;	// Pure Virtual Function
	virtual bool operator < (Comparable& op2) = 0;	// Pure Virtual Function
	virtual bool operator == (Comparable& op2) = 0;	// Pure Virtual Function
};

class Circle {
	int radius;
public:
	Circle(int radius = 1) { this->radius = radius; }
	int getRadius() { return radius; }
	virtual bool operator > (Comparable& op2) {
		if ((this->radius) > op2.getRadius()) return true;
		else return false;
	}
	virtual bool operator < (Comparable& op2) {
		if ((this->radius) < op2.getRadius()) return true;
		else return false;
	}
	virtual bool operator == (Comparable& op2) {
		if ((this->radius) == op2.getRadius()) return true;
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