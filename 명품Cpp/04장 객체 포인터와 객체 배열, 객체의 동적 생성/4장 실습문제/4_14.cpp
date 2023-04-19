/* 14.
* 두 사람이 참여하는 갬블링 게임
* 초기에 선수이름 입력받기
* 자신의 차례에서 엔터를 치면 [0-2] 중 랜덤한 3개의 수 생성
* 승리조건 : 랜덤한 3개의 수가 동일한 경우
* 
* 선수는 player클래스 & 2 객체 배열
* 게임은 GamblingGame 클래스
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
	string name;
public:
	int state[3];
	void setName(string name) { this->name = name; }
	string getName() { return name; }
};

class GamblingGame {
	Player gamer[2];
	int stage(int player);
public:
	GamblingGame() { srand((unsigned)time(NULL)); }		// 난수 패턴 생성
	void gameStart();
};

// 1판 : 특정 player의 1판을 진행하고 승패여부 리턴
int GamblingGame::stage(int player) {
	// 1) 자신의 차례에서 엔터 입력받기
	cout << gamer[player].getName() << ":<ENTER>";
	int enter = getchar();

	if (enter == '\n') {
		cout << "\t\t";

		for (int i = 0; i < 3; i++) {						// 난수 3개 생성
			gamer[player].state[i] = rand() % 3;
			cout << gamer[player].state[i] << '\t';			// 난수 3개 출력
		}

		if (gamer[player].state[0] == gamer[player].state[1] && gamer[player].state[1] == gamer[player].state[2]) {
			cout << gamer[player].getName() << "님 승리!!" << endl;	// 결과 출력
			return player;
		}
		else {
			cout << "아쉽군요!" << endl;
			return -1;
		}
	}
	else {
		cout << gamer[player].getName() << "님께서 게임을 종료하셨습니다." << endl;
		exit(1);
	}

}

// 전체게임 : winner이 나올 때까지 N판 진행
void GamblingGame::gameStart() {
	cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
	
	// 1. 초기에 선수이름 입력 받기
	string name;
	cout << "첫번째 선수 이름>>";
	getline(cin, name);
	gamer[0].setName(name);

	cout << "두번째 선수 이름>>";
	getline(cin, name);
	gamer[1].setName(name);

	// 2. 자신의 차례에서 엔터를 치면 수 생성 & 승리 결정
	int result = -1;					// 승자인덱스
	int player = 0;
	while (result == -1) {				// 반복: 탈출조건 승자가 나옴
		result = stage(player);
		player = (player + 1) % 2;
	}
}

int main() {
	GamblingGame game;
	game.gameStart();

	return 0;
}