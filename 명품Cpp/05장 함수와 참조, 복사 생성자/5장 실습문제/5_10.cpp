/* 10.
* 참조리턴 코드 작성하기
* append() 함수를 작성하기 : Buffer 객체에 문자열을 추가하고 해당 객체를 참조리턴
*/

#include <iostream>
#include <string>
using namespace std;

class Buffer {
	string text;
public:
	Buffer(string text) { this->text = text; }
	void add(string next) { this->text += next; }
	void print() { cout << text << endl; }
};

Buffer& append(Buffer& buffer, string word) {
	buffer.add(word);
	return buffer;
}

int main() {
	Buffer buf("Hello");
	Buffer& temp = append(buf, "Guys");	// buf를 변경하고 temp라는 alias 생성 (temp가 곧 buf : 같은 객체)
	temp.print();
	buf.print();
	return 0;
}