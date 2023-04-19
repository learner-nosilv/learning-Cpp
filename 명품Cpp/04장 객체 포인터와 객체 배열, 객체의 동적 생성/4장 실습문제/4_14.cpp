/* 14.
* �� ����� �����ϴ� ���� ����
* �ʱ⿡ �����̸� �Է¹ޱ�
* �ڽ��� ���ʿ��� ���͸� ġ�� [0-2] �� ������ 3���� �� ����
* �¸����� : ������ 3���� ���� ������ ���
* 
* ������ playerŬ���� & 2 ��ü �迭
* ������ GamblingGame Ŭ����
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
	GamblingGame() { srand((unsigned)time(NULL)); }		// ���� ���� ����
	void gameStart();
};

// 1�� : Ư�� player�� 1���� �����ϰ� ���п��� ����
int GamblingGame::stage(int player) {
	// 1) �ڽ��� ���ʿ��� ���� �Է¹ޱ�
	cout << gamer[player].getName() << ":<ENTER>";
	int enter = getchar();

	if (enter == '\n') {
		cout << "\t\t";

		for (int i = 0; i < 3; i++) {						// ���� 3�� ����
			gamer[player].state[i] = rand() % 3;
			cout << gamer[player].state[i] << '\t';			// ���� 3�� ���
		}

		if (gamer[player].state[0] == gamer[player].state[1] && gamer[player].state[1] == gamer[player].state[2]) {
			cout << gamer[player].getName() << "�� �¸�!!" << endl;	// ��� ���
			return player;
		}
		else {
			cout << "�ƽ�����!" << endl;
			return -1;
		}
	}
	else {
		cout << gamer[player].getName() << "�Բ��� ������ �����ϼ̽��ϴ�." << endl;
		exit(1);
	}

}

// ��ü���� : winner�� ���� ������ N�� ����
void GamblingGame::gameStart() {
	cout << "***** ���� ������ �����մϴ�. *****" << endl;
	
	// 1. �ʱ⿡ �����̸� �Է� �ޱ�
	string name;
	cout << "ù��° ���� �̸�>>";
	getline(cin, name);
	gamer[0].setName(name);

	cout << "�ι�° ���� �̸�>>";
	getline(cin, name);
	gamer[1].setName(name);

	// 2. �ڽ��� ���ʿ��� ���͸� ġ�� �� ���� & �¸� ����
	int result = -1;					// �����ε���
	int player = 0;
	while (result == -1) {				// �ݺ�: Ż������ ���ڰ� ����
		result = stage(player);
		player = (player + 1) % 2;
	}
}

int main() {
	GamblingGame game;
	game.gameStart();

	return 0;
}