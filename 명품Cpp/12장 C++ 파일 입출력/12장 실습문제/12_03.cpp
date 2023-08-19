/* 파일을 읽고 영문 글자를 모두 대문자로 출력하라. */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";	// 출력할 파일의 위치
	ifstream fin(file);								// 읽기목적으로 파일열기(연결)
	if (!fin) {
		cout << "IN: 파일 열기 실패" << endl;
		return 0;
	}

	char n;
	while ((n = fin.get()) != EOF) {	// 한 문자 읽기
		if (n >= 'a' && n <= 'z')		// 소문자 -> 대문자
			cout << (char)(n - 'a' + 'A');
		else
			cout << n;
	}

	return 0;
}