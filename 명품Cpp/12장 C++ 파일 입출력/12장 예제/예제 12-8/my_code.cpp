/* p.616	예제12-08	read()를 이용하여 블록 단위로 텍스트 파일 읽기 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* firstFile = "c:\\windows\\system.ini";

	ifstream fin(firstFile, ios::in | ios::binary);
	if (!fin) {			// 파일 열기 실패 시
		cout << "파일 열기 오류";
		return 0;
	}

	int count = 0;					// 버퍼로부터 실제 읽힌 문자(=바이트) 수
	char blockBuf[32];				// 블록 단위로 읽어들일 버퍼
	while (!fin.eof()) {			// 읽은 값 없이 파일의 끝인 경우 루프탈출
		fin.read(blockBuf, 32);		// 최대 32byte를 읽어서 버퍼에 저장
		int n = fin.gcount();		// 스트림버퍼에서 읽혀져 처리된 바이트 수 할당
		cout.write(blockBuf, n);	// 읽은 만큼의 바이너리값(최대 32byte)을 콘솔에 출력 (1byte=16진수 2자리, 32byte = 64자리)
		count += n;					// 읽은 바이너리단위 갯수 누적
	}

	cout << "읽은 바이트 수는 " << count << endl;
	fin.close();					// 파일 닫기

	return 0;
}