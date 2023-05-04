/* 9.
* 게시판 클래스
*  게시판 내용: static
* main() 함수와 실행결과를 참고하여 Board 클래스만들고 프로그램 완성하기
*/

#include <iostream>
#include <string>
using namespace std;

class Board {
	static string content[10];		// 10개의 내용을 담을 수 있는 게시판
	static int empty;
public:
	void static add(string content);
	void static print();
};

// static멤버 Definition
string Board::content[10];
int Board::empty = 0;
void Board::add(string content) {
	if (empty < 10) {
		Board::content[Board::empty] = content;
		Board::empty++;
	}
	else
		cout << "!게시판 공간부족!" << endl;
}

void Board::print() {
	for (int star = 0; star < 13; star++) cout << '*';
	cout << " 게시판입니다. ";
	for (int star = 0; star < 13; star++) cout << '*';
	cout << endl;

	for (int i = 0; i < empty; i++)
		cout << i << ": " << Board::content[i] << endl;
	cout << endl;
}

int main() {
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();

	return 0;
}