/* p.618	예제12-09	read()/write()로 이미지 파일 복사 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// 소스 파일과 목적 파일의 이름
	const char* srcFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\명품CPP앞표지-1-scaled.jpg";
	const char* destFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-9\\copy.jpg";

	// 소스 파일 열기
	ifstream fsrc(srcFile, ios::in | ios::binary);
	if (!fsrc) {	// 열기 실패 검사
		cout << srcFile << " 열기 오류" << endl;
		return 0;
	}

	// 목적 파일 열기
	ofstream fdest(destFile, ios::out | ios::app | ios::binary);
	if (!fdest) {	// 열기 실패 검사
		cout << destFile << " 열기 오류" << endl;
		return 0;
	}

	// 소스파일에서 목적파일로 파일 복사하기
	char buf[1024];					// 버퍼블록: 1024바이트
	while (!fsrc.eof()) {			// 파일의 끝에 온 경우, 루프탈출
		fsrc.read(buf, 1024);		// fsrc의 바이너리코드를 파일 읽기 스트림버퍼에 넣고, 최대 1024바이트만큼의 바이너리코드만 buf에 할당
		int n = fsrc.gcount();		// 버퍼에서 나와 읽힌 바이트 량 할당
		fdest.write(buf, n);		// buf배열에 저장된 바이너리 값 중 버퍼에서 나와 읽힌 바이트만큼 목적파일에 쓰기
	}
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	fsrc.close();
	fdest.close();

	return 0;
}