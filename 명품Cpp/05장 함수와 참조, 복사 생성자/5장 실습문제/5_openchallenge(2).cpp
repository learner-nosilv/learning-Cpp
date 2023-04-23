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
	if (morse[(size - 1)] != ' ')	// ���������� ���� 1) �˻������ ���� �𽺺�ȣ (�������̶��, �𽺺�ȣ�� ���� ������ �����̾����)
		return false;

	int start_idx = 0;				// �� �˻������ �𽺺�ȣ ���� �ε���
	int end_idx;					// �� �˻������ �𽺺�ȣ �� �ε���
	string word;					// �� �˻������ �𽺺�ȣ
	char next;						// �� �˻������ �𽺺�ȣ�� �����ϴ� ����
	bool state = true;				// �𽺺�ȣ�� �����Ǵ� ���ڰ� �߰ߵǾ����� ����

	// �𽺺�ȣ �˻� ����
	while (start_idx < size && state == true) {			// ������������ : �˻��� or �𽺺�ȣ�� �����Ǵ� ���ڰ� �����ϴ� ���
		state = false;									// �߰ߵǸ� true�� ��ȯ
		if (morse.substr(start_idx, 2) == "  ") {		// ġȯ�� �� �ִ� ��� 1) 2����𽺺�ȣ -> 1���鹮�� (������ ������ �˻������ �������ʴ� ������ 2���� �𽺺�ȣ)
			start_idx += 2;
			text += ' ';
			state = true;
		}
		else {											// �� �˻������ �𽺺�ȣ�� �����ϴ� ��� ( ġȯ������ ���ڰ� �ְų� ���� ��� �� �� ���� )
			end_idx = morse.find(' ', start_idx);		// �� �˻������ �𽺺�ȣ �� �ε���: �𽺺�ȣ�� ��������� ���ڰ� ��
			word = morse.substr(start_idx, (end_idx - start_idx + 1));

			for (int i = 0; i < 42; i++) {			// �𽺺�ȣ: morse[0-25] = a-z , morse[26-35] = 0-9,  morse[36-41] = / ? , . + =, morse[42] = ����
				if (word == morse_base[i]) {		// ġȯ�� �� �ִ� ��� 2) ������ ������ ���ĺ�/����/Ư������ 
					if (i >= 0 && i <= 25)			// ���ĺ�
						next = 'a' + i;
					else if (i >= 26 && i <= 35)	// ����
						next = '0' + i - 26;
					else							// Ư������ if (i >= 36 && i<=41) 
						switch (i) {
							case 36:
								next = '/';
								break;
							case 37:
								next = '?';
								break;
							case 38:
								next = ',';
								break;
							case 39:
								next = '.';
								break;
							case 40:
								next = '+';
								break;
							case 41:
								next = '=';
								break;
						}
					start_idx = end_idx + 1;
					text += next;
					state = true;
					break;							// ġȯ������ ���ڰ� �߰ߵ� ��� ���� Ż��
				}
			}
			// for �� Ż����� : ġȯ������ ���ڰ� �߰ߵǾ� state true���·� Ż�� or �ѹ��� �߰ߵ����ʾƼ� state=false���·� Ż��
		}
		// for �� Ż����°� state true���·� Ż���� ���, while �ʱ⹮ / state false ���·� Ż���� ��� while �� Ż��
	}
	return state;
}

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