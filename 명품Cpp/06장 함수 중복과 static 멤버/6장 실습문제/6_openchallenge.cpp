/* 309p Openchallenge
	UP & Down ���� ���α׷� �ۼ�
	UpAndDownGame Ŭ���� : static ����θ� �����϶�.
	Person Ŭ���� : ���� �߻�ȭ
	main() �Լ� : ���α׷��� ���۽�Ű�� ��� �����θ� ������ ��

	������ random ������ �����ϱ�
*/
#include <iostream>
#include <string>
#include <cstdlib>		// �������� ������
#include <ctime>		// �������� ������
using namespace std;	// C++ ǥ�� ���̺귯���� ���ӽ����̽�

class Person {
	string name;
public:
	Person(string name) { this->name = name; }
	string getName() { return this->name; }
};

// ���� ���û��׿� static ����θ� �����϶� ��� �Ǿ��ִ�.
// �׷���, ������(����Լ�)�� static�� �� ����.
// �׷��Ƿ�, ��� ��������� static ���� �϶�� ������ �����ϰ���. 
class UpAndDownGame {
	static Person players[2];				// Declaration ����: �����Ϸ����� ���縸 �˷���(�޸�X)
	static int key;							// Declaration ����: �����Ϸ����� ���縸 �˷���(�޸�X)
	static int low, high;
public:
	UpAndDownGame();
};

// UpAndDownGame Ŭ������ static ������� ������������ Definition ���� (�޸��Ҵ�)
// �Ǿ��� �κ�: ���� 28�� ���� 27�� 29���̶�� ǥ���Ѵٴ� ���� 0�� 99���� = �������� [1-98] 
int UpAndDownGame::key = (rand() % 98) + 1;				// 1~98 ��������
Person UpAndDownGame::players[2] = { Person("���μ�"), Person("������") };
int UpAndDownGame::low = 0;		// Key���� �ּҰ��� 1 - 1
int UpAndDownGame::high = 99;	// Key���� �ִ밪�� 98 + 1

// Constructor
UpAndDownGame::UpAndDownGame() {
	cout << "Up & Down ������ �����մϴ�." << endl;
	int player_idx = 0;			// ���� ������ �÷��̾��� �ε���
	int answer = 0;
	while (true) {
		cout << "���� " << low << "�� " << high << "���̿� �ֽ��ϴ�." << endl;
		cout << (this->players[player_idx]).getName() << ">>";
		cin >> answer;
		if (answer == key) {
			cout << (this->players[player_idx]).getName() << "�� �̰���ϴ�!!" << endl;
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