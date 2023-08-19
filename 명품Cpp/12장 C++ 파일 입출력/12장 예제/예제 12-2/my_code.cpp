/* P.600	ifstream과 >> 연산자를 이용한 텍스트 파일 읽기 */
#include <iostream>		// 표준 입출력 라이브러리
#include <fstream>		// 표준 파일 입출력 라이브러리
using namespace std;

int main() {
	ifstream fin;
	fin.open("C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-1\\student.txt");
	if (!fin) {
		cout << "파일을 열 수 없다";
		return 0;
	}

	char name[10], dept[20];	// C-string형: 이름(9자+\0), 학과(19자+\0)
	int sid;					// 학번: Student ID

	// 파일 읽기 -> 스트림버퍼-> 변수 할당
	fin >> name;				// 이름: 파일내용 중 구분자(띄어쓰기나 개행)전까지의 문자 -> 프로그램의 name변수
	fin >> sid;					// 학번: 파일내용 중 구분자(띄어쓰기나 개행)전까지의 문자 -> 숫자로 변환하여 -> 프로그램의 sid변수
	fin >> dept;				// 학과: 파일내용 중 구분자(띄어쓰기나 개행)전까지의 문자 -> 프로그램의 dept변수


	// 읽은 텍스트 파일의 내용을 화면에 출력
	cout << name << endl;	// 이름과 개행
	cout << sid << endl;	// 학번과 개행 (정수 -> 문자로 변환)
	cout << dept << endl;	// 학과와 개행

	fin.close();			// 파일닫기, 연결해제
	
	return 0;
}