/* 단어가 들어있는 words.txt 파일을 읽어 단어별로 vector에 저장하고,
 사용자로부터 단어를 입력받아, 한 글자만 다른 단어를 모두 출력하기
 사용자가 입력한 단어와 한 글자만 다른 단어가 없는 경우 "단어없음" 출력하기
 * 사용자가 exit를 입력한 경우 프로그램 종료 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Word {
	vector<string> wordBook;		// 단어를 저장할 가변배열
	string user;
	int userSize;
	bool findWord();				// 한 글자만 다른 단어를 찾고 출력하는 함수
public:
	Word() {						// 생성자: words.txt 파일 속 단어들을 모두 vector에 저장
		cout << '.';
		ifstream fin("C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\words.txt");
		if (!fin) {
			cout << "파일열기실패\n";
			return;
		}
		string word;					// 단어 임시저장
		while (getline(fin, word))		// 파일 속 한 줄 -> 단어
			wordBook.push_back(word);	// 가변배열에 푸시
		cout << "..words.txt 파일 로딩 완료\n검색을 시작합니다. 단어를 입력해 주세요.\n";
	}
	void run() {
		while (true) {
			cout << "단어>> ";
			cin >> user;
			userSize = user.size();
			if (user == "exit")
				return;
			else if (this->findWord() == false)
				cout << "발견할 수 없음\n";
		}
	}
	~Word() { fin.close(); }
};

// 한 글자만 다른 단어를 찾고 출력하는 함수
bool Word::findWord() {
	bool result = false;
	for (int i = 0; i < wordBook.size(); i++) {			// 루프: 가변배열 속 모든 원소 갯수만큼 반복
		if (wordBook[i].size() == userSize) {			//	글자수가 같은 경우
			int count = 0;								//		변수: 두 단어 간 같은 글자수
			for (int j = 0; j < userSize; j++) {		//		루프: 모든 글자수만큼 반복
				if (wordBook[i][j] == user[j])			//			동일한 위치에 같은 글자가 있다면
					count++;							//			카운트 1증가
			}
			if (count == userSize - 1) {				//		한 글자만 다르다면
				cout << wordBook[i] << '\n';			//		해당 단어 출력
				result = true;							//		단어를 찾았으므로 true
			}
		}
	}
	return result;										// 한번도 못 찾은 경우만 false 리턴
}

int main() {
	Word wordbook;
	wordbook.run();
	return 0;
}

/* 솔루션은
	단어장의 단어와 사용자입력단어가 같은 경우를 제외,
	동일한 크기인 경우,
	for문으로 두 단어의 같은 자리 문자를 '*'로 바꾼 후
	바꾼 두 단어가 동일한지를 비교함
	VS
	나는
	단어장의 단어와 사용자입력단어가 동일한 크기인 경우,
	두 단어가 (단어크기-1) 개 만큼 동일한지 비교함
*/