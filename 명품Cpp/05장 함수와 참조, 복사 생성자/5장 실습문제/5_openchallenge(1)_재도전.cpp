/* Open Challenge 265p
* 최소단위 . 와 -
* 알파벳 단위는 공백으로 구분
* 단어 단위는 공백3으로 구분 스페이스바 = 공백2
*
* 프로그램 기능:
*	영문 텍스트를 입력받아 모스 부호로 변환하여 출력
*	해당 모스부호를 다시 영문텍스트로 변환하여 출력
*
* Morse 클래스:
*	멤버변수: 알파벳, 숫자, 특수문자의 모스부호를 string 타입으로 담은 배열
*	멤버함수: 영문텍스트를 모스 부호로 / 모스부호를 영문텍스트로 변환하는 함수
*
* 메인함수:
*	변수: 영문텍스트, 모스부호를 저장할 스트링 객체
*	영문 텍스트 입력받기
*	모스부호로 변환하고 출력하기
*	모스부호를 영문텍스트로 변환하고 출력하기
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
	void text2Morse(string text, string& morse);	// 텍스트는 값복사, 모스부호는 참조alias
	bool morse2Text(string morse, string& text);	// 모스부호는 값복사, 텍스트는 참조alias (실패시 false 리턴)
};

// Constructor : 더 쉬운 길이 있을텐데, 교수님께서 힌트 말을 들으라고 하셨음
Morse::Morse() {
	// 모스 부호 초기화: temp_morse[0-25] = a-z , temp_morse[26-35] = 0-9,  temp_morse[36-41] = / ? , . + =
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

// 문자를 모스부호로 변환하는 함수
void Morse::text2Morse(string text, string& morse) {
	int size = text.size();
	string next;

	// 한 문자에 매치되는 모스부호를 찾아서 이어붙인다.
	for (int i = 0; i < size; i++) {
		if (text[i] >= 'a' && text[i] <= 'z')		// 알파벳
			next = alphabet[(text[i] - 'a')];
		else if (text[i] >= '0' && text[i] <= '9')	// 숫자
			next = digit[(text[i] - '0')];
		else {										// 특수문자와 공백
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
				default:							// 해석이 안 되는 경우
					next = '#';
			}
		}
		morse += next;
	}
}

/* 모스부호[루프]
	1. 공백 단위로 자름 [find로 공백찾기]
	2. 모든 문자의 모스 부호와 비교를 한 후, 발견되면 이어붙이고 state를 true로 전환
	3. 비교가 끝나면, end+1부터 다시 공백 단위로 자름
*/
bool Morse::morse2Text(string morse, string& text) {
	int size = morse.size();		// 모스부호의 총 갯수
	int start_idx = 0;				// 한 검사단위의 모스부호 인덱스 시작
	int end_idx;					// 한 검사단위의 모스부호 인덱스 끝
	string word;					// 한 검사단위의 모스부호

	// 모스부호 검사 시작
	if (morse[(size - 1)] != ' ')	// 비정상적 모스부호 (정상적이라면, 모스부호의 끝은 무조건 공백이어야함)
		return false;

	while (start_idx < size) {		// 검사할 모스부호단위가 없어질 때까지 반복
		if (start_idx < size - 1 && morse.substr(start_idx, 2) == "  ") {	// [모스] 공백2개인 경우
			text += ' ';							// [일반] 공백으로 변환
			start_idx += 2;							// 다음 검사시작점 설정
			continue;								// 다음 모스부호단위 검사
		}
		end_idx = morse.find(' ', start_idx);		// 모스부호를 검사하는 끝 index
		word = morse.substr(start_idx, (end_idx - start_idx + 1));	// 모스부호 검사단위

		int state = false;							// 발견되지 않은 경우
		// 1. alphabet 모스부호와 대조
		for (int i = 0; i < 26; i++) {
			if (word == alphabet[i]) {
				text += i + 'a';
				start_idx = end_idx + 1;
				state = true;
				break;
			}
		}
		if (state == true) { continue; }			// alphabet 에서 대조완료된 경우 다음 모스부호단위 검사

		// 2. digit 모스부호와 대조
		for (int i = 0; i < 10; i++) {
			if (word == digit[i]) {
				text += i + '0';
				start_idx = end_idx + 1;
				state = true;
				break;
			}
		}
		if (state == true) { continue; }			// digit 에서 대조완료된 경우 다음 모스부호단위 검사

		// 3. 특수문자와 대조
		if (word == slash) { text += '/'; }
		else if (word == question) { text += '?'; }
		else if (word == comma) { text += ','; }
		else if (word == period) { text += '.'; }
		else if (word == plus) { text += '+'; }
		else if (word == equal) { text += '='; }
		else { return false; }						// 대조불가 false 반환
		start_idx = end_idx + 1;					// 대조된 경우 
		continue;									// 다음 모스부호단위 검사
	}
	return true;					// 모든 검사를 문제없이 마친 경우 true 반환 
}
// [55 Line]

int main() {
	Morse test;	// Morse클래스의 객체test 생성

	string english_sentence;
	string morse_sentence = "";
	string morse2english = "";

	// 영문 텍스트 입력받기
	cout << "아래에 영문 텍스트를 입력하세요. 모스 부호로 바꿉니다." << endl;
	getline(cin, english_sentence, '\n');

	// 모스부호로 변환 후 출력하기
	test.text2Morse(english_sentence, morse_sentence);
	cout << morse_sentence << endl << endl;

	// 모스부호를 영문 텍스트로 변환 후 출력하기
	cout << "모스 부호를 다시 영문 텍스트로 바꿉니다." << endl;
	if (test.morse2Text(morse_sentence, morse2english) == true)
		cout << morse2english << endl;
	else
		cout << "변환 실패" << endl;

	return 0;
}