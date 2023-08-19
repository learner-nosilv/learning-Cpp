/* 638p. system.ini 파일을 읽고 라인 번호를 다음과 같이 붙여 화면에 출력
	애매모호하게 풀었다면, 610p. 참조 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";	// 출력할 파일의 위치
	ifstream fin(file);								// 읽기목적으로 파일열기(연결)
	if (!fin) {
		cout << "IN: 파일 열기 실패" << endl;
		return 0;
	}

	string line;
	int n = 0;
	while (getline(fin, line))	// 한 라인을 읽고, fin 참조리턴: ()연산자가 fin의 오류 상태(fail, badbit) 체크하고 결과리턴
		cout << (++n) << " : " << line << endl;

	return 0;
}