/* p.612	����12-06	getline(ifstream&, string&) ���� words.txt ������ �а� �ܾ� �˻�*/

#include <iostream>	// C++ ǥ�� ����� ���̺귯��
#include <fstream>	// C++ ǥ�� ���� ����� ���̺귯��
#include <string>
#include <vector>	// �����迭
using namespace std;

// ������ �� �پ� �о, �� �� = �����迭�� ���ҷ� �Ҵ�
void fileRead(vector<string>& v, ifstream& fin) {	// �����Ű�����: �����迭v, �����бⰴü fin
	string line;	// �� �� ����
	while (getline(fin, line)) {	// fin ��ü�� �����а� line�� �Ҵ�
		v.push_back(line);			// ����Ÿ���� string���� �����迭 v�� ���ʿ� ����
	}
}

// �����迭 ���·� ����� �ؽ�Ʈ ���� �� ���ϴ� �ܾ ����ִ� ���� ã�Ƽ� �ش� �� ��ü�� ����ϴ� �Լ�
void search(vector<string>& v, string word) {
	for (int i = 0; i < v.size(); i++) {
		int index = v[i].find(word);	// �ش� ���ڿ����� �ܾ �����ϴ� ù index �� ���� (������ -1)
		if (index != -1) {
			cout << v[i] << endl;		// �ܾ ���ԵǾ��ִٸ� �ش� �� ���� ���
		}
	}
}


int main() {
	vector<string> wordVector;
	const char* firstFile = "C:\\Users\\renee\\source\\repos\\learning-Cpp\\��ǰCpp\\12�� C++ ���� �����\\12�� ����\\���� 12-6\\words.txt";
	ifstream fileIn(firstFile);		// �ش� ������ ��� �о���̴� ���� �б� ��Ʈ�� ��ü ����
	if (!fileIn) {					// ���� ���Ⱑ ������ ���
		cout << firstFile << " ������ �� �� �����ϴ�" << endl;
		return 0;
	}

	fileRead(wordVector, fileIn);	// �����б⽺Ʈ����ü�� ���ؼ�, ���� ������ �� �� ������ �����迭�� �Ҵ�
	fileIn.close();					// �����б⽺Ʈ����ü�� ����� ���ϴݱ�

	cout << firstFile << " ������ �о����ϴ�." << endl;
	while (true) {					// ���ѷ���
		cout << "�˻��� �ܾ �Է��ϼ��� >>";
		string word;
		getline(cin, word);
		if (word == "exit")
			break;
		search(wordVector, word);
	}
	cout << "���α׷��� �����մϴ�." << endl;

	return 0;
}