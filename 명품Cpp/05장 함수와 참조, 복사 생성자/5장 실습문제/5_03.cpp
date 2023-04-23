/* 3. 다음과 같이 작동하도록 combine() 함수 작성하기
* 호출문: combine(text1, text2, text3);
* 기능: 인자 text3의 실제 값을 text1과 text2를 공백으로 이은 문자열로 바꾸기
*/

#include <iostream>
#include <string>
using namespace std;

void combine(string a, string b, string& c) {
	c = a + ' ' + b;
}

int main() {
	string text1("I love you"), text2("very much");
	string text3;
	combine(text1, text2, text3);
	cout << text3;
	return 0;
}