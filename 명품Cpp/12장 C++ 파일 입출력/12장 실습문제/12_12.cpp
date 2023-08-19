/* �ܾ ����ִ� words.txt ������ �о� �ܾ�� vector�� �����ϰ�,
 ����ڷκ��� �ܾ �Է¹޾�, �� ���ڸ� �ٸ� �ܾ ��� ����ϱ�
 ����ڰ� �Է��� �ܾ�� �� ���ڸ� �ٸ� �ܾ ���� ��� "�ܾ����" ����ϱ�
 * ����ڰ� exit�� �Է��� ��� ���α׷� ���� */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Word {
	vector<string> wordBook;		// �ܾ ������ �����迭
	string user;
	int userSize;
	bool findWord();				// �� ���ڸ� �ٸ� �ܾ ã�� ����ϴ� �Լ�
public:
	Word() {						// ������: words.txt ���� �� �ܾ���� ��� vector�� ����
		cout << '.';
		ifstream fin("C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� �ǽ�����\\words.txt");
		if (!fin) {
			cout << "���Ͽ������\n";
			return;
		}
		string word;					// �ܾ� �ӽ�����
		while (getline(fin, word))		// ���� �� �� �� -> �ܾ�
			wordBook.push_back(word);	// �����迭�� Ǫ��
		cout << "..words.txt ���� �ε� �Ϸ�\n�˻��� �����մϴ�. �ܾ �Է��� �ּ���.\n";
	}
	void run() {
		while (true) {
			cout << "�ܾ�>> ";
			cin >> user;
			userSize = user.size();
			if (user == "exit")
				return;
			else if (this->findWord() == false)
				cout << "�߰��� �� ����\n";
		}
	}
	~Word() { fin.close(); }
};

// �� ���ڸ� �ٸ� �ܾ ã�� ����ϴ� �Լ�
bool Word::findWord() {
	bool result = false;
	for (int i = 0; i < wordBook.size(); i++) {			// ����: �����迭 �� ��� ���� ������ŭ �ݺ�
		if (wordBook[i].size() == userSize) {			//	���ڼ��� ���� ���
			int count = 0;								//		����: �� �ܾ� �� ���� ���ڼ�
			for (int j = 0; j < userSize; j++) {		//		����: ��� ���ڼ���ŭ �ݺ�
				if (wordBook[i][j] == user[j])			//			������ ��ġ�� ���� ���ڰ� �ִٸ�
					count++;							//			ī��Ʈ 1����
			}
			if (count == userSize - 1) {				//		�� ���ڸ� �ٸ��ٸ�
				cout << wordBook[i] << '\n';			//		�ش� �ܾ� ���
				result = true;							//		�ܾ ã�����Ƿ� true
			}
		}
	}
	return result;										// �ѹ��� �� ã�� ��츸 false ����
}

int main() {
	Word wordbook;
	wordbook.run();
	return 0;
}

/* �ַ����
	�ܾ����� �ܾ�� ������Է´ܾ ���� ��츦 ����,
	������ ũ���� ���,
	for������ �� �ܾ��� ���� �ڸ� ���ڸ� '*'�� �ٲ� ��
	�ٲ� �� �ܾ ���������� ����
	VS
	����
	�ܾ����� �ܾ�� ������Է´ܾ ������ ũ���� ���,
	�� �ܾ (�ܾ�ũ��-1) �� ��ŭ �������� ����
*/