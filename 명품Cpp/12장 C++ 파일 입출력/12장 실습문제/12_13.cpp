/* �ܾ ����ִ� words.txt ������ �о� �ܾ�� vector�� �����ϰ�,
 ����ڰ� �Է��� ���ڿ��� ���۵Ǵ� ��� �ܾ ����ϴ� ���α׷�
 (���ٸ�, "�߰��� �� ����"	exit �Է½� ���� */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Word {
	vector<string> wordBook;		// �ܾ ������ �����迭
	string user;					// ����ڰ� �Է��� �ܾ�
	int userSize;					// ����ڰ� �Է��� �ܾ��� ���ڼ�
	bool find1DiffWord();			// �� ���ڸ� �ٸ� �ܾ ã�� ����ϴ� �Լ�
	bool findIncludingWord();		// ����ڰ� �Է��� �ܾ�� �����ϴ� �ܾ�
public:
	Word() {						// ������: words.txt ���� �� �ܾ���� ��� vector�� ����
		cout << '.';
		ifstream fin("C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\words.txt");
		if (!fin) {
			cout << "���Ͽ������\n";
			return;
		}
		string word;						// �ܾ� �ӽ�����
		while (getline(fin, word))			// ���� �� �� �� -> �ܾ�
			this->wordBook.push_back(word);	// �����迭�� Ǫ��
		cout << "..words.txt ���� �ε� �Ϸ�\n�˻��� �����մϴ�. �ܾ �Է��� �ּ���.\n";
	}
	void run(int menu) {
		while (true) {
			cout << "�ܾ�>> ";
			cin >> this->user;
			this->userSize = user.size();
			if (user == "exit")
				return;
			else if ((menu == 0) && (this->find1DiffWord() == false))
				cout << "�߰��� �� ����\n";
			else if ((menu == 1) && (this->findIncludingWord() == false))
				cout << "�߰��� �� ����\n";
		}
	}
	~Word() { fin.close(); }
};

// �� ���ڸ� �ٸ� �ܾ ã�� ����ϴ� �Լ�
bool Word::find1DiffWord() {
	bool result = false;
	for (int i = 0; i < this->wordBook.size(); i++) {			// ����: �����迭 �� ��� ���� ������ŭ �ݺ�
		if (this->wordBook[i].size() == this->userSize) {		//	���ڼ��� ���� ���
			int count = 0;										//		����: �� �ܾ� �� ���� ���ڼ�
			for (int j = 0; j < this->userSize; j++) {			//		����: ��� ���ڼ���ŭ �ݺ�
				if (this->wordBook[i][j] == user[j])			//			������ ��ġ�� ���� ���ڰ� �ִٸ�
					count++;									//			ī��Ʈ 1����
			}
			if (count == this->userSize - 1) {					//		�� ���ڸ� �ٸ��ٸ�
				cout << this->wordBook[i] << '\n';				//		�ش� �ܾ� ���
				result = true;									//		�ܾ ã�����Ƿ� true
			}
		}
	}
	return result;												// �ѹ��� �� ã�� ��츸 false ����
}

// ����ڰ� �Է��� �ܾ�� �����ϴ� �ܾ�
bool Word::findIncludingWord() {
	bool result = false;
	for (int i = 0; i < this->wordBook.size(); i++) {					// ����: �����迭 �� ��� ���� ������ŭ �ݺ�
		if (this->wordBook[i].size() >= this->userSize) {				//	ũ�Ⱑ �� ũ�� (substr ��������)
			if (wordBook[i].substr(0, this->userSize) == this->user) {	//	�� �κ��� ����ڰ� �Է��� �ܾ�� �����ϴٸ�
				cout << this->wordBook[i] << '\n';						//		�ش� �ܾ� ���
				result = true;											//		�ܾ ã�����Ƿ� true
			}
		}
	}
	return result;														// �ѹ��� �� ã�� ��츸 false ���� 
}

int main() {
	Word wordbook;			// �ܾ����� �ܾ ����Լ��� ����, �ѱ��ڸ� �ٸ� �ܾ�(0)�� ���� ���� �ܾ�(1)�� ã���ִ� Ŭ������ ��ü ����
	wordbook.run(1);		// ���� ���� �ܾ ã���ִ� ������� run
	return 0;
}