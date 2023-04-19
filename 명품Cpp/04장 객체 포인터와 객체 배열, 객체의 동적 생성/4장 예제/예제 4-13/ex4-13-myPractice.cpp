/* 첫번째 발상 : [0] 번째문자 삭제& 맨 뒤에 삽입 : 1. 문자열.insert(문자열.size(), 문자열[0]), 2. 문자열.erase(0, 1)
	1. 스트링객체.insert(인덱스, 스트링): 스트링객체의 특정 인덱스에 스트링 삽입
	2. 스트링객체.erase(인덱스, 갯수): 스트링객체의 특정 인덱스부터 N글자 삭제
	
   두번째 발상: insert대신에 + 사용, 삭제 대신에 새로운 배열substr()
   스트링객체.substr(인덱스, 갯수): 스트링객체의 특정 인덱스부터 N글자만 뜯어서 반환
   ^^^^ 
   위 방법 채택, 이유 : 예제 답안을 슬쩍보니 substr을 씀
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	string str1;
	cout << "Type String" << endl;
	getline(cin, str1, '\n');		// 개행 전까지의 문자열을 스트링객체 str1에 저장
	int size = (str1).size();
	
	// 첫번째 발상대로 간단하게 - 
	for (int i = 0; i < size; i++) {
		str1 = str1 + str1[0];
		str1.erase(0, 1);
		cout << str1 << endl;
	}

	// 두번째 발상: 책의 방향대로
	for (int i = 0; i < size; i++) {
		string first = str1.substr(1, size - 1);
		string sub = str1.substr(0, 1);
		str1 = first + sub;
		cout << str1 << endl;
	}

	return 0;
}