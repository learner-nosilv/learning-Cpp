/* 12. 10�� Open Challenge: ���� ���� �׽�Ʈ �ۼ���
	����ڰ� ���ָ� ������ �� �ֵ��� ����߰�
	class Word: string �ѱ�/����
	vector<Word> v�� �����迭�� �̿��Ͽ�
	�Ʒ��� ���� �׽�Ʈ ���α׷� �ۼ��ϱ�
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Word {
	string eng;
	string kor;
public:
	Word(string eng = "", string kor = "") { this->eng = eng; this->kor = kor; }
	string getEng() { return this->eng; }
	string getKor() { return this->kor; }
};

class WordTest {
	vector<Word> v;		// ��� �ܾ���� ����� �����迭
	int idxBox[4];		// �����迭�� ���� �� ������ ���� 4�ܾ�
	int answer;			// ���� �� �� ��ȣ
public:
	WordTest() {		// ���� �ܾ� 10��
		srand((unsigned)time(NULL));
		v.push_back(Word("human", "�ΰ�"));		// 0
		v.push_back(Word("society", "��ȸ"));	// 1
		v.push_back(Word("doll", "����"));		// 2
		v.push_back(Word("emotion", "����"));	// 3
		v.push_back(Word("painting", "�׸�"));	// 4
		v.push_back(Word("trade", "�ŷ�"));		// 5
		v.push_back(Word("love", "���"));		// 6
		v.push_back(Word("happyness", "�ູ"));	// 7
		v.push_back(Word("sincerity", "����"));	// 8
		v.push_back(Word("diligence", "�ٸ�"));	// 9
	}
	int getMenu() {			// ���α׷� �޴� �Է¹ޱ�
		int menu;
		cout << "���� ����: 1, ���� �׽�Ʈ: 2, ���α׷� ����: �׿�Ű >> ";
		cin >> menu;
		return menu;
	}
	void insertWord();		// �ܾ� ����
	int ask() {				// ���� �Է�
		int answer;
		cout << ":>";
		cin >> answer;
		return answer - 1;
	}
	void makeQuest();		// �����׽�Ʈ
	void run();				// ���α׷� ����
};

void WordTest::insertWord() {
	string eng, kor; 
	cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��\n";
	while (true) {
		cout << "���� >>";
		cin >> eng;
		if (eng == "exit") {		// ���ѷ��� Ż������
			cout << endl;
			return;
		}
		for (int i = 0; i < v.size(); i++) {
			if (eng == v[i].getEng()) {
				cout << "�̹� �ִ� �ܾ� �Դϴ�.\n";
				eng = "";
				break;
			}
		}
		if (eng == "") continue;		// �̹� �ִ� �ܾ��� ���, �ٽ� �Է¹ޱ�
		cout << "�ѱ� >>";				// �������� ��� �ѱ۵� �Է¹ޱ�
		cin >> kor;
		v.push_back(Word(eng, kor));
	}
}

void WordTest::makeQuest() {
	cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� ����.\n";
	while (true) {
		//  1. ������ �� �ܾ� 4����, ���伱��
		for (int i = 0; i < 4; i++) {				// (10C4) 0-9 ������ ���� �� �ߺ����� 4�� ����
			this->idxBox[i] = rand() % 10;			//	idxBox�� �� ���ҿ� �ܾ��
			for (int j = 0; j < i; j++) {			//	��� ������ �ܾ� vs ���� ���ҵ�
				if (this->idxBox[i] == this->idxBox[j]) {	//	��� ������ �ܾ ���� ���ҿ� �ߺ��Ǿ��ٸ�,
					this->idxBox[i] = rand() % 10;	//	�� ����
					j--;
					continue;						//	�� �˻�
				}
			}
		}											// ������ �� �ܾ� 4�� �����Ϸ�
		answer = rand() % 4;						// ���� �� ���� ����

		// 2. ���� ���
		cout << v[idxBox[answer]].getEng() << '?' << endl;		// ���� ���
		for (int i = 0; i < 4; i++)								// ���� ���
			cout << '(' << (i + 1) << ") " << v[this->idxBox[i]].getKor() << ' ';

		// 3. �� �Է¹ް� ����
		int user = ask();						// ���� ��
		if (user == this->answer) {				//	1. �����̶��,
			cout << "Excellent !!" << endl;
			continue;
		}
		else if (user >= 0 && user < 4) {		//	2. �����̶��,
			cout << "No. !!" << endl;
			continue;
		}
		else {									//	3. ��ȣ �� �ٸ� �Է�(����)		
			cout << endl;
			return;
		}
	}
}

void WordTest::run() {
	cout << "***** ���� ���� �׽�Ʈ�� �����մϴ�. *****" << endl;
	while (true) {
		int menu = getMenu();
		switch (menu) {
			case 1:		// ���� ����
				insertWord();
				break;
			case 2:		// ���� �׽�Ʈ
				makeQuest();
				break;
			default:	// ���α׷� ����
				return;
		}
	}
}

int main() {
	WordTest a;
	a.run();
	return 0;
}