/*458p OpenChallenge
* ���� ��: �� ����(�ΰ�/����/����) �� Ŭ������ ����
*	�ΰ�: ������Է����� 1ĭ�� ������
*	����: �������� 2ĭ�� ������
*	����: 5 �� 3��°������ ����, �� 2ȸ�� �������� 1ĭ�� ������
* 
*	��������: �ΰ��� ���͸� ���ؼ� ���ļ���
*	��������: ���Ͱ� �ΰ��� ��ų� ���Ͱ� ������ �����ϴ� ���
*		* ���ļ��� : ���� �ڸ��� �Ǵ� ���
* Ŭ���� ����
* GameObject: ���� ������, ����ġ, ��ġ�񱳰� ���������Լ��� ���� �� Human/Monster/Food�� ��ӹ޾Ƽ� ������ ���� ������ ����
* Game: ��ü���� ���� ����
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GameObject {
protected:
	int distance;					// 1ȸ �̵��Ÿ�
	int x, y;						// �� ��ġ
public:
	GameObject(int startX, int startY, int distance) {	// ������: �ʱ���ġ�� �̵��Ÿ� ����
		this->x = startX;	this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {};		// Base�� �� �� �ִ� Ŭ������ �Ҹ��ڸ� ����Ҹ��ڷ� ���� ��
	virtual void move() = 0;		// ������ : pure virtual function
	virtual char getShape() = 0;	// ��� : pure virtual function

	int getX() { return this->x; }	//
	int getY() { return this->y; }	//
	bool collide(GameObject* p) {	// p�� ����Ű�� ��ü���� �浹���� (�浹�� true)
		if ((this->x == p->x) && (this->y == p->y)) return true;	// [TRUE] ��ǥ x, y�� ��� ���� ��
		else return false;
	}
};

class Human : public GameObject {
public:
	Human(int startX, int startY, int distance) : GameObject(startX, startY, distance) { }
	char getDirection();					// ���� ���ڸ� �Է¹ް� �����Ͽ� �����ϴ� �Լ� ����
	virtual void move();					// ������:	����� ������(1�� �� ����� �Է����� 1ĭ) [OVERRIDING]
	virtual char getShape() { return 'H'; }	// ���:		����� ���(H) [OVERRIDING]
};
char Human::getDirection() {			// ���� ���ڸ� �Է¹ް� �����Ͽ� �����ϴ� �Լ� ����
	char direction;
	while (true) {
		cout << "����(a), �Ʒ�(s), ��(d), ������(f) >> ";
		cin >> direction;
		if (direction == 'a' || direction == 's' || direction == 'd' || direction == 'f') return direction;
		if (direction == ' ') {
			cout << "[ERROR] No Spacebar : �ٸ� ���� �Է����ּ���. " << endl;
			cin.ignore(99, '\n');
		}
		else cout << "[ERROR] Only a, s, d, f : �ٸ� ���� �Է����ּ��� " << endl;
	}
}
void Human::move() {						// ������:	����� ������(1�� �� ����� �Է����� 1ĭ) [OVERRIDING]				
	char direction = getDirection();		// ���� �Է¹ޱ�
	switch (direction) {		// ���⿡ ����
		case 'a':				// ��
			x--;
			if (x < 0) x = 19;	// ���ι��� [0-19] 
			break;
		case 's':				// ��
			y++;
			if (y > 9) y = 0;	// ���ι��� [0-9] 
			break;
		case 'd':				// ��
			y--;
			if (y < 0) y = 9;	// ���ι��� [0-9] 
			break;
		case 'f':				// ��
			x++;
			if (x > 19) x = 0;	// ���ι��� [0-19] 
			break;
	}
}

class Monster : public GameObject {
public:
	Monster(int startX, int startY, int distance) : GameObject(startX, startY, distance) { }
	virtual void move();						// ������ : pure virtual function ����
	virtual char getShape() { return 'M'; }		// ��� : pure virtual function ����
};
void Monster::move() {				// ������:	������ ������(1�� �� �������� 2ĭ) [OVERRIDING]				
	int direction = rand() % 4;		// ���� �Է¹ޱ�
	switch (direction) {			// ���⿡ ����
		case 0:						// ��
			x -= 2;
			if (x < 0) x += 20;		// ���ι��� [0-19] 
			break;
		case 1:						// ��
			y += 2;
			if (y > 9) y -= 10;		// ���ι��� [0-9] 
			break;
		case 2:						// ��
			y -= 2;
			if (y < 0) y += 10;		// ���ι��� [0-9] 
			break;
		case 3:						// ��
			x += 2;
			if (x > 19) x -= 20;	// ���ι��� [0-19] 
			break;
	}
}

class Food : public GameObject {
	int turn;
public:
	Food(int startX, int startY, int distance)
		:GameObject(startX, startY, distance) { this->turn = 0;}
	virtual void move();						// ������ : pure virtual function ����
	virtual char getShape() { return '@'; }		// ��� : pure virtual function ����
};
void Food::move() {					// ������:	������ ������(5�� �� �� 2�ϸ� �������� 1ĭ ������) [OVERRIDING]	
	if (turn >= 0 && turn < 3) {
		turn++;
		return;
	}
	int direction = rand() % 4;		// ���� �Է¹ޱ�
	switch (direction) {		// ���⿡ ����
		case 0:					// ��
			x--;
			if (x < 0) x = 19;	// ���ι��� [0-19] 
			break;
		case 1:					// ��
			y++;
			if (y > 9) y = 0;	// ���ι��� [0-9] 
			break;
		case 2:					// ��
			y--;
			if (y < 0) y = 9;	// ���ι��� [0-9] 
			break;
		case 3:					// ��
			x++;
			if (x > 19) x = 0;	// ���ι��� [0-19] 
			break;
	}
	turn++;
	if (turn > 4) turn = 0;
}

class Game {
	GameObject* objectHMF[3];	// ������ �迭
public:
	Game();
	~Game() { for (int i = 0; i < 3; i++) delete objectHMF[i]; }
	void showMap();
	void start();
};
Game::Game() {								// �ΰ�, ����, ������ ��ġ ����
	srand((unsigned)time(NULL));			// �ΰ�, ���ʹ� ���� ���İ� 3ĭ�̻� ������ �־�� �Ѵ�
	int a = rand() % 20;
	int b = rand() % 10;
	objectHMF[1] = new Human(a, b, 1);				// �ΰ��� ��ġ

	int c = -1;
	int d = -1;
	while (true) {
		c = rand() % 20;
		d = rand() % 10;
		if (a != c && b != d) break;
	}
	objectHMF[2] = new Monster(c, d, 2);			// ������ ��ġ

	int e, f;
	while (true) {
		e = rand() % 20;
		f = rand() % 10;
		int gapX = a - e;
		if (gapX < 0) gapX *= -1;
		int gapY = b - f;
		if (gapY < 0) gapY *= -1;
		int distance = gapX + gapY;
		if ((c != e && d != f) && (distance > 3))	// ���Ϳʹ� ������ �� ��, ������� 4ĭ�̻����̳�����
			break;
	}
	objectHMF[0] = new Food(e, f, 1);						// ������ ��ġ
}
void Game::showMap() {
	for (int i = 0; i < 10; i++) {			// ��
		for (int j = 0; j < 20; j++) {		// ��
			cout << '-';
			for (int o = 0; o < 3; o++) {	// ��������� �켱����: ��[0] > �ΰ�[1] > ����[2]
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
	cout << "** Human�� Food �Ա� ������ �����մϴ�. **" << endl;
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