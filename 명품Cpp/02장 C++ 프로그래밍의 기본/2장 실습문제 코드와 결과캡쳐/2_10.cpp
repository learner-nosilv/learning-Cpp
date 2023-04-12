/*
* cin입력: 문자열을 입력받아서
* cout출력: 1줄 당 앞 1글자, 앞1~2글자, 앞 1~3글자 이렇게 점층적으로 부분문자열을 반복출력하는 프로그램
* 이번에도 string을 사용해본다(이와 관련된 좋은 함수들 많을텐데 아는 내용으로만 작성해보자)
*/

#include<iostream>
#include<string>
using namespace std;

int main() {
	string sentence;	// 입력된 문장을 저장할 스트링 객체

	// 1. 입력받기
	cout << "문자열 입력>>";
	getline(cin, sentence);	// 공백도 인정하는 입력값 받기

	// 2. 문장을 점층적으로 출력하기
	for (int i = 0; sentence[i] != '\0'; i++) {	// 문자수만큼 반복 (sentence[i]=='\0'이면, i는 문자수+1이다.)
		for (int j = 0; j <= i; j++) {	// 1번째 줄은 글자 1자 출력 ~ N번째 줄은 글자 N자 출력
			cout << sentence[j];		// 글자 1개씩 출력
		}
		cout << endl;
	}
	return 0;
}