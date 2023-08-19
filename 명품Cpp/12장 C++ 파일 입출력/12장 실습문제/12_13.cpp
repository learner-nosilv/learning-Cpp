/* 단어가 들어있는 words.txt 파일을 읽어 단어별로 vector에 저장하고,
 사용자가 입력한 문자열로 시작되는 모든 단어를 출력하는 프로그램
 (없다면, "발견할 수 없음"	exit 입력시 종료 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Word {
	vector<string> wordBook;		// 단어를 저장할 가변배열
	string user;					// 사용자가 입력한 단어
	int userSize;					// 사용자가 입력한 단어의 문자수
	bool find1DiffWord();			// 한 글자만 다른 단어를 찾고 출력하는 함수
	bool findIncludingWord();		// 사용자가 입력한 단어로 시작하는 단어
public:
	Word() {						// 생성자: words.txt 파일 속 단어들을 모두 vector에 저장
		cout << '.';
		ifstream fin("C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\words.txt");
		if (!fin) {
			cout << "파일열기실패\n";
			return;
		}
		string word;						// 단어 임시저장
		while (getline(fin, word))			// 파일 속 한 줄 -> 단어
			this->wordBook.push_back(word);	// 가변배열에 푸시
		cout << "..words.txt 파일 로딩 완료\n검색을 시작합니다. 단어를 입력해 주세요.\n";
	}
	void run(int menu) {
		while (true) {
			cout << "단어>> ";
			cin >> this->user;
			this->userSize = user.size();
			if (user == "exit")
				return;
			else if ((menu == 0) && (this->find1DiffWord() == false))
				cout << "발견할 수 없음\n";
			else if ((menu == 1) && (this->findIncludingWord() == false))
				cout << "발견할 수 없음\n";
		}
	}
	~Word() { fin.close(); }
};

// 한 글자만 다른 단어를 찾고 출력하는 함수
bool Word::find1DiffWord() {
	bool result = false;
	for (int i = 0; i < this->wordBook.size(); i++) {			// 루프: 가변배열 속 모든 원소 갯수만큼 반복
		if (this->wordBook[i].size() == this->userSize) {		//	글자수가 같은 경우
			int count = 0;										//		변수: 두 단어 간 같은 글자수
			for (int j = 0; j < this->userSize; j++) {			//		루프: 모든 글자수만큼 반복
				if (this->wordBook[i][j] == user[j])			//			동일한 위치에 같은 글자가 있다면
					count++;									//			카운트 1증가
			}
			if (count == this->userSize - 1) {					//		한 글자만 다르다면
				cout << this->wordBook[i] << '\n';				//		해당 단어 출력
				result = true;									//		단어를 찾았으므로 true
			}
		}
	}
	return result;												// 한번도 못 찾은 경우만 false 리턴
}

// 사용자가 입력한 단어로 시작하는 단어
bool Word::findIncludingWord() {
	bool result = false;
	for (int i = 0; i < this->wordBook.size(); i++) {					// 루프: 가변배열 속 모든 원소 갯수만큼 반복
		if (this->wordBook[i].size() >= this->userSize) {				//	크기가 더 크고 (substr 오류방지)
			if (wordBook[i].substr(0, this->userSize) == this->user) {	//	앞 부분이 사용자가 입력한 단어와 동일하다면
				cout << this->wordBook[i] << '\n';						//		해당 단어 출력
				result = true;											//		단어를 찾았으므로 true
			}
		}
	}
	return result;														// 한번도 못 찾은 경우만 false 리턴 
}

int main() {
	Word wordbook;			// 단어장의 단어를 멤버함수로 갖고, 한글자만 다른 단어(0)나 앞이 같은 단어(1)를 찾아주는 클래스의 객체 생성
	wordbook.run(1);		// 앞이 같은 단어를 찾아주는 방식으로 run
	return 0;
}