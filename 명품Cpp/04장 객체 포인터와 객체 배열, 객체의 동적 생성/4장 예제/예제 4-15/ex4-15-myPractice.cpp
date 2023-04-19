/*
* & 키가 입력되기 전까지 여러 줄의 영문 문자열 입력받기 : getline(cin, s, '&');
* 찾는 문자열과 대치할 문자열을 각각 입력받아서 문자열을 변경하라
* 문자열 찾기: 스트링객체.find(문자열) -> return 문자열 시작위치 or -1
* 문자열 대치: 스트링객체.	replace(시작인덱스, n글자, 문자열)
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string essay;
	cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &문자입니다." << endl;
	getline(cin, essay, '&');
	cin.ignore();				// 버퍼에 들어있는 & 이후의 문자는 개행까지 쭉 삭제

	string f, r;
	cout << "find: ";
	getline(cin, f, '\n');
	cout << "replace: ";
	getline(cin, r, '\n');

	int fsize = (int)f.size();	// 나중에 교체할 때 필요함(replace)
	int rsize = (int)r.size();	// startIndex를 증가시킬 때 필요함
	
	int startIndex = 0;		// 검사위치
	while (true) {
		startIndex = (int)essay.find(f, startIndex);	// startIndex부터 문자열f 찾기
		if (startIndex == -1)	// 없다면, 대치 종료
			break;
		else {
			essay.replace(startIndex, fsize, r);
			startIndex += rsize;
		}
			
	}

	cout << "수정본: " << endl;
	cout << essay << endl;

	return 0;
}