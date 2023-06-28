/* 8. Circle 클래스 실행결과를 참조하여 << >> 연산자를 작성하고, 클래스를 수정하여 프로그램완성하기
* cin>>Circle객체로 멤버변수할당까지 완료, cout <<Circle객체로 객체정보출력
*	class Circle;
	istream& operator >> (istream& ins, Circle& a);
	ostream& operator << (ostream& outs, Circle a);
*/
#include <iostream>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	Circle(int radius = 1, string name = "") {
		this->radius = radius;
		this->name = name;
	}
	friend istream& operator >> (istream& ins, Circle& a);
	friend ostream& operator << (ostream& outs, Circle a);
};

istream& operator >> (istream& ins, Circle& a) {
	string name;
	int radius;
	while (true) {
		cout << "반지름 >> ";
		cin >> radius;
		if (cin.fail()) {
			cout << "'숫자'를 입력하세요.\n";
			cin.clear();
			cin.ignore(99, '\n');
		}
		else if (radius <= 0)
			cout << "반지름 값으로 음수는 적합하지 않습니다.\n";
		else break;
	}
	a.radius = radius;

	cout << "이름>> ";
	cin >> a.name;

	return ins;
}

ostream& operator << (ostream& outs, Circle a) {
	outs << "(반지름이" << a.radius << "인 " << a.name << ')';
	return outs;
}

int main() {
	Circle d, w;
	cin >> d >> w;			// 키보드 입력을 받아 객체 d와 w를 완성
	cout << d << w << endl; // 객체 d, w 출력
	return 0;
}