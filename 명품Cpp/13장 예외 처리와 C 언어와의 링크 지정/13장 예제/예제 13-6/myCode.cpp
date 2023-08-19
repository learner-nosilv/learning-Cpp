/* 예제 13-6		문자열을 정수로 변환하는 함수 작성하기 
	* 정수로 변환할 수 없는 문자열은 예외처리 */
#include <iostream>
#include <string>
using namespace std;

int stringToInt(const char x[]) {
	int sum = 0;			// 문자열이 변환된 정수
	int len = strlen(x);	// 문자열 길이
	for (int i = 0; i < len; i++) {
		if (x[i] < '0' || x[i]>'9')
			throw x;
		else
			sum = (sum * 10) + (x[i] - '0');
	}
	return sum;
}

int main() {
	int n;
	const char* firstLine = "123";
	const char* secondLine = "1A3";

	try {
		n = stringToInt(firstLine);
		cout << '\"' << firstLine << "\" 은 정수 " << n << " (으)로 변환됨" << endl;
		n = stringToInt(secondLine);
		cout << '\"' << secondLine << "\" 은 정수 " << n << " (으)로 변환됨" << endl;
	}
	catch (const char* s) {
		cout << s << " 은 처리에서 예외 발생!!" << endl;
		return 0;
	}
	return 0;
}