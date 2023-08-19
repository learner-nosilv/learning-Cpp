/* 632p.	OpenChallenge	HangMan Game 
	- ���ܾ� ��������
	- ������ N(2)���� ���� �����	-> ���ӻ������� �Ķ���ͷ� ����
	- 5�� Ʋ���� ���α׷� ����
*/
#include <iostream>	// C++ ǥ�� ����� ���̺귯��
#include <string>	// string type ���
#include <fstream>	// C++ ǥ�� ���� ����� ���̺귯��
#include <vector>	// ���� �� �ܾ �����迭�� �Ҵ�
#include <map>		// �ܾ�� ���� (index, ��)
#include <iterator>	// �ݺ���
#include <random>	// �����Լ�
#include <ctime>	// �ð� srand�� seed�� ����
using namespace std;

class HangMan {
	vector<string> wordBook;	// �ܾ���
	string word;				// ���� �ܾ�
	int level;					// �� ĭ ����
	map<int, char> blank;		// �� ĭ �ο���, �� ĭ�� ��

	void set();					// �ܾ�� �� ĭ ����
	void showWord();			// �� ĭ�� �ݿ��� �ܾ� ���
	void game();				// ���� �� ��
public:
	HangMan(const char* wordFile, int level);
	void run();
};

// ������
HangMan::HangMan(const char* wordFile, int level) {
	ifstream fin(wordFile);						// ���� �б� ��Ʈ�� ��ü ���� & �б� �������� ���α׷�-���Ͽ���
	string word;								// �� �ܾ� <- �� ��
	while (getline(fin, word))					// ���� : EOF ������
		this->wordBook.push_back(word);			// �ܾ��忡 �߰� 
	fin.close();								// ���� ���� ����
	this->level = level;						// ���̵� ����
	srand((unsigned)time(NULL));				// ���� seed ����
}

// �ܾ�� �� ĭ ����
void HangMan::set() {
	// 1. �ܾ� ����
	int idx = rand() % 25143;				// �ܾ� ������ �� �ε��� �����ϰ� �Ҵ�
	this->word = this->wordBook[idx];		// �ܾ� ����
	int length = this->word.length();		// �ܾ� ����

	// 2. �� ĭ ����
	blank.clear();																// �� ĭ �ʱ�ȭ
	for (int i = 0; (i < (this->level) && i < length); i++) {					// �� ĭ�� ����=���̵� && �ܾ���̺��� ���� �� ����
		int randIdx = rand() % length;
		auto iter = blank.insert({ randIdx , word[randIdx] });							// �� ĭ �ε���, �� ĭ�� �� (�ߺ����� ���� ���н�, iter�� �ι�° ����=false)
		if (iter.second == false) {												// �� ĭ �ε����� �ߺ��� ���
			i--;
			continue;															// �� ĭ ���� �����
		}
	}
}

// �� ĭ�� �ݿ��� �ܾ� ���
void HangMan::showWord() {
	for (int i = 0; i < this->word.length(); i++) {
		if (blank.find(i) == blank.end())				// ������ �� ĭ�� �ƴ� ���
			cout << word[i];							// ���� ���
		else
			cout << '-';
	}
}

// ���� �� ��
void HangMan::game() {
	char answer;					// ����� ���
	int count=0;					// Ʋ�� Ƚ��
	this->set();					// �ܾ�� �� ĭ ����

	while (true) {
		bool clear = false;			// ���俩��
		this->showWord();			// ���� �����ֱ�
		cout << ">>";
		cin >> answer;				// ��� �ޱ�
		for (auto it = blank.begin(); it != blank.end(); it++) {	// ��� ��
			if ((it->second) == answer) {							// ���̶�� �� ĭ ����
				clear = true;										// ����ó��
				blank.erase(it);									// �� ĭ ����
				break;
			}
		}
		if (clear == false) count++;								// Ʋ�� ���, Ʋ�� Ƚ�� ����
		if (count > 4) {											// 5ȸ Ʋ�� ���
			cout << "5�� ���� �Ͽ����ϴ�.\n" << this->word << endl;	// ����� ������ ��,
			break;													// ���� ����
		}
		if (blank.size() == 0) {									// ���� ��� ���� ���
			cout << this->word << endl;								// ����� ������ ��
			break;													// ���� ����
		}
	}
}

// ���� ��ü �۵�
void HangMan::run() {
	cout << "----------------------------------------------\n"
		<< "���ݺ��� ��� ������ �����մϴ�.\n"
		<< "----------------------------------------------\n";
	char reGame = 'y';
	while (reGame=='y') {
		game();
		cout << "Next(y/n)?";
		cin >> reGame;
	}
}

int main() {
	HangMan mark1("C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\words.txt", 2);	// �ش� �ܾ�����, 2���� ���ڰ� ������ ���̵��� ��ǰ��Ӱ�ü ����
	mark1.run();		// ��ǰ��� ����
	return 0;
}