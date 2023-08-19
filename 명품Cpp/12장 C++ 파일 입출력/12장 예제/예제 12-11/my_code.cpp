/* p.623	예제12-11	스트림 상태 검사 */
#include <iostream>
#include <fstream>
using namespace std;

// State bit의 상태 출력
void showStreamState(ios& stream) {					// ios형의 참조매개변수
	cout.setf(ios::boolalpha);						// bool형 값은 true/false 형식으로 출력
	cout << "eof()\t" << stream.eof() << endl;		// end of file bit = 1 : 파일의 끝 
	cout << "fail()\t" << stream.fail() << endl;	// failbit 나 bad bit = 1 : 전반적 오류or데이터 손상수준오류나 유효하지않은 명령 
	cout << "bad()\t" << stream.bad() << endl;		// bad bit = 1 : 데이터손상수준, 유효하지 않은 명령오류
	cout << "good()\t" << stream.good() << endl;
}

int main() {
	// 읽을 파일의 이름
	const char* noExistFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-10\\datad.dat";
	const char* existFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-10\\data.dat";

	ifstream fin(noExistFile);	// 존재하지 않은 파일과 연결
	if (!fin) {
		cout << noExistFile << " 열기 오류" << endl;		// 상태 출력
		showStreamState(fin);							// 스트림 상태 출력
	}

	cout << existFile << " 파일 열기" << endl;			// 존재하는 파일 열기
	fin.open(existFile);
	showStreamState(fin);								// 스트림 상태 출력

	// 스트림을 끝까지 읽고 파일 출력
	int c;
	while ((c = fin.get()) != EOF)						// 루프: 파일 1byte 읽기 (파일의 끝이면 루프탈출)
		cout.put(char(c));

	cout << endl << "- 파일 끝까지 읽은 후: 스트림 상태\n";
	showStreamState(fin);

	fin.close();
	return 0;
}