/* P.609	예제 12-4	텍스트 파일 연결 */
#include <iostream>		// 표준 입출력 라이브러리
#include <fstream>		// 표준 파일 입출력 라이브러리
using namespace std;

int main() {
	const char* firstFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-1\\student.txt";
	const char* secondFile = "c:\\windows\\system.ini";

	fstream fout(firstFile, ios::out | ios::app);	// 객체선언: 파일열기, 파일쓰기모드, 항상 뒤에 덧붙임모드
	if (!fout) {									// 파일열기 실패유무 검사
		cout << firstFile << " 열기 오류";
		return 0;
	}

	fstream fin(secondFile, ios::in);				// 객체선언: 파일열기, 파일읽기모드
	if (!fin) {										// 파일열기 실패유무 검사
		cout << secondFile << " 열기오류";
		return 0;
	}
	fout.put('\n');		// Line Feed
	fout.put('\r');		// Carrage Return

	int c;											// 변수: 현재 읽은 문자 할당
	while ((c = fin.get()) != EOF) {				// 읽은 문자가 있는 경우 반복 (문서의 끝이라 읽은 문자가 없는 경우 루프탈출)
		fout.put(c);								// 파일쓰기스트림객체를 통해 파일에 문자쓰기 
	}

	fout.close();									// 쓴 파일(firstFile) 닫기
	fin.close();									// 읽은 파일(secondFile) 닫기

	fin.open(firstFile, ios::in);
	if (!fin) {										// 파일열기 실패유무 검사
		cout << secondFile << " 열기오류";
		return 0;
	}

	while((c = fin.get()) != EOF) {				// 읽은 문자가 있는 경우 반복 (문서의 끝이라 읽은 문자가 없는 경우 루프탈출)
		cout << (char)c;						// 읽은 문자 출력 
	}

	fin.close();								// 읽은 파일(firstFile) 닫기

	return 0;
}