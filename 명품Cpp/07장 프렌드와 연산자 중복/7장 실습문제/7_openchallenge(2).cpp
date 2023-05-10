/* openchallenge.
* 4장 실습문제 13번의 Histogram 클래스 솔루션코드를
* 현 문제의 main()과 호환되도록 수정하기
* 
*  * 내 코드로하면 이미 코드를 너무 잘 알고있으니까,
*	일부러 생소한 솔루션 코드를 조작해보기로 함
*/

#include <iostream>
#include <string>
using namespace std;

// class Declaration
class Histogram {
	string text;
	int histo[26] = { 0, }; // [26개의 알파벳]에 대해 각 글자당 개수 저장
public:
	Histogram(string text);				// 생성자: 히스토그램으로 분석할 문자열 전달
	Histogram& operator<<(string text);	// 인자를 멤버text에 concat후 객체 참조리턴
	Histogram& operator<<(char c);		// 인자를 멤버text에 concat후 객체 참조리턴
	void operator!();					// 객체의 멤버text 콘솔출력
	~Histogram() {}						// 
};

// class Implementation
Histogram::Histogram(string text = "") {
	this->text = text;
}

Histogram& Histogram::operator<<(string text) {	// 객체.<<(내용)
	this->text.append(text);		// this->text += text; 와 동일
	return *(this);					// 객체자신 참조리턴
}
Histogram& Histogram::operator<<(char c) {
	char buf[] = { c, '\0' };		// 문자c를 c-string 스타일의 문자열로 변환
	this->text.append(buf);			// this->text += text; 와 동일
	return *(this);					// 객체자신 참조리턴
}

void Histogram::operator!(){

	cout << this->text << endl << endl;	// text 전문 출력

	for (int i = 0; i < (this->text).length(); i++) {
		if (isalpha((this->text)[i])) {			// 알파벳에 대해서만 처리
			char c = tolower((this->text)[i]);	// 알파벳의 소문자형의 ascii코드값 파악
			this->histo[c - 'a']++;			// n번째 알파벳이면 n번째 원소값 1증가
		}
	}

	int n = 0;
	for (int i = 0; i < 26; i++) n += this->histo[i]; // 전체 알파벳 수 더하기
	cout << "총 알파벳 수 " << n << endl;
	cout << endl;

	for (int i = 0; i < 26; i++) {				// 각 알파벳의 빈도* 출력
		cout << char('a' + i) << " (" << this->histo[i] << ")" << '\t' << ": ";
		for (int j = 0; j < this->histo[i]; j++)
			cout << '*';
		cout << endl;
	}
}

int main() {
	Histogram song("Wise men say, only fools rush in But I can't help, \n");	// 생성자
	song << "falling" << " in love with you" << " - by ";	// <<연산자 오버로딩: bit shift -> add (문자열)
	song << 'k' << 'i' << 't';								// <<연산자 오버로딩: bit shift -> add (문자 = 함수 오버로딩)
	!song;													// !연산자 오버로딩: 논리not-> 히스토그램 콘솔출력
}