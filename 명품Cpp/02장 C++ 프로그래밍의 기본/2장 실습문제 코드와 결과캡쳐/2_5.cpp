#include <iostream>
using namespace std;

// main: 100개 미만의 문자열을 입력받은 후 x의 갯수를 세어 출력하는 함수
int main() {
	// 1. 최대 99개의 문자 입력받기
	char str[100];
	cout << "문자들을 입력하라(100개 미만).\n";
	cin.getline(str, 100, '\n');	// 입력스트림객체의 메소드getline을 사용

	// 2. 순차적으로 검색하며 x 갯수 카운트
	int count = 0;
	for (int i = 0; i < 99; i++) {	// 검색범위는 str[0]~str[98]이다. str[99]는 반드시 '\0' 이므로
		if (str[i] == 'x') count++;	// str[0~98]이 문자x일 때마다, count가 1씩 증가
	}

	// 3. x 갯수 출력
	cout << "x의 개수는 " << count << endl;

	return 0;
}