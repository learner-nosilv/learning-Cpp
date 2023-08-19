/* p.614	예제12-07	get()와 put()을 이용한 이미지 파일 복사 */
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// 소스 파일과 목적 파일의 이름
	const char* srcFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\명품CPP앞표지-1-scaled.jpg";
	const char* destFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-7\\copy.jpg";

	// 소스 파일 열기
	ifstream sourceFile(srcFile, ios::in | ios::binary);		// binary 형식으로 파일을 열어 읽기
	if (!sourceFile) {											// 열기 실패 검사
		cout << srcFile << "열기 오류" << endl;
		return 0;
	}

	// 목적 파일 열기
	ofstream destinationFile(destFile, ios::out | ios::app | ios::binary);	// binary 형식으로 파일을 열어 쓰기
	if (!destinationFile) {
		cout << destFile << "열기 오류" << endl;
		return 0;
	}

	// 소스 파일 읽고 -> 목적파일 쓰기로 내용 복사
	int c;	// int는 4byte지만, 문자 하나(1byte)씩 읽기
	while ((c = sourceFile.get()) != EOF) {	// 루프: 읽은 값이 글의 끝이 아닌 동안 (글이 끝이면 루프탈출)
		destinationFile.put(c);				// 파일에 쓰기
	}
	
	cout << srcFile << "을 " << destFile << "로 복사 완료" << endl;
	sourceFile.close();						// 읽은 파일 닫기
	destinationFile.close();				// 쓴 파일 닫기

	return 0;
}