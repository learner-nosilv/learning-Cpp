/* 11. 다음 프로그램과 실행결과를 보고, pos 조작자를 작성하라. */
#include <iostream>
using namespace std;

istream& pos(istream& ins) {
	cout << "위치는? ";
	return ins;
}

int main() {
	int x, y;
	cin >> pos >> x;
	cin >> pos >> y;
	cout << x << ',' << y << endl;

	return 0;
}