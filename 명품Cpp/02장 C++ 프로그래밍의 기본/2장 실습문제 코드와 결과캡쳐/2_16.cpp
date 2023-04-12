/*
* 기능 1. 영문텍스트 입력받기
* 크기가 10000인 문자열변수필요
* cin.getline(문자열변수명, 10000글자, 구분문자는';')
* 
* 기능 2. 문자를 세는 배열 int count [27]: 26자 + 총 알파벳합계1자
*		index와 A=65~ a=97을 활용한다
* 기능 3. 문자의 갯수출력(1회씩) 갯수만큼의 *출력(N회씩)
*/

#include <iostream>
using namespace std;

int main() {
	int count[27] = { 0 };	// count[0]은 A(65), a(97)의 갯수~count[25]는 Z,z의 갯수, count[26]는 총합
	char line[10000];		// 영문 텍스트를 입력받을 변수

	// 1. 영문 텍스트 입력받기
	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다. \n"
		<< "텍스트의 끝은 ; 입니다. 10000개까지 가능합니다." << endl;	// 사실상 ;를 제외한 9999자를 입력받을 수 있다.

	cin.getline(line, 10000, ';');	// 마지막 ; 글자를 제외한 9999자를 line에 할당하고 마지막은 '\0'로 문자열처리 

	// 2. 영문자 세기
	for (int i = 0; line[i] != '\0'; i++) {	// 문자열의 종료지점 전 까지 반복
		if (line[i] >= 'A' && line[i] <= 'Z') {			// 대문자의 경우
			count[26]++;								// 총 글자 수 세기
			count[(line[i] - 'A')]++;					// A(65)이면 count[0]이 1증가
		}
		else if (line[i] >= 'a' && line[i] <= 'z') {	// 소문자의 경우
			count[26]++;								// 총 글자 수 세기
			count[(line[i]-'a')]++;						//  a(97)이면 count[0]이 1증가
		}
	}

	// 3. 히스토그램 출력
	// 3-1) 총 알파벳 수 출력
	cout << "총 알파벳 수 " << count[26] << '\n' << endl;
	// 3-2) 개별 알파벳 수 출력 
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 'a') << '(' << count[i] << ')' << "\t: ";
		// * 출력
		for (int j = 0; j < count[i]; j++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}