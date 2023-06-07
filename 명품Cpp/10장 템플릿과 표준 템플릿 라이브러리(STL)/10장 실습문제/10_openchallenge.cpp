/* 520p. 10장 Open Challenge: 영어 어휘 테스트 작성
	class Word: string 한글/영어
	vector<Word> v인 가변배열을 이용하여
	아래와 같은 테스트 프로그램 작성하기
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Word {
	string eng;
	string kor;
public:
	Word(string eng = "", string kor = "") { this->eng = eng; this->kor = kor; }
	string getEng() { return this->eng; }
	string getKor() { return this->kor; }
};

class WordTest {
	vector<Word> v;		// 모든 단어들이 저장된 가변배열
	int idxBox[4];		// 가변배열의 원소(단어) 중 선지에 들어갈 4 단어의 인덱스
	int answer;			// 선지 중 답 번호
public:
	WordTest() {
		srand((unsigned)time(NULL));
		v.push_back(Word("human", "인간"));		// 0
		v.push_back(Word("society", "사회"));	// 1
		v.push_back(Word("doll", "인형"));		// 2
		v.push_back(Word("emotion", "감정"));	// 3
		v.push_back(Word("painting", "그림"));	// 4
		v.push_back(Word("trade", "거래"));		// 5
		v.push_back(Word("love", "사랑"));		// 6
		v.push_back(Word("happyness", "행복"));	// 7
		v.push_back(Word("sincerity", "진심"));	// 8
		v.push_back(Word("diligence", "근면"));	// 9
	}
	void makeQuest();	// 문제 제작
	int ask();			// 유저 입력
	void run();			// 프로그램 구동
};
void WordTest::makeQuest() {
	for (int i = 0; i < 4; i++) {			// (10C4) 0-9 사이의 숫자 중 중복없이 4개 선택
		idxBox[i] = rand() % 10;			//	idxBox의 새 원소에 단어선정
		for (int j = 0; j < i; j++) {		//	방금 선정한 단어 vs 이전 원소들
			if (idxBox[i] == idxBox[j]) {	//	방금 선정한 단어가 이전 원소와 중복되었다면,
				idxBox[i] = rand() % 10;	//	재 선정
				j--;
				continue;					//	재 검사
			}
		}
	}								// 선지에 들어갈 단어 4개 선정
	answer = rand() % 4;			// 선지 중 정답 선정
}
int WordTest::ask() {
	int answer;
	cout << ":>";
	cin >> answer;
	return answer - 1;
}
void WordTest::run() {
	cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료합니다." << endl;
	while (true) {
		makeQuest();														// 문제 세팅
		cout << v[this->idxBox[this->answer]].getEng() << '?' << endl;		// 문제 출력
		for (int i = 0; i < 4; i++)											// 선지 출력
			cout << '(' << (i+1) << ") " << v[this->idxBox[i]].getKor() << ' ';
		int user = ask();						// 유저 답
		if (user == this->answer) {				//	1. 정답이라면,
			cout << "Excellent !!" << endl;
			continue;
		}
		else if (user >= 0 && user < 4) {		//	2. 오답이라면,
			cout << "No. !!" << endl;
			continue;
		}
		else									//	3. 번호 외 다른 입력
			break;
	}
}

int main() {
	WordTest a;
	a.run();
	return 0;
}