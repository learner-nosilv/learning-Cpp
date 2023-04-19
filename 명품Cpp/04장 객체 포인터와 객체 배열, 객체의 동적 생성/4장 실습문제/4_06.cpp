/* 6.
* string Ŭ������ ���������� �Է¹ް� �Ųٷ� ����ϴ� ���α׷� (size/2)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence = "\0";
	int index;
	char temp;
	cout << "�Ʒ��� �� ���� �Է��ϼ���. (exit�� �Է��ϸ� �����մϴ�)" << endl;

	while (1) {
		
		cout << ">>";
		getline(cin, sentence, '\n');	// ���� �Է¹ޱ�

		if (sentence == "exit") break;

		index = sentence.size() - 1;	// ���� ������ �ε���

		for (int i = 0; i < ((index+1)/2); i++) {
			temp = sentence[i];
			sentence[i] = sentence[index - i];
			sentence[index - i] = temp;
		}

		cout << sentence << endl;
	}
	
	return 0;
}

/* [book solution]
* ������
* 1. ���� ������ġ: ���� �ݺ��� ��, �ַ���� �ݺ��� �� (int size�� char temp)
* 2. �ε��� ���� : �� sentence[i] = sentence[index - i] | �ַ�� text[i] = text[size-i-1]
* 3. for���� ���ǹ�: �� i < ((index+1)/2) | �ַ�� i<n (int n = size/2;�� �̸� ����)

int main() {
	string text;
	cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
	while(true) {
		cout << ">>";
		getline(cin, text, '\n');
		if(text == "exit")
			break;
		int size = text.length();
		int n = size/2;
		for(int i=0; i<n; i++) {
			char tmp = text[i];
			text[i] = text[size-i-1];
			text[size-i-1] = tmp;
		}
		cout << text << endl;
	}
}
*/