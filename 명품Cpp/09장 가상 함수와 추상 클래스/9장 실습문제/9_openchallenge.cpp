/*458p OpenChallenge
* 게임 룰: 세 종류(인간/몬스터/음식) → 클래스로 구현
*	인간: 사용자입력으로 1칸씩 움직임
*	몬스터: 랜덤으로 2칸씩 움직임
*	음식: 5 중 3번째까지는 정지, 끝 2회만 랜덤으로 1칸씩 움직임
* 
*	성공조건: 인간이 몬스터를 피해서 음식섭취
*	실패조건: 몬스터가 인간을 잡거나 몬스터가 음식을 섭취하는 경우
*		* 음식섭취 : 같은 자리가 되는 경우
* 클래스 구상
* GameObject: 모양과 움직임, 현위치, 위치비교가 순수가상함수로 존재 → Human/Monster/Food가 상속받아서 각자의 모양과 움직임 구현
* Game: 전체적인 게임 진행
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GameObject {
protected:
	int distance;					// 1회 이동거리
	int x, y;						// 현 위치
public:
	GameObject(int startX, int startY, int distance) {	// 생성자: 초기위치와 이동거리 설정
		this->x = startX;	this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {};		// Base가 될 수 있는 클래스는 소멸자를 가상소멸자로 해줄 것
	virtual void move() = 0;		// 움직임 : pure virtual function
	virtual char getShape() = 0;	// 모양 : pure virtual function

	int getX() { return this->x; }	//
	int getY() { return this->y; }	//
	bool collide(GameObject* p) {	// p가 가리키는 객체와의 충돌여부 (충돌시 true)
		if ((this->x == p->x) && (this->y == p->y)) return true;	// [TRUE] 좌표 x, y가 모두 같을 때
		else return false;
	}
};

class Human : public GameObject {
public:
	Human(int startX, int startY, int distance) : GameObject(startX, startY, distance) { }
	char getDirection();					// 방향 문자를 입력받고 검증하여 리턴하는 함수 구현
	virtual void move();					// 움직임:	사람의 움직임(1턴 당 사용자 입력으로 1칸) [OVERRIDING]
	virtual char getShape() { return 'H'; }	// 모양:		사람의 모양(H) [OVERRIDING]
};
char Human::getDirection() {			// 방향 문자를 입력받고 검증하여 리턴하는 함수 구현
	char direction;
	while (true) {
		cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
		cin >> direction;
		if (direction == 'a' || direction == 's' || direction == 'd' || direction == 'f') return direction;
		if (direction == ' ') {
			cout << "[ERROR] No Spacebar : 바른 값을 입력해주세요. " << endl;
			cin.ignore(99, '\n');
		}
		else cout << "[ERROR] Only a, s, d, f : 바른 값을 입력해주세요 " << endl;
	}
}
void Human::move() {						// 움직임:	사람의 움직임(1턴 당 사용자 입력으로 1칸) [OVERRIDING]				
	char direction = getDirection();		// 방향 입력받기
	switch (direction) {		// 방향에 따라
		case 'a':				// 좌
			x--;
			if (x < 0) x = 19;	// 가로범위 [0-19] 
			break;
		case 's':				// 하
			y++;
			if (y > 9) y = 0;	// 세로범위 [0-9] 
			break;
		case 'd':				// 상
			y--;
			if (y < 0) y = 9;	// 세로범위 [0-9] 
			break;
		case 'f':				// 우
			x++;
			if (x > 19) x = 0;	// 가로범위 [0-19] 
			break;
	}
}

class Monster : public GameObject {
public:
	Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance) { }
	virtual void move();						// 움직임 : pure virtual function 구현
	virtual char getShape() { return 'M'; }		// 모양 : pure virtual function 구현
};
void Monster::move() {				// 움직임:	몬스터의 움직임(1턴 당 랜덤으로 2칸) [OVERRIDING]				
	int direction = rand() % 4;		// 방향 입력받기
	switch (direction) {			// 방향에 따라
		case 0:						// 좌
			x -= 2;
			if (x < 0) x += 20;		// 가로범위 [0-19] 
			break;
		case 1:						// 하
			y += 2;
			if (y > 9) y -= 10;		// 세로범위 [0-9] 
			break;
		case 2:						// 상
			y -= 2;
			if (y < 0) y += 10;		// 세로범위 [0-9] 
			break;
		case 3:						// 우
			x += 2;
			if (x > 19) x -= 20;	// 가로범위 [0-19] 
			break;
	}
}

class Food : public GameObject {
	int turn;
public:
	Food(int startX, int startY, int distance)
		:GameObject(startX, startY, distance) { this->turn = 0;}
	virtual void move();						// 움직임 : pure virtual function 구현
	virtual char getShape() { return '@'; }		// 모양 : pure virtual function 구현
};
void Food::move() {					// 움직임:	음식의 움직임(5턴 중 뒤 2턴만 랜덤으로 1칸 움직임) [OVERRIDING]	
	if (turn >= 0 && turn < 3) {
		turn++;
		return;
	}
	int direction = rand() % 4;		// 방향 입력받기
	switch (direction) {		// 방향에 따라
		case 0:					// 좌
			x--;
			if (x < 0) x = 19;	// 가로범위 [0-19] 
			break;
		case 1:					// 하
			y++;
			if (y > 9) y = 0;	// 세로범위 [0-9] 
			break;
		case 2:					// 상
			y--;
			if (y < 0) y = 9;	// 세로범위 [0-9] 
			break;
		case 3:					// 우
			x++;
			if (x > 19) x = 0;	// 가로범위 [0-19] 
			break;
	}
	turn++;
	if (turn > 4) turn = 0;
}

class Game {
	GameObject* objectHMF[3];	// 포인터 배열
public:
	Game();
	~Game() { for (int i = 0; i < 3; i++) delete objectHMF[i]; }
	void showMap();
	void start();
};
Game::Game() {								// 인간, 몬스터, 음식의 위치 세팅
	srand((unsigned)time(NULL));			// 인간, 몬스터는 각자 음식과 3칸이상 떨어져 있어야 한다
	int a = rand() % 20;
	int b = rand() % 10;
	objectHMF[1] = new Human(a, b, 1);				// 인간의 위치

	int c = -1;
	int d = -1;
	while (true) {
		c = rand() % 20;
		d = rand() % 10;
		if (a != c && b != d) break;
	}
	objectHMF[2] = new Monster(c, d, 2);			// 몬스터의 위치

	int e, f;
	while (true) {
		e = rand() % 20;
		f = rand() % 10;
		int gapX = a - e;
		if (gapX < 0) gapX *= -1;
		int gapY = b - f;
		if (gapY < 0) gapY *= -1;
		int distance = gapX + gapY;
		if ((c != e && d != f) && (distance > 3))	// 몬스터와는 같으면 안 됨, 사람과는 4칸이상차이나야함
			break;
	}
	objectHMF[0] = new Food(e, f, 1);						// 음식의 위치
}
void Game::showMap() {
	for (int i = 0; i < 10; i++) {			// 행
		for (int j = 0; j < 20; j++) {		// 열
			cout << '-';
			for (int o = 0; o < 3; o++) {	// 덮어씌워지는 우선순위: 빵[0] > 인간[1] > 몬스터[2]
				if (objectHMF[o]->getY() == i && objectHMF[o]->getX() == j) {
					cout << '\b';
					cout << objectHMF[o]->getShape();
				}
			}
		}
		cout << '\n';
	}
}
void Game::start() {
	cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl;
	while (true) {
		showMap();
		if (objectHMF[1]->collide(objectHMF[0])) {
			cout << "Human is Winner!!" << endl;
			break;
		}
		else if (objectHMF[1]->collide(objectHMF[2]) || objectHMF[0]->collide(objectHMF[2])) {
			cout << "Monster is Winner!!" << endl;
			break;
		}
		for (int i = 0; i < 3; i++) objectHMF[i]->move();
	}
	

	return;
}

int main() {
	Game first;
	first.start();

	return 0;
}