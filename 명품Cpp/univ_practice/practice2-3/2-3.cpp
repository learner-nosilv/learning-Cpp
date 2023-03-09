/* 2023.03.09 객체지향프로그래밍 수업 - B111064 김혜민
	교재: 02. C++ 프로그래밍의 기본
	2.3 키 입력받기 (65p~)
		2-3 CIN과 >>로 키 입력받기 실습

*/
#include <iostream>
using namespace std;

int main() {
	cout << "너비를 입력하세요>>";

	int width;
	cin >> width;

	cout << "높이를 입력하세요>>";

	int height;
	cin >> height;

	int area = width * height;

	cout << "면적은" << area << "\n";
	return 0;
}