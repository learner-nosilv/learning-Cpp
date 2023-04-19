#include <iostream>
using namespace std;

class Circle {
private:
	static int numOfCircles;		// static 멤버로 객체수를 체크
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; }	// 소멸시 객체 수 감소
	double getArea() { return 3.14 * radius * radius; }
	static int getNumOfCircles() { return numOfCircles; }	// static 멤버변수 값 반환
};

Circle::Circle(int r) {
	radius = r;
	numOfCircles++;					// 객체 생성시 카운트++
}

int Circle::numOfCircles = 0;		// ** 0으로 초기화 **

int main() {
	Circle* p = new Circle[10];		// Circle클래스의 객체10개를 배열로 생성 & 포인터 p
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;		// 객체 10개 생성했므로 10 출력

	delete[]p;	// 객체 10개가 들어간 배열 전부 소멸
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;		// 10개 전부 소멸됐으므로 0 출력

	Circle a;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;		// 객체 1개 생성했므로 1 출력
	
	Circle b;
	cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;		// 객체 1개 더 생성했므로 2 출력
	return 0;
}