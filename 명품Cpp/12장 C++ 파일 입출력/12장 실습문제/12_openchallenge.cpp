/* 632p.	OpenChallenge	HangMan Game 
	- 영단어 랜덤선택
	- 랜덤한 N(2)개의 글자 숨기기	-> 게임생성자의 파라미터로 지정
	- 5번 틀리면 프로그램 종료
*/
#include <iostream>	// C++ 표준 입출력 라이브러리
#include <string>	// string type 멤버
#include <fstream>	// C++ 표준 파일 입출력 라이브러리
#include <vector>	// 파일 속 단어를 가변배열에 할당
#include <map>		// 단어에서 숨길 (index, 답)
#include <iterator>	// 반복자
#include <random>	// 랜덤함수
#include <ctime>	// 시간 srand의 seed로 설정
using namespace std;

class HangMan {
	vector<string> wordBook;	// 단어장
	string word;				// 선정 단어
	int level;					// 빈 칸 개수
	map<int, char> blank;		// 빈 칸 인엑스, 빈 칸의 답

	void set();					// 단어와 빈 칸 선정
	void showWord();			// 빈 칸이 반영된 단어 출력
	void game();				// 게임 한 판
public:
	HangMan(const char* wordFile, int level);
	void run();
};

// 생성자
HangMan::HangMan(const char* wordFile, int level) {
	ifstream fin(wordFile);						// 파일 읽기 스트림 객체 생성 & 읽기 목적으로 프로그램-파일연결
	string word;								// 한 단어 <- 한 줄
	while (getline(fin, word))					// 루프 : EOF 전까지
		this->wordBook.push_back(word);			// 단어장에 추가 
	fin.close();								// 파일 연결 해제
	this->level = level;						// 난이도 설정
	srand((unsigned)time(NULL));				// 랜덤 seed 설정
}

// 단어와 빈 칸 선정
void HangMan::set() {
	// 1. 단어 선정
	int idx = rand() % 25143;				// 단어 선정에 쓸 인덱스 랜덤하게 할당
	this->word = this->wordBook[idx];		// 단어 선정
	int length = this->word.length();		// 단어 길이

	// 2. 빈 칸 선정
	blank.clear();																// 빈 칸 초기화
	for (int i = 0; (i < (this->level) && i < length); i++) {					// 빈 칸의 갯수=난이도 && 단어길이보다 많을 수 없음
		int randIdx = rand() % length;
		auto iter = blank.insert({ randIdx , word[randIdx] });							// 빈 칸 인덱스, 빈 칸의 답 (중복으로 인한 실패시, iter의 두번째 원소=false)
		if (iter.second == false) {												// 빈 칸 인덱스가 중복된 경우
			i--;
			continue;															// 빈 칸 선정 재실행
		}
	}
}

// 빈 칸이 반영된 단어 출력
void HangMan::showWord() {
	for (int i = 0; i < this->word.length(); i++) {
		if (blank.find(i) == blank.end())				// 설정된 빈 칸이 아닌 경우
			cout << word[i];							// 글자 출력
		else
			cout << '-';
	}
}

// 게임 한 판
void HangMan::game() {
	char answer;					// 사용자 답안
	int count=0;					// 틀린 횟수
	this->set();					// 단어와 빈 칸 선정

	while (true) {
		bool clear = false;			// 정답여부
		this->showWord();			// 문제 보여주기
		cout << ">>";
		cin >> answer;				// 답안 받기
		for (auto it = blank.begin(); it != blank.end(); it++) {	// 답안 비교
			if ((it->second) == answer) {							// 답이라면 빈 칸 삭제
				clear = true;										// 정답처리
				blank.erase(it);									// 빈 칸 제거
				break;
			}
		}
		if (clear == false) count++;								// 틀린 경우, 틀린 횟수 증가
		if (count > 4) {											// 5회 틀린 경우
			cout << "5번 실패 하였습니다.\n" << this->word << endl;	// 답안을 보여준 후,
			break;													// 게임 종료
		}
		if (blank.size() == 0) {									// 답을 모두 맞춘 경우
			cout << this->word << endl;								// 답안을 보여준 후
			break;													// 게임 종료
		}
	}
}

// 게임 전체 작동
void HangMan::run() {
	cout << "----------------------------------------------\n"
		<< "지금부터 행맨 게임을 시작합니다.\n"
		<< "----------------------------------------------\n";
	char reGame = 'y';
	while (reGame=='y') {
		game();
		cout << "Next(y/n)?";
		cin >> reGame;
	}
}

int main() {
	HangMan mark1("C:\\Users\\renee\\source\\repos\\learning-Cpp\\명품Cpp\\12장 C++ 파일 입출력\\12장 실습문제\\words.txt", 2);	// 해당 단어파일, 2개의 글자가 숨겨진 난이도의 행맨게임객체 생성
	mark1.run();		// 행맨게임 실행
	return 0;
}