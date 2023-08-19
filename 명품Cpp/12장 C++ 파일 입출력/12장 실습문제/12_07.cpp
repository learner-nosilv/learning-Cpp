/* 파일을 바이트단위로 거꾸로 사본에 저장하는 프로그램
	* 두 번 사용하여 프로그램에 오류가 없는지 확인할 것 */

#include <iostream>
#include <fstream>
using namespace std;

// 파일을 거꾸로 복사해주는 함수
void reverseCopy(const char* srcFile, const char* destFile) {
	// 1. 파일열기
	ifstream fin(srcFile, ios::binary);
	ofstream fout(destFile, ios::binary);
	if (!fin || !fout) {
		cout << "복사실패: 파일 열기 오류\n";
		return;
	}

	// 2. 뒤->앞으로 복사; 읽기 포인터(get pointer) 뒤에서부터 앞으로 옮겨가기
	fin.seekg(-1, ios::end);			// 포인터 맨 뒤의 이전: EOF 직전
	int size = (int)fin.tellg() + 1;	// 파일 크기 파악 = EOF

	for (int i = 0; i < size; i++) {
		int c = fin.get();			// 읽기 ( 앞으로 한 칸 진행 )
		fout.put(c);				// 복사
		fin.seekg(-2, ios::cur);	// 읽기 포인터를 읽기 이전의 문자위치로 이동
	}
	fin.close();
	fout.close();
	cout << "복사완료\n";
	return;
}

// 파일내용을 textI/O를 이용하여 콘솔에 출력하는 함수
void show(const char* srcFile) {
	// 1. 파일열기
	ifstream fin(srcFile, ios::binary);
	if (!fin) {
		cout << "출력실패: 파일 열기 오류\n";
		return;
	}

	// 2. 화면출력
	char buf[32];
	while (!fin.eof()) {
		fin.read(buf, 32);
		cout.write(buf, fin.gcount());
	}
	fin.close();
	return;
}

int main() {
	// 1. 파일 세팅
	const char* file[3] = { "c:\\windows\\system.ini",																					// 읽을 파일의 위치		[정]
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\12_07_system.txt",					// 쓸 파일의 위치			[역]
		"C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\12_07_systemRE.txt" };				// 다시 쓸 파일의 위치		[정]

	// 2. 파일 역복사
	for (int i = 0; i < 2; i++)
		reverseCopy(file[i], file[(i + 1)]);

	// 3. 파일 내용 콘솔출력
	for (int i = 0; i < 3; i++) {
		cout << "\n[ 파일" << (i + 1) << " ]\n";
		show(file[i]);
		cout << endl;
	}

	return 0;
}