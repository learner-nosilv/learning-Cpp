/* 13.
* 영문자로 구성된 텍스트에 대해 각 알파벳에 해당하는 문자가 몇 개인지 출력하는 히스토그램 클래스
* 대문자, 소문자 구분없이 카운트
* 
* 메인함수와 실행결과를 보고 클래스를 작성하자
*/

#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string sentence;
	int size = 0;
	int count[27] = { 0, };				// [0-25]까지 a(65 97)~z(90 122)의 갯수, [26] total
	void counter(string s);
	void counter(char c);
	
public:
	Histogram(string s) {
		sentence = s;
		size = s.size();
		counter(s);
	}
	void put(string s);
	void putc(char c);
	void print();
};

void Histogram::counter(string s) {
	int size = s.size();
	for (int i = 0; i < size; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			count[(s[i] - 'a')]++;	// a이면 counter[0]++
			count[26]++;					// 총 알파벳 수
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			count[(s[i] - 'A')]++;	// A이면 counter[0]++
			count[26]++;					// 총 알파벳 수
		}
	}
}

void Histogram::counter(char c) {
	if (c >= 'a' && c <= 'z') {
		count[(c - 'a')]++;				// a이면 counter[0]++
		count[26]++;					// 총 알파벳 수
	}
	else if (c >= 'A' && c <= 'Z') {
		count[(c - 'A')]++;				// A이면 counter[0]++
		count[26]++;					// 총 알파벳 수
	}
}

void Histogram::put(string s) {
	sentence.append(s);
	size += s.size();
	counter(s);
}

void Histogram::putc(char c) {
	sentence = sentence + c;	// [솔루션] char buf[] = {c, '\0'}; this->text.append(buf);
	size++;
	counter(c);
}

void Histogram::print() {
	cout << sentence << endl << endl;
	cout << "총 알파벳 수 " << count[26] << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 65) << " (" << count[i] << ") \t: ";
		for (int star = 0; star < count[i]; star++) {
			cout << '*';
		}
		cout << endl;
	}
}


int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();

	return 0;
}