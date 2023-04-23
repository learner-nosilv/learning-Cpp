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
	string morse_base[43];	// 알파벳, 숫자, 특문, 공백 전부 담음 [책의 힌트와 다르게 함]
public:
	Morse();
	void text2Morse(string text, string& morse);	// 텍스트는 값복사, 모스부호는 참조alias
	bool morse2Text(string morse, string& text);	// 모스부호는 값복사, 텍스트는 참조alias (실패시 false 리턴)
};

// Constructor : 내 방식대로 (주어진 힌트말고 내 방식대로)
Morse::Morse() {
	// 모스 부호 초기화: temp_morse[0-25] = a-z , temp_morse[26-35] = 0-9,  temp_morse[36-41] = / ? , . + =, temp_morse[42] = 공백
	string* temp_morse = new string[43]{ ".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. ", "----- ", ".---- ", "..--- ", "...-- ", "....- ", "..... ", "-.... ", "--... ", "----.. ", "----. ", "-..-. ", "..--.. ", "--..-- ", ".-.-.- ", ".-.-. ", "-...- ", "  " };

	for (int i = 0; i < 43; i++)		// 멤버함수에 할당하기
		morse_base[i] = temp_morse[i];

	delete[] temp_morse;
}

// 문자를 모스부호로 변환하는 함수
void Morse::text2Morse(string text, string& morse) {
	int size = text.size();
	string next;

	// 한 문자에 매치되는 모스부호를 찾아서 이어붙인다.
	for (int i = 0; i < size; i++) {
		if (text[i] >= 'a' && text[i] <= 'z')		// 알파벳
			next = morse_base[(text[i] - 'a')];
		else if (text[i] >= '0' && text[i] <= '9')	// 숫자
			next = morse_base[text[i] - '0' + 26];
		else {										// 특수문자와 공백
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
	if (morse[(size - 1)] != ' ')	// 비정상적인 상태 1) 검사단위가 없는 모스부호 (정상적이라면, 모스부호의 끝은 무조건 공백이어야함)
		return false;

	int start_idx = 0;				// 한 검사단위의 모스부호 시작 인덱스
	int end_idx;					// 한 검사단위의 모스부호 끝 인덱스
	string word;					// 한 검사단위의 모스부호
	char next;						// 한 검사단위의 모스부호와 대응하는 문자
	bool state = true;				// 모스부호와 대조되는 문자가 발견되었는지 여부

	// 모스부호 검사 시작
	while (start_idx < size && state == true) {			// 루프유지조건 : 검사중 or 모스부호와 대조되는 문자가 존재하는 경우
		state = false;									// 발견되면 true로 전환
		if (morse.substr(start_idx, 2) == "  ") {		// 치환할 수 있는 경우 1) 2공백모스부호 -> 1공백문자 (공백이 기준인 검사단위에 잡히지않는 공백이 2개인 모스부호)
			start_idx += 2;
			text += ' ';
			state = true;
		}
		else {											// 한 검사단위의 모스부호가 존재하는 경우 ( 치환가능한 문자가 있거나 없는 경우 둘 다 존재 )
			end_idx = morse.find(' ', start_idx);		// 한 검사단위의 모스부호 끝 인덱스: 모스부호는 공백단위로 문자가 됨
			word = morse.substr(start_idx, (end_idx - start_idx + 1));

			for (int i = 0; i < 42; i++) {			// 모스부호: morse[0-25] = a-z , morse[26-35] = 0-9,  morse[36-41] = / ? , . + =, morse[42] = 공백
				if (word == morse_base[i]) {		// 치환할 수 있는 경우 2) 공백을 제외한 알파벳/숫자/특수문자 
					if (i >= 0 && i <= 25)			// 알파벳
						next = 'a' + i;
					else if (i >= 26 && i <= 35)	// 숫자
						next = '0' + i - 26;
					else							// 특수문자 if (i >= 36 && i<=41) 
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
					break;							// 치환가능한 문자가 발견된 경우 루프 탈출
				}
			}
			// for 문 탈출상태 : 치환가능한 문자가 발견되어 state true상태로 탈출 or 한번도 발견되지않아서 state=false상태로 탈출
		}
		// for 문 탈출상태가 state true상태로 탈출한 경우, while 초기문 / state false 상태로 탈출한 경우 while 문 탈출
	}
	return state;
}

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