/* 예제 13-5		지수 승 계산을 예외처리코드로 재작성 */
#include <iostream>
using namespace std;

int getExp(int base, int exp) {
	if (base < 0 || exp < 0) {	// 오류 검사
		throw "음수 사용 불가";	// 예외 발생
	}
	else {
		int value = 1;
		for (int i = 0; i < exp; i++)
			value *= exp;
		return value;			// 계산 성공
	}
}

int main() {
	int v = 0;
	try {
		v = getExp(2, 3);								// 예외 X
		cout << "2의 3승은 " << v << "입니다." << endl;
		v = getExp(2, -3);								// 예외 O -> throw "음수 사용 불가"
		cout << "2의 3승은 " << v << "입니다." << endl;	// catch문으로 가서
	}
	catch (const char* s) {
		cout << "예외 발생 !! " << s << endl;
	}
	return 0;
}