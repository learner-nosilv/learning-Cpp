/* 11. (4) 스트링 클래스로 사용하기
* Book 클래스 : 책의 이름과 가격 저장 
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price) { this->set(title, price); }	// (1) 생성자 작성
	void set(string title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

void Book::set(string title, int price) {		// (1) 생성자, 소멸자, set함수 작성
	this->title = title;
	this->price = price;				// 가격
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000); 
	cpp.show();
	java.show();
	return 0;
}