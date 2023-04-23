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
	string alphabet[26];
	string digit[10];
	string slash, question, comma, period, plus, equal;
public:
	Morse();
	void text2Morse(string text, string& morse);	// �ؽ�Ʈ�� ������, �𽺺�ȣ�� ����alias
	bool morse2Text(string morse, string& text);	// �𽺺�ȣ�� ������, �ؽ�Ʈ�� ����alias (���н� false ����)
};

// Constructor : �� ���� ���� �����ٵ�, �����Բ��� ��Ʈ ���� ������� �ϼ���
Morse::Morse() {
	// �� ��ȣ �ʱ�ȭ: temp_morse[0-25] = a-z , temp_morse[26-35] = 0-9,  temp_morse[36-41] = / ? , . + =
	string* temp_morse = new string[42]{ ".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. ", "----- ", ".---- ", "..--- ", "...-- ", "....- ", "..... ", "-.... ", "--... ", "----.. ", "----. ", "-..-. ", "..--.. ", "--..-- ", ".-.-.- ", ".-.-. ", "-...- " };

	int j = 0;
	for (int i = 0; i < 26; i++) {
		alphabet[i] = temp_morse[j];
		j++;
	}
	for (int i = 0; i < 10; i++) {
		digit[i] = temp_morse[j];
		j++;
	}
	slash = temp_morse[j++];
	question = temp_morse[j++];
	comma = temp_morse[j++];
	period = temp_morse[j++];
	plus = temp_morse[j++];
	equal = temp_morse[j++];

	delete[] temp_morse;
}

// ���ڸ� �𽺺�ȣ�� ��ȯ�ϴ� �Լ�
void Morse::text2Morse(string text, string& morse) {
	int size = text.size();
	string next;

	// �� ���ڿ� ��ġ�Ǵ� �𽺺�ȣ�� ã�Ƽ� �̾���δ�.
	for (int i = 0; i < size; i++) {
		if (text[i] >= 'a' && text[i] <= 'z')		// ���ĺ�
			next = alphabet[(text[i] - 'a')];
		else if (text[i] >= '0' && text[i] <= '9')	// ����
			next = digit[(text[i] - '0')];
		else {										// Ư�����ڿ� ����
			switch (text[i]) {
				case '/':
					next = slash;
					break;
				case '?':
					next = question;
					break;
				case ',':
					next = comma;
					break;
				case '.':
					next = period;
					break;
				case '+':
					next = plus;
					break;
				case '=':
					next = equal;
					break;
				case ' ':
					next = "  ";
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
	bool state = true;				// �𽺺�ȣ�� �����Ǵ� ���ڰ� �߰ߵǾ����� ����

	// �𽺺�ȣ �˻� ����
	if (morse[(size - 1)] != ' ')	// ���������� ���� 1) �˻������ ���� �𽺺�ȣ (�������̶��, �𽺺�ȣ�� ���� ������ �����̾����)
		return false;

	while (start_idx < size && state == true) {	// ������������ : �˻��� or �𽺺�ȣ�� �����Ǵ� ���ڰ� �����ϴ� ���
		end_idx = morse.find(' ', start_idx);	// �𽺺�ȣ�� �˻��ϴ� �� index ��� �𽺺�ȣ�� ��������� ���ڰ� ��
		if (morse.substr(start_idx, 2) == "  ") {	// ġȯ�� �� �ִ� ��� 2) 2����𽺺�ȣ -> 1���鹮�� (������ ������ �˻������ �������ʴ� ������ 2���� �𽺺�ȣ)
			start_idx += 2;
			text += ' ';
		}
		else {													// �� �˻������ �𽺺�ȣ�� �����ϴ� ��� ( ġȯ������ ���ڰ� �ְų� ���� ��� �� �� ���� )
			word = morse.substr(start_idx, (end_idx - start_idx + 1));
			for (int i = 0; i < 37; i++) {		// word�� 42���� �𽺺�ȣ�� �����ϱ�
				state = false;					// ��ġ�ϴ� ���� ������ false�� for�� Ż����
				if (i < 26) {					// 1) alphabet �𽺺�ȣ�� ����
					if (word == alphabet[i]) {
						text += i + 'a';
						start_idx = end_idx + 1;
						state = true;			// ��� ��
						break;
					}
				}
				else if (i < 36) {				// 2) digit �𽺺�ȣ�� ����
					if (word == digit[i - 26]) {
						text += i - 26 + '0';
						start_idx = end_idx + 1;
						state = true;
						break;
					}
				}
				else {							// 3) Ư�����ڿ� ����
					if (word == slash) {
						text += '/';
						start_idx = end_idx + 1;
						state = true;
						break;
					}
					else if (word == question) {
						text += '?';
						start_idx = end_idx + 1;
						state = true;
						break;
					}
					else if (word == comma) {
						text += ',';
						start_idx = end_idx + 1;
						state = true;
						break;
					}
					else if (word == period) {
						text += '.';
						start_idx = end_idx + 1;
						state = true;
						break;
					}
					else if (word == plus) {
						text += '+';
						start_idx = end_idx + 1;
						state = true;
						break;
					}
					else if (word == equal) {
						text += '=';
						start_idx = end_idx + 1;
						state = true;
						break;
					}
				}
			} // for�� �� : state true or false�� ��
		} // if �� else �� �� : state true or false�� ��
	} // while�� �� : 1�𽺴����� true ���·� ���� �˻�Ϸ� or false ���·� �ߴ�
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