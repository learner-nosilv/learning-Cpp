/* 연습문제 4. getFileSize() 함수는 매개변수에 NULL이 넘어오면 -1을, 파일을 열 수 없으면 -2를 리턴하고, 정상적인 경우 파일크기 리턴
	위 프로그램을 수정하여 try-throw-catch 블록으로 예외 처리하고 프로그램 완성하기*/
#include <iostream>
#include <fstream>
using namespace std;

int getFileSize(const char* name) throw (const char*) {
	if (name == NULL) throw "파일명이 NULL 입니다.";
	ifstream fin(name, ios::in | ios::binary);
	if (!fin) throw "파일열기를 실패하였습니다.";
	fin.seekg(0, ios::end);			// 파일 끝으로 포인터 이동
	int size = (int)fin.tellg();	// 파일 끝의 index = 파일크기 (byte)
	return size;
}

int main() {
	try {
		int n = getFileSize("C:\\windows\\system.ini");
		cout << "파일크기 = " << n << endl;
		n = getFileSize(NULL);
		cout << "파일크기 = " << n << endl;
	}
	catch (const char* msg) {
		cout << "예외 발생 : " << msg << endl;
	}
	return 0;
}