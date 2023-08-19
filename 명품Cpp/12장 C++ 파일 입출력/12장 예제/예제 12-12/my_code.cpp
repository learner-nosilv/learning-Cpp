/* p.629	예제12-12	파일 크기 알아내기 */
#include <iostream>
#include <fstream>
using namespace std;

// 파일크기를 byte단위 리턴 (long형의 크기는 16byte이므로, 2의 15승-1 값까지 표현가능)
long getFileSize(ifstream& fin) {
	fin.seekg(0, ios::end);		// get pointer를 EOF에서 0만큼 전진 = EOF
	return (fin.tellg());		// 입력 스트림의 현재 get pointer의 절대위치 반환
}

int main() {
	const char* file = "c:\\windows\\system.ini";	// 크기를 알고싶은 파일의 위치

	ifstream fin(file);		// 파일입력 스트림객체와 연결
	if (!fin) {
		cout << file << " 열기 오류" << endl;
		return 0;
	}

	cout << file << "의 크기는 " << getFileSize(fin) << "byte 입니다." << endl;
	fin.close();

	return 0;
}