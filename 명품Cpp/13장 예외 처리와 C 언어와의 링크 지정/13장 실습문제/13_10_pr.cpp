/* 연습문제 10. 다음 printline(int count) 함수는 한 줄에 count 개의 '*'를 출력하는 함수이다. 
* 위 함수를 사용하여 화면에 출력하는 프로그램을 pr.cpp 파일로 작성하고
* print.c와 pr.cpp 파일로 구성되는 프로젝트를 생성하여 실행하라.
*/
#include <iostream>
using namespace std;

extern "C" void printline(int count);

int main() {
	for (int i = 1; i < 4; i++)
		printline(i);
	return 0;
}