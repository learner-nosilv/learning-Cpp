/* 14. 입출력포인터의 임의접근방식을 이용하지 않고 read 함수를 이용하여 파일의 크기를 화면에 출력하는 함수
	get(), seekg(), tellg() 사용X
	∴ 파일의 크기를 정확하게 측정해야하므로 ios::binary로 읽고, read()와 .eof()와 gcount() 사용하기 */
#include <iostream>
#include <fstream>
#include <Windows.h>	// 재량으로 Sleep함수 사용해보고픔
using namespace std;

int main() {
	// 1. 파일연결
	const char* srcFile = "c:\\windows\\system.ini";		// 크기를 측정할 파일
	ifstream fin(srcFile, ios::in | ios::binary);			// 읽기 & 바이너리I/O 방식으로 파일연결(열기)
	if (!fin) {												// 연결실패시, 알리고 프로그램 종료
		cout << "파일읽기실패\n";
		return 0;
	}
	cout << "파일 [" << srcFile << "] 을 읽었습니다.\n";

	// 2. 파일읽고 크기측정
	cout << "파일크기 측정 중";
	char buf[32];				// 배열: 파일내용을 읽는 단위(32byte씩)
	int size = 0;				// 변수: 파일크기
	while (!fin.eof()) {		// 파일을 전부 읽을 때까지
		fin.read(buf, 32);		// 32바이트씩 읽고
		Sleep(300);				//	(지연: 1ms 단위이므로 1초는 1000)
		size += fin.gcount();	// 실제 읽은 바이트 값을 누적합산
		cout << '.';
	}

	// 3. 파일크기 출력
	cout << "\n파일크기: " << size << "Byte\n";
	fin.close();
	return 0;
}