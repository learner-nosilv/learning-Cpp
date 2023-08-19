/* 연습문제 5. 예외를 고려한 구구단 출력프로그램 */
#include <iostream>
using namespace std;

int main() {
	int n;
	while (true) {
		try {
			cout << "양수 입력>> ";
			cin >> n;
			if (cin.fail()) {			// 문자입력 -> 예외
				cin.clear();
				cin.ignore(99, '\n');
				throw 1;
			}
			if (n < 1 || n>9) throw 2;	// 0~9를 벗어나는 입력 -> 예외
			for (int i = 1; i <= 9; i++)
				cout << n << 'x' << i << '=' << n * i << ' ';
			cout << endl;
		}
		catch (int n) {
			if (n == 1) {
				cout << "입력 오류가 발생하여 더 이상 입력되지 않습니다. 프로그램을 종료합니다" << endl;
				return 0;
			}
			else if (n == 2)
				cout << "잘못된 입력입니다. 1~9 사이의 정수만 입력하세요" << endl;
		}
	}
	return 0;
}