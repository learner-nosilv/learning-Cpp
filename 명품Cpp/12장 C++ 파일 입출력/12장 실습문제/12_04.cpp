/* 4. 실습문제3에서는 대문자로 변환하여 출력하였다. 실습문제4에서는 변환하여 새 파일에 저장한 후, 출력하여 테스트하기 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// 1. 파일열기: 읽/쓰 포인터가 따로 움직이고 있다는 것을 인지하기
	const char* file = "c:\\windows\\system.ini";	// 출력할 파일의 위치
	ifstream fin(file);								// 읽기목적으로 파일열기(연결)
	if (!fin) {
		cout << "IN: 파일 열기 실패" << endl;
		return 0;
	}
	ofstream fout("text.txt");						// 쓰기목적으로 파일열기(연결)
	if (!fout) {
		cout << "OUT: 파일 열기 실패" << endl;
		return 0;
	}

	// 2. 파일변환
	int n;
	while ((n = fin.get()) != EOF) {				// 한 문자 읽기
		if (n >= 'a' && n <= 'z')					// 소문자인 경우 -> 대문자
			n = n - 'a' + 'A';						// n = toupper(n);
		fout.put((char)n);							// 쓰기
	}
	fin.close();
	fout.close();

	// 3. 파일콘솔출력
	fin.open("text.txt", ios::in);					// 읽기목적으로 파일열기(연결)
	string line;
	while (getline(fin,line)) {
		cout << line << endl;
	}
	return 0;
}