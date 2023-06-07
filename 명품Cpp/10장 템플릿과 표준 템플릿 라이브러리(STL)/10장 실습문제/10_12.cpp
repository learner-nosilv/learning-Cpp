/* 12. 10장 Open Challenge: 영어 어휘 테스트 작성에
	사용자가 어휘를 삽입할 수 있도록 기능추가
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
	int idxBox[4];		// 가변배열의 원소 중 선지에 나올 4단어
	int answer;			// 선지 중 답 번호
public:
	WordTest() {		// 기존 단어 10개
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
	int getMenu() {			// 프로그램 메뉴 입력받기
		int menu;
		cout << "어휘 삽입: 1, 어휘 테스트: 2, 프로그램 종료: 그외키 >> ";
		cin >> menu;
		return menu;
	}
	void insertWord();		// 단어 삽입
	int ask() {				// 유저 입력
		int answer;
		cout << ":>";
		cin >> answer;
		return answer - 1;
	}
	void makeQuest();		// 어휘테스트
	void run();				// 프로그램 구동
};

void WordTest::insertWord() {
	string eng, kor; 
	cout << "영어 단어에 exit을 입력하면 입력 끝\n";
	while (true) {
		cout << "영어 >>";
		cin >> eng;
		if (eng == "exit") {		// 무한루프 탈출조건
			cout << endl;
			return;
		}
		for (int i = 0; i < v.size(); i++) {
			if (eng == v[i].getEng()) {
				cout << "이미 있는 단어 입니다.\n";
				eng = "";
				break;
			}
		}
		if (eng == "") continue;		// 이미 있는 단어인 경우, 다시 입력받기
		cout << "한글 >>";				// 정상적인 경우 한글도 입력받기
		cin >> kor;
		v.push_back(Word(eng, kor));
	}
}

void WordTest::makeQuest() {
	cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료.\n";
	while (true) {
		//  1. 선지에 들어갈 단어 4개와, 정답선정
		for (int i = 0; i < 4; i++) {				// (10C4) 0-9 사이의 숫자 중 중복없이 4개 선택
			this->idxBox[i] = rand() % 10;			//	idxBox의 새 원소에 단어선정
			for (int j = 0; j < i; j++) {			//	방금 선정한 단어 vs 이전 원소들
				if (this->idxBox[i] == this->idxBox[j]) {	//	방금 선정한 단어가 이전 원소와 중복되었다면,
					this->idxBox[i] = rand() % 10;	//	재 선정
					j--;
					continue;						//	재 검사
				}
			}
		}											// 선지에 들어갈 단어 4개 선정완료
		answer = rand() % 4;						// 선지 중 정답 선정

		// 2. 문제 출력
		cout << v[idxBox[answer]].getEng() << '?' << endl;		// 문제 출력
		for (int i = 0; i < 4; i++)								// 선지 출력
			cout << '(' << (i + 1) << ") " << v[this->idxBox[i]].getKor() << ' ';

		// 3. 답 입력받고 판정
		int user = ask();						// 유저 답
		if (user == this->answer) {				//	1. 정답이라면,
			cout << "Excellent !!" << endl;
			continue;
		}
		else if (user >= 0 && user < 4) {		//	2. 오답이라면,
			cout << "No. !!" << endl;
			continue;
		}
		else {									//	3. 번호 외 다른 입력(종료)		
			cout << endl;
			return;
		}
	}
}

void WordTest::run() {
	cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;
	while (true) {
		int menu = getMenu();
		switch (menu) {
			case 1:		// 어휘 삽입
				insertWord();
				break;
			case 2:		// 어휘 테스트
				makeQuest();
				break;
			default:	// 프로그램 종료
				return;
		}
	}
}

int main() {
	WordTest a;
	a.run();
	return 0;
}