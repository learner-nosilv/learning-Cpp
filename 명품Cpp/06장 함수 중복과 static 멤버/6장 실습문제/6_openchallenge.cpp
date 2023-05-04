/* 309p Openchallenge
	UP & Down 게임 프로그램 작성
	UpAndDownGame 클래스 : static 멤버로만 구성하라.
	Person 클래스 : 선수 추상화
	main() 함수 : 프로그램을 시작시키는 기능 정도로만 구현할 것

	정답은 random 정수로 구현하기
*/
#include <iostream>
#include <string>
#include <cstdlib>		// 랜덤정수 구현용
#include <ctime>		// 랜덤정수 구현용
using namespace std;	// C++ 표준 라이브러리의 네임스페이스

class Person {
	string name;
public:
	Person(string name) { this->name = name; }
	string getName() { return this->name; }
};

// 교재 지시사항에 static 멤버로만 구성하라 라고 되어있다.
// 그러나, 생성자(멤버함수)는 static일 수 없다.
// 그러므로, 모든 멤버변수를 static 으로 하라는 것으로 이해하겠음. 
class UpAndDownGame {
	static Person players[2];				// Declaration 선언: 컴파일러에게 존재만 알려줌(메모리X)
	static int key;							// Declaration 선언: 컴파일러에게 존재만 알려줌(메모리X)
	static int low, high;
public:
	UpAndDownGame();
};

// UpAndDownGame 클래스의 static 멤버변수 전역범위에서 Definition 정의 (메모리할당)
// 의아한 부분: 답이 28인 것을 27과 29사이라고 표현한다는 말은 0과 99사이 = 랜덤정수 [1-98] 
int UpAndDownGame::key = (rand() % 98) + 1;				// 1~98 랜덤정수
Person UpAndDownGame::players[2] = { Person("김인수"), Person("오은경") };
int UpAndDownGame::low = 0;		// Key범위 최소값인 1 - 1
int UpAndDownGame::high = 99;	// Key범위 최대값인 98 + 1

// Constructor
UpAndDownGame::UpAndDownGame() {
	cout << "Up & Down 게임을 시작합니다." << endl;
	int player_idx = 0;			// 현재 차례인 플레이어의 인덱스
	int answer = 0;
	while (true) {
		cout << "답은 " << low << "과 " << high << "사이에 있습니다." << endl;
		cout << (this->players[player_idx]).getName() << ">>";
		cin >> answer;
		if (answer == key) {
			cout << (this->players[player_idx]).getName() << "가 이겼습니다!!" << endl;
			break;
		}
		else if (answer > key && high > answer)
			high = answer;
		else if (low < answer)
			low = answer;
	}
}

int main() {
	srand((unsigned)time(NULL));
	UpAndDownGame round1;
	return 0;
}