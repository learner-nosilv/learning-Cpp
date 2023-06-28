#include <iostream>
using namespace std;

class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend istream& operator >> (istream& ins, Point& a);
	friend ostream& operator << (ostream& stream, Point a);
};

istream& operator >> (istream& ins, Point& a) {	// cin >>
	cout << "x >> ";
	ins >> a.x;			// 참조매개변수이므로, 실제 값 변경
	cout << "y >> ";
	ins >> a.y;			// 참조매개변수이므로, 실제 값 변경
	return ins;			// 참조리턴
}

ostream& operator << (ostream& stream, Point a) {
	stream << '(' << a.x << ',' << a.y << ')';
	return stream;
}

int main() {
	Point p;
	cin >> p;
	cout << p;
	return 0;
}