/* 9. vector을 응용하여, 파일내용 중 입력받은 숫자의 라인을 출력하는 프로그램 */
#include <iostream>	// 표준 입출력 라이브러리
#include <fstream>	// 표준 파일입출력 라이브러리
#include <string>
#include <vector>	// 가변배열
using namespace std;

// 입력오류가 있는지 검사하는 함수
bool isError() {
	if (cin.fail()) {	// 문자르 입력하여 버퍼가 오류상태인 경우
		cin.ignore(99, '\n');
		cin.clear();
		return true;
	}
	return false;
}

int main() {
	// 1. 파일 열기
	const char* srcFile = "c:\\windows\\system.ini";
	ifstream fin(srcFile, ios::in | ios::binary);
	if (!fin) {
		cout << "파일열기실패\n";
		return 0;
	}

	// 2. 파일을 한줄단위로 가변배열에 저장
	vector<string> content;
	string buf;
	while (getline(fin,buf,'\n'))			// 한 줄씩 읽기(구분자는 저장X 버퍼에선 삭제됨)
		content.push_back(buf);
	cout << srcFile << " 파일 읽기 완료\n";

	cout << "라인 번호를 입력하세요. 1보다 작은 값을 입력하면 종료\n";
	// 3. 라인을 입력받고, 출력하기
	while (true) {
		int answer;
		cout << ": ";
		cin >> answer;
		if (isError()) {					// 경우1. 입력에 오류가 있는 경우
			cout << "[ERROR] 숫자 하나를 입력하세요\n";
			continue;						// 재입력
		}
		else if (answer < 1)				// 경우2. 1보다 작은 수를 입력한 경우
			break;
		else if (answer > content.size()) {	// 경우3. 요구하는 라인이 파일크기를 넘어선 경우
			continue;
		}
		else								// 경우4. 제대로 입력한 경우
			cout << content[(answer - 1)] << endl;
	}
	cout << "종료 합니다." << endl;
	return 0;
}