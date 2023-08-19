/* p.610	예제12-05	istream의 getline()을 이용하여 텍스트 파일을 읽고 화면 출력 */
#include <iostream>	// C++ 표준 입출력 라이브러리
#include <fstream>	// C++ 표준 파일 입출력 라이브러리
using namespace std;

int main() {
	const char* firstFile = "c:\\windows\\system.ini";
	ifstream fileIn(firstFile);		// 해당 파일을 열어서 읽어들이는 파일 읽기 스트림 객체 선언
	if (!fileIn) {					// 파일 열기가 실패한 경우
		cout << firstFile << " 열기 실패" << endl;
		return 0;
	}

	char buf[81];						// 80자 + '/0'
	while (fileIn.getline(buf, 81)) {	// 루프: 한 줄씩 읽기 (끝난 경우, 루프탈출)
		cout << buf << endl;			// 읽은 한 줄 출력 + 개행(LF, CR)
	}

	fileIn.close();						// fileIn과 연결된 파일 닫기

	return 0;
}