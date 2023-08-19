/* 연습문제3. 0~9사이의 정수를 키보드에서 입력받아 리턴하는 get() 함수 
	예외: 0-9사이의 값을 입력하지 않은 경우
	main()은 while(true)
*/
#include <iostream>
using namespace std;

int get() throw(const char*) {
	int a;
	cout << "0~9 사이의 정수 입력 >> ";
	cin >> a;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(99, '\n');
		throw "input(char) fault";
	}
	if (a < 0 || a > 9) throw "input(out of range) fault";
	return a;
}

int main() {
	int a, b;
	while (true) {
		try {
			a = get();
			b = get();
			cout << a << 'x' << b << '=' << a * b << endl;
		}
		catch (const char* msg) {
			cout << msg << ", 계산할 수 없음" << endl;
		}
	}
	return 0;
}