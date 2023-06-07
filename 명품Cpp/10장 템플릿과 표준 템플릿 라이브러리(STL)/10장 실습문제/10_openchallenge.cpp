/* 520p. 10�� Open Challenge: ���� ���� �׽�Ʈ �ۼ�
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
	int idxBox[4];		// �����迭�� ����(�ܾ�) �� ������ �� 4 �ܾ��� �ε���
	int answer;			// ���� �� �� ��ȣ
public:
	WordTest() {
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
	void makeQuest();	// ���� ����
	int ask();			// ���� �Է�
	void run();			// ���α׷� ����
};
void WordTest::makeQuest() {
	for (int i = 0; i < 4; i++) {			// (10C4) 0-9 ������ ���� �� �ߺ����� 4�� ����
		idxBox[i] = rand() % 10;			//	idxBox�� �� ���ҿ� �ܾ��
		for (int j = 0; j < i; j++) {		//	��� ������ �ܾ� vs ���� ���ҵ�
			if (idxBox[i] == idxBox[j]) {	//	��� ������ �ܾ ���� ���ҿ� �ߺ��Ǿ��ٸ�,
				idxBox[i] = rand() % 10;	//	�� ����
				j--;
				continue;					//	�� �˻�
			}
		}
	}								// ������ �� �ܾ� 4�� ����
	answer = rand() % 4;			// ���� �� ���� ����
}
int WordTest::ask() {
	int answer;
	cout << ":>";
	cin >> answer;
	return answer - 1;
}
void WordTest::run() {
	cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� �����մϴ�." << endl;
	while (true) {
		makeQuest();														// ���� ����
		cout << v[this->idxBox[this->answer]].getEng() << '?' << endl;		// ���� ���
		for (int i = 0; i < 4; i++)											// ���� ���
			cout << '(' << (i+1) << ") " << v[this->idxBox[i]].getKor() << ' ';
		int user = ask();						// ���� ��
		if (user == this->answer) {				//	1. �����̶��,
			cout << "Excellent !!" << endl;
			continue;
		}
		else if (user >= 0 && user < 4) {		//	2. �����̶��,
			cout << "No. !!" << endl;
			continue;
		}
		else									//	3. ��ȣ �� �ٸ� �Է�
			break;
	}
}

int main() {
	WordTest a;
	a.run();
	return 0;
}