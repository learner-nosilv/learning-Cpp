/* 577p. openchallenge
*	사람과 컴퓨터가 가위바위보하는 프로그램
*	힌트를 요구사항으로 설정하기
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class AbstractPlayer {
	string name;
protected:
	string gbb[3];
public:
	AbstractPlayer(string name = "No named") {
		gbb[0] = "가위";
		gbb[1] = "바위";
		gbb[2] = "보";
		this->name = name;
	}
	virtual string turn() = 0;	// 가위, 바위, 보 중 하나 출력
	string getName() { return this->name; }
};

class Human : public AbstractPlayer {
public:
	Human(string name = "No named") : AbstractPlayer(name) {}
	virtual string turn();
};
string Human::turn() {
	string hand;
	while (true) {
		cout << this->getName() << ">>";
		getline(cin, hand, '\n');
		if (hand == "가위" || hand == "바위" || hand == "보" || hand == "exit") return hand;
	}
}

class Computer : public AbstractPlayer {
public:
	Computer() :AbstractPlayer("Computer") {}
	virtual string turn();
};
string Computer::turn() {
	int hand = rand() % 3;
	string handStr = gbb[hand];
	cout << this->getName() << ": " << handStr << endl;
	return handStr;
}

class ggbGame {
	Computer* com;
	Human* hum;
public:
	ggbGame() {
		srand((unsigned)(time(NULL)));
		cout << "***** 컴퓨터와 사람이 가위 바위 보 대결을 펼칩니다. *****" << endl;
		string name;
		while (true) {
			cout << "선수 이름을 입력하세요(한글4자, 영어8글자 이내)>>";
			getline(cin, name, '\n');		// delimeter도 버퍼에서 읽고 버림
			if (cin.gcount() < 10) {
				hum = new Human(name);
				break;
			}
		}
		com = new Computer();
	}
	int result(string com, string hum) {
		if (hum == "exit") return 0;
		else if (hum == com) return 1;
		else if ((hum == "가위" && com == "보") || (hum == "바위" && com == "가위") || (hum == "보" && com == "바위")) return 2;
		else return 3;
	}
	void run() {
		while (true) {
			int gameResult = result(com->turn(), hum->turn());
			switch (gameResult) {
				case 0:
					cout << "- The End -\n";
					return;
				case 1: 	// 비김
					cout << "the same\n";
					break;
				case 2:		// human 승리
					cout << hum->getName() << " is winner.\n"; break;
				case 3:		// com 승리
					cout << com->getName() << " is winner.\n"; break;
			}
		}
	}
};

int main() {
	ggbGame mark1;
	mark1.run();
	return 0;
}