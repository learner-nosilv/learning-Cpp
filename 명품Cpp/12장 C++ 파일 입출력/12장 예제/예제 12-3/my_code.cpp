/* P.605	예제12-03	get()을 이용한 텍스트 파일 읽기 */
#include <iostream>		// 표준 입출력 라이브러리
#include <fstream>		// 표준 파일 입출력 라이브러리
using namespace std;

int main() {
	const char* file = "c:\\windows\\system.ini";	// 읽을 파일명
	ifstream fin(file, ios::in);					// 파일 읽기 스트림 객체 생성 & 읽기 목적으로 파일 열기

	if (!fin) {										// 파일 읽기 실패 시,
		cout << file << " 열기 오류" << endl;
		return 0;
	}

	int count = 0;		// 변수: 읽은 문자 개수
	int c;				// 변수: 현재 읽은 문자

	while ((c = fin.get()) != EOF) {	// 현재 읽은 문자가 있으면(=파일의 끝이 아니면) 반복 (파일의 끝이면 탈출)
		cout << (char)c;				// 현재 읽은 문자 콘솔출력
		count++;						// 읽은 문자 개수 카운트
	}

	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();		// 파일 닫기

	return 0;
}