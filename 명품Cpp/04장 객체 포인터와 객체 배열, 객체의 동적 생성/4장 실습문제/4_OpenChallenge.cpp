/*
* n���� �̸��� �Է¹ް�
* �����ձ� ����
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
	int people;								// ��ü �÷��̾� ��
	Player* every;							// �÷��̾� ��ü �迭�� �����Ҵ�
	int past = 0;					// ���������� ��ü�� �ε���
	int now = 0;							// ���� ��ü�� �ε���
public:
	// ������: ���Ӽ���
	WordGame() {
		cout << "���� �ձ� ������ �����մϴ�" << endl;
		cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�?";
		int people;							// �ο� ��
		cin >> people;
		this->people = people;				// ������� people�� �Ҵ�
		this->past = people-1;
		every = new Player[people];

		for (int i = 0; i < people; i++) {	// �̸� �Է¹ޱ�
			cout << "�������� �̸��� �Է��ϼ���. ��ĭ����>>";
			string name;
			cin >> name;
			(every + i)->setName(name);		// Player��ü�迭���� �� ��ü�� �������name�� �̸��Ҵ�  
		}
		(every + past)->setWord("�ƹ���");	// ���۴ܾ�: �ƹ���
		cout << "�����ϴ� �ܾ�� �ƹ����Դϴ�." << endl;
		Start();							// ���� ����
	}
	
	//void setName(int i, string name) {	// WordGame�� ���� Player ��ü�� �� i��° ��ü�� �̸��Ҵ�
	//	(every + i)->setName(name);
	//}
	//void setWord(int i, string word) {	// WordGame�� ���� Player ��ü�� �� i��° ��ü�� �ܾ��Ҵ�
	//	(every + i)->setWord(word);
	//}
	//string getName(int i) {	// WordGame�� ���� Player ��ü�� �� i��° ��ü�� �̸�����
	//	return (every + i)->getName();
	//}
	//string getWord(int i) {	// WordGame�� ���� Player ��ü�� �� i��° ��ü�� �ܾ��
	//	return (every + i)->getWord();
	//}

	void Start() {
		string temp_word;	// ���� �ܾ�
		string past_word;	// ���� �ܾ�
		int past_size;		// ���� �ܾ��� 
		while (1) {
			// ���� �÷��̾�� �ܾ� �Է¹ޱ�
			
			past_word = (every+past)->getWord();
			past_size = past_word.size();

			cout << (every+now)->getName() << ">>";
			cin >> temp_word;
			(every + now)->setWord(temp_word);

			// �Է¹��� �ܾ� ���� ( WordGame �ȿ��� Player ��ü�� �����ߴ��ص� WordGame���� Player Ŭ������ private ������� ������ �Ұ���! )
			if (past_word[past_size-2] == temp_word[0] && past_word[past_size-1] == temp_word[1]) {
				past = now;
				now = (now + 1) % 3;
				continue;
			}
			else {
				cout << (every+now)->getName() << "���� �й�" << endl;
				cout << "~~������ �����մϴ�~~" << endl;
				break;
			}
		}
	}

};

int main() {
	int token = 1;
	while (token == 1) {
		WordGame();
		cout << "�ٽ� �ϰ� ������ 1�� �Է��ϼ���>> ";
		cin >> token;
	}
	return 0;
}