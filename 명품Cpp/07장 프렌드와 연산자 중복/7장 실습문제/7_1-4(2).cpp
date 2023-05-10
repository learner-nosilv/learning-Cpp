/* 1-4. Book class에 대한 묶음 문제
* 문제1(2), 2(2)
	+=, -=, == 연산자의 함수를 외부함수로 구현하기
*/
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price, pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}

	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() { return title; }

	friend Book& operator+=(Book& book, int price);
	friend Book& operator-=(Book& book, int price);
	friend bool operator==(Book book, string title);
	friend bool operator==(Book book, int price);
	friend bool operator==(Book book, Book book2);
};

// 문제1(2) +=, -= 연산자 함수를 외부함수로 구현
Book& operator+=(Book& book, int price) {
	book.price += price;
	return book;
}
Book& operator-=(Book& book, int price) {
	book.price -= price;
	return book;
}

// 문제2(2) == 연산자 함수 3개를 외부함수로 구현
bool operator==(Book book, string title) { return book.title == title; }
bool operator==(Book book, int price) { return book.price == price; }
bool operator==(Book book, Book book2) {
	return (book.title == book2.title)
		&& (book.price == book2.price)
		&& (book.pages == book2.pages);
}

int main() {
	cout << "-------문제1(2)구현-------" << endl;
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;	// price 증가
	b == 500;	// price 감소
	a.show();
	b.show();
	cout << endl;

	cout << "-------문제2(2)구현-------" << endl;
	Book c("명품 C++", 30000, 500), d("고품 C++", 30000, 500);
	if (c == 30000) cout << "정가 30000원" << endl;			// price 비교
	if (c == "명품 C++") cout << "명품 C++ 입니다." << endl;	// title 비교
	if (c == d) cout << "두 책이 같은 책입니다." << endl;	// title, price, pages 모두 비교
	cout << endl;

	return 0;
}