/* 파일을 복사하는 동안 10%를 진행할 때마다 '.'과 바이트 크기를 다음과 같이 출력하는 프로그램 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// 1. 파일열기: 읽/쓰 포인터가 따로 움직이고 있다는 것을 인지하기
	const char* read = "c:\\windows\\system.ini";																						// 읽을 파일의 위치
	const char* writeOn = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\12_06_system.txt";	// 쓸 파일의 위치
	ifstream fin(read, ios::binary);			// 읽을 파일
	ofstream fout(writeOn, ios::binary);		// 쓸 파일
	if (!fin || !fout) {
		cout << "파일열기실패" << endl;
		return 0;
	}

	// 2. 파일포인터를 이용하여 파일크기 알아내기
	fin.seekg(0, ios::end);				// get(읽기)포인터 이동: EOF = 크기(byte)
	int length = (int)fin.tellg();		// 크기 저장
	cout << read << " 크기: " << length << "Byte" << endl;
	int i = length / 10;				// 10%에 해당하는 바이트 값 (소수점 버림적용, 따라서 10%이하)
	cout << "약 10%: " << i << "Byte\n" << endl;
	char* buf = new char[i];			// 해당 바이트만큼의 문자를 저장할 블록

	// 3. 읽은 파일의 약 10%씩을 목적 파일에 쓰기 * 10회
	fin.seekg(0, ios::beg);
	cout << "복사 시작...\n";
	for (int j = 0; j < 10; j++) {
		fin.read(buf, i);										// 파일에서 10%(이하)에 해당하는 데이터 읽기
		fout.write(buf, i);										// 해당 문자열만큼 기록
		cout << '.' << i << "B " << (j + 1) << "0%" << endl;	// 복사현황 콘솔출력
	}

	// 4. 아직 안 읽힌 데이터가 있다면, 마지막으로 목적 파일에 쓰기
	if (!fin.eof()) {											// 아직 다 읽지 않았다면,
		fin.read(buf, i);										// 파일에서 10%(이하)에 해당하는 데이터 읽기
		fout.write(buf, fin.gcount());										// 해당 문자열만큼 기록
	}

	// 5. 파일 쓰기가 완료됨을 알리기
	cout << "파일 크기: " << length << "Byte / 실제 " << ((i * 10) + fin.gcount()) << "Byte 복사 완료" << endl;

	delete[] buf;

	return 0;
}