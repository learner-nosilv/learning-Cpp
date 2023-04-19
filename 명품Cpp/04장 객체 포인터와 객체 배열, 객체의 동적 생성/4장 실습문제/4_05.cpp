/* 5.
* string 클래스를 이용하여 영문 한 줄 입력받기 : getline(cin, 변수, 구분자)
* 글자 하나만 랜덤하게 수정하여 출력
* 
* 랜덤정수 : <cstdlib> 의 srand, rand, <ctime>의 time 사용
* 
* ascii 코드표를 보면, 33 ~ 126까지가 문자들이고,
* 65~90까지가 알파벳 대문자, 97~122까지가 알파벳 소문자이다.* 
*/

#include <iostream>		// c++ 표준 입출력
#include <string>		// string 클래스사용
#include <cstdlib>		// srand, rand 등 사용
#include <ctime>		// time 사용
using namespace std;	// 모두 std namespace 속에 존재

int main() {
	string sentence;
	while (1) {								// 루프
		// 1. 영문 한 줄 입력받고, 문자갯수 파악
		cout << ">>";
		getline(cin, sentence, '\n');
		if (sentence == "exit") break;		// 루프탈출조건: exit 입력
		int size = sentence.size();

		// 2. 대체될 글자의 index를 랜덤하게 결정
		srand((unsigned)time(NULL));	// seed 설정
		int index = rand() % size;

		// 3. 대체할 글자의 ascii코드값 랜덤하게 설정 (65~90, 97~122)
		int ascii = 91;						// '['
		while (ascii >= 91 && ascii <= 96) {	// 대체할 글자가 알파벳이 아니라면 반복 
			ascii = (rand() % 58) + 65;		// 65 ~ 122 사이의 랜덤 정수
		}

		// 4. 영문 한 줄에서 글자 하나만 랜덤하게 수정하여 출력
		sentence[index] = (char)ascii;
		cout << sentence << endl;
	}
	
	return 0;
}