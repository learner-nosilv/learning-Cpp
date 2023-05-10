/* 5. Color Ŭ������ 3��� RGB�� �ϳ��� ���� ��Ÿ���� Ŭ����:4�� �ǽ�����1�� solution����
* +�� ���� ���ϰ� ==�� ���� ���ϰ��� �Ѵ�.
* main()�� �������� ���� ���α׷� �ϼ��ϱ�
* (1) Ŭ���� ��� �Լ��� �����ϱ�
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
	Color operator+ (Color a) {
		a.red += this->red;
		a.green += this->green;
		a.blue += this->blue;
		return a;
	}
	bool operator== (Color a) {
		if (a.red == this->red
			&& a.green == this->green
			&& a.blue == this->blue)
			return true;
		else return false;
	}
};

int main() {
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia) cout << "����� ����";
	else cout << "����� �ƴ�";
}