/* 8. 파일을 왼쪽은 16진수 오른쪽은 문자로 8자씩 구역을 나누어 출력하는 프로그램 작성하기
 16진수 출력은 조작자: hex 이용 
 8글자는 띄어쓰기로 구분
 8글자 한 묶음간은 공백4칸 으로 구분
 8글자 두 묶음간은 16진수/문자로 구분
 16글자를 한 버퍼에 넣어서 한번은 16진수로 한번은 문자로 출력하기

 힌트가 왜 뒷장에 있어

*/
#include <iostream>
#include <fstream>
using namespace std;

void print16Byte(char* buf, int bufSize, int option) {	// option: 0이면 hex, 그 외면 문자
	// 문자로 출력
	if (option) {
		for (int i = 0; i < 16; i++) {
			// 한 글자 출력
			if (i < bufSize) {							// 1글자 출력 : 출력값이 있는 경우
				if (isprint(buf[i]))					//		출력가능한 문자인 경우 제대로 출력
					cout << buf[i];
				else									//		출력불가한 문자인 경우 '.'으로 대체 출력				
					cout << '.';	
			}
			else										// 1글자 출력 : 출력값이 없는 경우 공백출력
				cout << ' ';
			// 구분자 출력
			if (i == 7 || i == 15)						// 구분자 출력 : 8, 16글자단위로 긴 공백
				cout << "    ";
			else										// 구분자 출력 : 기본 공백
				cout << ' ';
		}
	}
	// 16진수로 출력
	else {
		for (int i = 0; i < 16; i++) {
			// 한 글자 출력
			if (i < bufSize) {							// 1글자 출력 : 출력값이 있는 경우 제대로 출력
				cout.width(2);
				cout.fill('0');
				cout << hex << (int)buf[i];
			}
			else										// 1글자 출력 : 출력값이 없는 경우 공백출력
				cout << "  ";
			// 구분자 출력
			if (i == 7 || i == 15)						// 구분자 출력 : 8, 16글자단위로 긴 공백
				cout << "    ";
			else										// 구분자 출력 : 기본 공백
				cout << ' ';
		}
	}
}

int main() {
	// 1. 파일 열기
	const char* srcFile = "c:\\windows\\system.ini";
	ifstream fin(srcFile, ios::in | ios::binary);
	if (!fin) {
		cout << "파일열기실패\n";
		return 0;
	}
	// 2. 파일 읽고 출력
	char buf[16];						// 파일내용을 저장할 버퍼
	while (!fin.eof()) {
		fin.read(buf, 16);					// 16byte 단위로 파일읽기
		int realCount = (int)fin.gcount();	// 실제 읽은 byte 수
		print16Byte(buf, realCount, 0);		// 16byte 16진수로 출력
		print16Byte(buf, realCount, 1);		// 16byte 문자로 출력
		cout << '\n';
	}
	return 0;
}