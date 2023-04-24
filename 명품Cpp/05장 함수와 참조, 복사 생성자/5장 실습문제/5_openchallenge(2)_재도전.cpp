/* Open Challenge 265p
* �ּҴ��� . �� -
* ���ĺ� ������ �������� ����
* �ܾ� ������ ����3���� ���� �����̽��� = ����2
*
* ���α׷� ���:
*	���� �ؽ�Ʈ�� �Է¹޾� �� ��ȣ�� ��ȯ�Ͽ� ���
*	�ش� �𽺺�ȣ�� �ٽ� �����ؽ�Ʈ�� ��ȯ�Ͽ� ���
*
* Morse Ŭ����:
*	�������: ���ĺ�, ����, Ư�������� �𽺺�ȣ�� string Ÿ������ ���� �迭
*	����Լ�: �����ؽ�Ʈ�� �� ��ȣ�� / �𽺺�ȣ�� �����ؽ�Ʈ�� ��ȯ�ϴ� �Լ�
*
* �����Լ�:
*	����: �����ؽ�Ʈ, �𽺺�ȣ�� ������ ��Ʈ�� ��ü
*	���� �ؽ�Ʈ �Է¹ޱ�
*	�𽺺�ȣ�� ��ȯ�ϰ� ����ϱ�
*	�𽺺�ȣ�� �����ؽ�Ʈ�� ��ȯ�ϰ� ����ϱ�
*/

#include <iostream>
#include <string>
using namespace std;

class Morse {
	string morse_base[43];	// ���ĺ�, ����, Ư��, ���� ���� ���� [å�� ��Ʈ�� �ٸ��� ��]
public:
	Morse();
	void text2Morse(string text, string& morse);	// �ؽ�Ʈ�� ������, �𽺺�ȣ�� ����alias
	bool morse2Text(string morse, string& text);	// �𽺺�ȣ�� ������, �ؽ�Ʈ�� ����alias (���н� false ����)
};

// Constructor : �� ��Ĵ�� (�־��� ��Ʈ���� �� ��Ĵ��)
Morse::Morse() {
	// �� ��ȣ �ʱ�ȭ: temp_morse[0-25] = a-z , temp_morse[26-35] = 0-9,  temp_morse[36-41] = / ? , . + =, temp_morse[42] = ����
	string* temp_morse = new string[43]{ ".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. ", "----- ", ".---- ", "..--- ", "...-- ", "....- ", "..... ", "-.... ", "--... ", "----.. ", "----. ", "-..-. ", "..--.. ", "--..-- ", ".-.-.- ", ".-.-. ", "-...- ", "  " };

	for (int i = 0; i < 43; i++)		// ����Լ��� �Ҵ��ϱ�
		morse_base[i] = temp_morse[i];

	delete[] temp_morse;
}

// ���ڸ� �𽺺�ȣ�� ��ȯ�ϴ� �Լ�
void Morse::text2Morse(string text, string& morse) {
	int size = text.size();
	string next;

	// �� ���ڿ� ��ġ�Ǵ� �𽺺�ȣ�� ã�Ƽ� �̾���δ�.
	for (int i = 0; i < size; i++) {
		if (text[i] >= 'a' && text[i] <= 'z')		// ���ĺ�
			next = morse_base[(text[i] - 'a')];
		else if (text[i] >= '0' && text[i] <= '9')	// ����
			next = morse_base[text[i] - '0' + 26];
		else {										// Ư�����ڿ� ����
			switch (text[i]) {
				case '/':
					next = morse_base[36];
					break;
				case '?':
					next = morse_base[37];
					break;
				case ',':
					next = morse_base[38];
					break;
				case '.':
					next = morse_base[39];
					break;
				case '+':
					next = morse_base[40];
					break;
				case '=':
					next = morse_base[41];
					break;
				case ' ':
					next = morse_base[42];
					break;
				default:							// �ؼ��� �� �Ǵ� ���
					next = '#';
			}
		}
		morse += next;
	}
}

/* �𽺺�ȣ[����]
	1. ���� ������ �ڸ� [find�� ����ã��]
	2. ��� ������ �� ��ȣ�� �񱳸� �� ��, �߰ߵǸ� �̾���̰� state�� true�� ��ȯ
	3. �񱳰� ������, end+1���� �ٽ� ���� ������ �ڸ�
*/

bool Morse::morse2Text(string morse, string& text) {
	int size = morse.size();		// �𽺺�ȣ�� �� ����
	int start_idx = 0;				// �� �˻������ �𽺺�ȣ �ε��� ����
	int end_idx;					// �� �˻������ �𽺺�ȣ �ε��� ��
	string word;					// �� �˻������ �𽺺�ȣ

	// �𽺺�ȣ �˻� ����
	if (morse[(size - 1)] != ' ')	// �������� �𽺺�ȣ (�������̶��, �𽺺�ȣ�� ���� ������ �����̾����)
		return false;

	while (start_idx < size) {		// �˻��� �𽺺�ȣ������ ������ ������ �ݺ�
		if (start_idx < size - 1 && morse.substr(start_idx, 2) == "  ") {	// [��] ����2���� ���
			text += ' ';							// [�Ϲ�] �������� ��ȯ
			start_idx += 2;							// ���� �˻������ ����
			continue;								// ���� �𽺺�ȣ���� �˻�
		}
		end_idx = morse.find(' ', start_idx);		// �𽺺�ȣ�� �˻��ϴ� �� index
		word = morse.substr(start_idx, (end_idx - start_idx + 1));	// �𽺺�ȣ �˻����

		// �ϳ��� �𽺺�ȣ������ 41���� ��������� ����
		for (int i = 0; i < 42; i++) {
			if (word == morse_base[i]) {			// �𽺺�ȣ�� ������ �� ���
				if (i < 26)
					text += i + 'a';
				else if (i < 36)
					text += i - 26 + '0';
				else {
					switch (i) {
						case 36: text += '/'; break;
						case 37: text += '?'; break;
						case 38: text += ','; break;
						case 39: text += '.'; break;
						case 40: text += '+'; break;
						case 41: text += '='; break;
					}
				}
				start_idx = end_idx + 1;
				break;	// for�� Ż��
			}
			else return false;						// ���������� ��� false ��ȯ
		}
	}
	return true;		// ��� �𽺺�ȣ���� �ؼ��Ϸ�
}
// [44 Line]

int main() {
	Morse test;	// MorseŬ������ ��ütest ����

	string english_sentence;
	string morse_sentence = "";
	string morse2english = "";

	// ���� �ؽ�Ʈ �Է¹ޱ�
	cout << "�Ʒ��� ���� �ؽ�Ʈ�� �Է��ϼ���. �� ��ȣ�� �ٲߴϴ�." << endl;
	getline(cin, english_sentence, '\n');

	// �𽺺�ȣ�� ��ȯ �� ����ϱ�
	test.text2Morse(english_sentence, morse_sentence);
	cout << morse_sentence << endl << endl;

	// �𽺺�ȣ�� ���� �ؽ�Ʈ�� ��ȯ �� ����ϱ�
	cout << "�� ��ȣ�� �ٽ� ���� �ؽ�Ʈ�� �ٲߴϴ�." << endl;
	if (test.morse2Text(morse_sentence, morse2english) == true)
		cout << morse2english << endl;
	else
		cout << "��ȯ ����" << endl;

	return 0;
}