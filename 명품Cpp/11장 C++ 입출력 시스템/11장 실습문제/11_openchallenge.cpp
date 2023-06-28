/* 577p. openchallenge
*	����� ��ǻ�Ͱ� �����������ϴ� ���α׷�
*	��Ʈ�� �䱸�������� �����ϱ�
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
		gbb[0] = "����";
		gbb[1] = "����";
		gbb[2] = "��";
		this->name = name;
	}
	virtual string turn() = 0;	// ����, ����, �� �� �ϳ� ���
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
		if (hand == "����" || hand == "����" || hand == "��" || hand == "exit") return hand;
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
		cout << "***** ��ǻ�Ϳ� ����� ���� ���� �� ����� ��Ĩ�ϴ�. *****" << endl;
		string name;
		while (true) {
			cout << "���� �̸��� �Է��ϼ���(�ѱ�4��, ����8���� �̳�)>>";
			getline(cin, name, '\n');		// delimeter�� ���ۿ��� �а� ����
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
		else if ((hum == "����" && com == "��") || (hum == "����" && com == "����") || (hum == "��" && com == "����")) return 2;
		else return 3;
	}
	void run() {
		while (true) {
			int gameResult = result(com->turn(), hum->turn());
			switch (gameResult) {
				case 0:
					cout << "- The End -\n";
					return;
				case 1: 	// ���
					cout << "the same\n";
					break;
				case 2:		// human �¸�
					cout << hum->getName() << " is winner.\n"; break;
				case 3:		// com �¸�
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