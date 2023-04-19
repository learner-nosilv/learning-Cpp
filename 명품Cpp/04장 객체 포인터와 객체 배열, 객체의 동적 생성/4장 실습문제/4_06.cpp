/* 6.
* string 클래스로 영문한줄을 입력받고 거꾸로 출력하는 프로그램 (size/2)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence = "\0";
	int index;
	char temp;
	cout << "아래에 한 줄을 입력하세요. (exit를 입력하면 종료합니다)" << endl;

	while (1) {
		
		cout << ">>";
		getline(cin, sentence, '\n');	// 문장 입력받기

		if (sentence == "exit") break;

		index = sentence.size() - 1;	// 문장 마지막 인덱스

		for (int i = 0; i < ((index+1)/2); i++) {
			temp = sentence[i];
			sentence[i] = sentence[index - i];
			sentence[index - i] = temp;
		}

		cout << sentence << endl;
	}
	
	return 0;
}

/* [book solution]
* 차이점
* 1. 변수 선언위치: 나는 반복문 밖, 솔루션은 반복문 안 (int size와 char temp)
* 2. 인덱스 형식 : 나 sentence[i] = sentence[index - i] | 솔루션 text[i] = text[size-i-1]
* 3. for문의 조건문: 나 i < ((index+1)/2) | 솔루션 i<n (int n = size/2;를 미리 선언)

int main() {
	string text;
	cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
	while(true) {
		cout << ">>";
		getline(cin, text, '\n');
		if(text == "exit")
			break;
		int size = text.length();
		int n = size/2;
		for(int i=0; i<n; i++) {
			char tmp = text[i];
			text[i] = text[size-i-1];
			text[size-i-1] = tmp;
		}
		cout << text << endl;
	}
}
*/