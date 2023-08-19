/* P.598	키보드로부터 입력 받아 텍스트 파일 저장하기 */
#include <iostream>		// 표준 입출력 라이브러리
#include <fstream>		// 표준 파일 입출력 라이브러리
using namespace std;

int main() {
	char name[10], dept[20];	// C-string형: 이름(9자+\0), 학과(19자+\0)
	int sid;					// 학번: Student ID

	// 키보드로부터 입력받기 : iostream
	cout << "이름>>";
	cin >> name;				// 이름: 키보드->입력스트림->프로그램의 name변수
	cout << "학번(숫자로)>>";
	cin >> sid;					// 학번: 키보드->입력스트림->프로그램의 sid변수
	cout << "학과>>";
	cin >> dept;				// 학과: 키보드->입력스트림->프로그램의 dept변수

	// 파일열기 : 파일->파일출력스트림->프로그램연결
	ofstream fout("C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-1\\student.txt");	// \를 쓰려면 \\를 써야함
	if (!fout) {
		cout << "파일을 열 수 없다";
		return 0;
	}

	// 파일쓰기
	fout << name << endl;	// 이름과 개행
	fout << sid << endl;	// 학번과 개행 (정수 -> 문자로 변환)
	fout << dept << endl;	// 학과와 개행

	fout.close();			// 파일닫기, 연결해제
	
	return 0;
}