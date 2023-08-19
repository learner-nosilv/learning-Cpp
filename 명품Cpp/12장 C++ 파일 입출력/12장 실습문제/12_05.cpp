/* 5. c++ 소스파일에서 //로 시작하는 주석문을 배고 출력하는 프로그램 작성하기 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// 1. 파일열기: 읽/쓰 포인터가 따로 움직이고 있다는 것을 인지하기
	const char* file = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\12_05_solution_ShowNoComment.cpp";
	ifstream fin(file);					// 읽을 파일
	ofstream fout("12_05_test.cpp");	// 쓸 파일
	if (!fin || !fout) {
		cout << "파일열기실패" << endl;
		return 0;
	}
	
	// 2. //로 된 주석문 삭제 (특징: // 이후로 해당 줄은 모두 삭제)
	string line;
	while (getline(fin,line,'\n')) {	// 루프 : 라인단위 읽기 (파일을 끝까지 읽기 전까지)
		int pos = line.find("//");		// 주석시작위치
		if (pos != -1)					// 주석이 존재한다면
			line.resize(pos);			// 주석 앞에서 자르기 (주석이 index 3까지면, 주석 앞까지는 size가 3byte)
		fout << line << endl;			// 라인->파일쓰기
	}
	fin.close();
	fout.close();

	// 3. 작성한 파일 읽기
	fin.open("12_05_test.cpp", ios::in);	// 읽기 목적으로 파일연결
	if (!fin) {
		cout << "파일열기실패" << endl;
		return 0;
	}
	while (getline(fin, line, '\n'))
		cout << line << endl;
	return 0;
}