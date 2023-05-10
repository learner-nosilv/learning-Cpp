/* 5. Color 클래스는 3요소 RGB로 하나의 색을 나타내는 클래스:4장 실습문제1번 solution참고
* +로 색을 더하고 ==로 색을 비교하고자 한다.
* main()과 실행결과를 보고 프로그램 완성하기
* (2) 클래스 프렌드 함수로 구현하기
*/

#include <iostream>
using namespace std;

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
	friend Color operator+ (Color a, Color b);
	friend bool operator== (Color a, Color b);
};

Color operator+ (Color a, Color b) {
	a.red += b.red;
	a.green += b.green;
	a.blue += b.blue;
	return a;
}
bool operator== (Color a, Color b) {
	if (a.red == b.red && a.green == b.green && a.blue == b.blue)
		return true;
	else return false;
}

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) cout << "보라색 맞음";
	else cout << "보라색 아님";
}