/*
* n명의 이름을 입력받고
* 끝말잇기 진행
*/

#include <iostream>
#include <string>
using namespace std;

class Player {
	string name;
	string word;
public:
	Player(string name= "NONAMED", string word="\0") {
		this->name = name;
		this->word = word;
	}
	void setName(string name) {
		this->name = name;
	}
	void setWord(string word) {
		this->word= word;
	}
	string getName() {
		return this->name;
	}
	string getWord() {
		return this->word;
	}
};

class WordGame {
	int people;								// 전체 플레이어 수
	Player* every;							// 플레이어 객체 배열로 동적할당
	int past = 0;					// 이전순번인 객체의 인덱스
	int now = 0;							// 현재 객체의 인덱스
public:
	// 생성자: 게임세팅
	WordGame() {
		cout << "끝말 잇기 게임을 시작합니다" << endl;
		cout << "게임에 참가하는 인원은 몇명입니까?";
		int people;							// 인원 수
		cin >> people;
		this->people = people;				// 멤버변수 people에 할당
		this->past = people-1;
		every = new Player[people];

		for (int i = 0; i < people; i++) {	// 이름 입력받기
			cout << "참가자의 이름을 입력하세요. 빈칸없이>>";
			string name;
			cin >> name;
			(every + i)->setName(name);		// Player객체배열에서 각 객체의 멤버변수name에 이름할당  
		}
		(every + past)->setWord("아버지");	// 시작단어: 아버지
		cout << "시작하는 단어는 아버지입니다." << endl;
		Start();							// 게임 시작
	}
	
	//void setName(int i, string name) {	// WordGame에 속한 Player 객체들 중 i번째 객체의 이름할당
	//	(every + i)->setName(name);
	//}
	//void setWord(int i, string word) {	// WordGame에 속한 Player 객체들 중 i번째 객체의 단어할당
	//	(every + i)->setWord(word);
	//}
	//string getName(int i) {	// WordGame에 속한 Player 객체들 중 i번째 객체의 이름리턴
	//	return (every + i)->getName();
	//}
	//string getWord(int i) {	// WordGame에 속한 Player 객체들 중 i번째 객체의 단어리턴
	//	return (every + i)->getWord();
	//}

	void Start() {
		string temp_word;	// 현재 단어
		string past_word;	// 이전 단어
		int past_size;		// 이전 단어의 
		while (1) {
			// 현재 플레이어에게 단어 입력받기
			
			past_word = (every+past)->getWord();
			past_size = past_word.size();

			cout << (every+now)->getName() << ">>";
			cin >> temp_word;
			(every + now)->setWord(temp_word);

			// 입력받은 단어 검증 ( WordGame 안에서 Player 객체를 생성했다해도 WordGame에서 Player 클래스의 private 멤버에는 접근이 불가함! )
			if (past_word[past_size-2] == temp_word[0] && past_word[past_size-1] == temp_word[1]) {
				past = now;
				now = (now + 1) % 3;
				continue;
			}
			else {
				cout << (every+now)->getName() << "선수 패배" << endl;
				cout << "~~게임을 종료합니다~~" << endl;
				break;
			}
		}
	}

};

int main() {
	int token = 1;
	while (token == 1) {
		WordGame();
		cout << "다시 하고 싶으면 1을 입력하세요>> ";
		cin >> token;
	}
	return 0;
}