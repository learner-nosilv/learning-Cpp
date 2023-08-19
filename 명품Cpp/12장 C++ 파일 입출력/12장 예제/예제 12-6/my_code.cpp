/* p.612	예제12-06	getline(ifstream&, string&) 으로 words.txt 파일을 읽고 단어 검색*/

#include <iostream>	// C++ 표준 입출력 라이브러리
#include <fstream>	// C++ 표준 파일 입출력 라이브러리
#include <string>
#include <vector>	// 가변배열
using namespace std;

// 파일을 한 줄씩 읽어서, 한 줄 = 가변배열의 원소로 할당
void fileRead(vector<string>& v, ifstream& fin) {	// 참조매개변수: 가변배열v, 파일읽기객체 fin
	string line;	// 한 줄 저장
	while (getline(fin, line)) {	// fin 객체로 파일읽고 line에 할당
		v.push_back(line);			// 원소타입이 string형인 가변배열 v의 뒤쪽에 삽입
	}
}

// 가변배열 형태로 저장된 텍스트 내용 중 원하는 단어가 들어있는 줄을 찾아서 해당 줄 전체를 출력하는 함수
void search(vector<string>& v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);	// 해당 문자열에서 단어가 등장하는 첫 index 값 리턴 (없으면 -1)
		if (index != -1) {
			cout << v[i] << endl;		// 단어가 포함되어있다면 해당 줄 전부 출력
		}
	}
}


int main() {
	vector<string> wordVector;
	const char* firstFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 예제\\예제 12-6\\words.txt";
	ifstream fileIn(firstFile);		// 해당 파일을 열어서 읽어들이는 파일 읽기 스트림 객체 선언
	if (!fileIn) {					// 파일 열기가 실패한 경우
		cout << firstFile << " 파일을 열 수 없습니다" << endl;
		return 0;
	}

	fileRead(wordVector, fileIn);	// 파일읽기스트림객체를 통해서, 파일 내용을 한 줄 단위로 가변배열에 할당
	fileIn.close();					// 파일읽기스트림객체와 연결된 파일닫기

	cout << firstFile << " 파일을 읽었습니다." << endl;
	while (true) {					// 무한루프
		cout << "검색할 단어를 입력하세요 >>";
		string word;
		getline(cin, word);
		if (word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "프로그램을 종료합니다." << endl;

	return 0;
}