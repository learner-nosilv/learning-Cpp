/* 10.	STL�� vector Ŭ������ �̿��Ͽ� ���� ���� ���߱� ���Ӹ����
*	�����̸�nation�� ����capital ���ڿ��� ������ Nation Ŭ����
*	Nation Ŭ������ ��ü�� ���ҷ� �ϴ� vetcor v �����ϱ�
*	���ӱ�� 1. �����Է�, 2. ����, 3. ����
*/
#include <iostream>
#include <string>
#include <vector>		// Standard Template Library
#include <cstdlib>		// to make random integer
#include <ctime>		// to make random integer
using namespace std;

class Nation {
	string nation;
	string capital;
public:
	Nation(string nation = "", string capital = "") { this->nation = nation; this->capital = capital; }
	string getNation() { return this->nation; }
	string getCapital() { return this->capital; }
};

class NationGame {
	vector<Nation> v;
	int getMenu();
	void setNation();
	void doQuiz();
public:
	NationGame() {
		v.push_back(Nation("���ѹα�", "����"));
		v.push_back(Nation("�׸���", "���׳�"));
		v.push_back(Nation("����", "īƮ����"));
		v.push_back(Nation("�븣����", "������"));
		v.push_back(Nation("����ũ", "�����ϰ�"));
		v.push_back(Nation("����θ�ũ", "����θ�ũ"));
		v.push_back(Nation("����", "����"));
		v.push_back(Nation("��Ʈ��", "�ϳ���"));
		v.push_back(Nation("�̶�ũ", "�ٱ״ٵ�"));
	}
	~NationGame() {}
	void run();
};
int NationGame::getMenu() {
	int answer;
	while (true) {
		cout << "���� �Է�: 1, ����: 2, ����: 3 >> ";
		cin >> answer;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(10, '\n');
			cout << "[����] 1, 2, 3 �� �ϳ��� �Է��Ͽ��� �մϴ�.\n";
			continue;
		}
		else if (answer != 1 && answer != 2 && answer != 3) {
			cout << "[����] 1, 2, 3 �� �ϳ��� �Է��Ͽ��� �մϴ�.\n";
			continue;
		}
		else
			return answer;
	}
}
void NationGame::setNation() {
	cout << "���� " << v.size() << "���� ���� �ԷµǾ� �ֽ��ϴ�.\n";
	cout << "����� ������ �Է��ϼ���(no no �̸� �Է³�)\n";
	while (true) {
		string nat = "", cap = "";				// ����� ������ �Է¹��� ����
		bool isExist = false;					// �̹� �����ϴ��� ���θ� ���� ����

		cout << v.size() + 1 << ">>";			// �Է¹ޱ�
		cin >> nat >> cap;

		if (nat == "no" && cap == "no") return;	// [���� Ż������] �Է� ����
		for (int i = 0; i < v.size(); i++) {	// ������ ���� �����迭�� �̹� �ִ��� �˻�
			if (v[i].getNation() == nat) {		//	�̹� �����Ѵٸ�
				cout << "already exists !!\n";	//	�̹� �������� �˸���
				isExist = true;					//	�οﺯ���� �ݿ� ��
				break;							//	���� �ﰢ Ż��
			}
		}
		if (isExist == false)						// ������ ���� ���ٸ�
			v.push_back(Nation(nat, cap));	// �Է¹ݿ�
	}
}
void NationGame::doQuiz() {
	while (true) {
		int idx = rand() % (v.size());			// ��� �� ������ �ε��� ����
		string answer = "";
		cout << v[idx].getNation() << "�� ������?(exit �̸� ���)";
		while (true) {
			cin >> answer;
			if (cin.fail()) {
				cout << "[����] ���� ����\n";
				cin.clear();
				cin.ignore(99, '\n');
			}
			break;
		}
		if (answer == "exit") return;				// [���� Ż������]
		else if (answer == v[idx].getCapital())
			cout << "Correct !!\n";
		else
			cout << "NO !!\n";
	}
}
void NationGame::run() {
	srand((unsigned)time(NULL));
	cout << "***** ������ ���� ���߱� ������ �����մϴ�. *****\n";
	while (true) {
		int answer = getMenu();
		switch (answer) {
			case 1:
				setNation();
				break;
			case 2:
				doQuiz();
				break;
			case 3:
				return;
		}
	}
}

int main() {
	NationGame first;
	first.run();

	return 0;
}