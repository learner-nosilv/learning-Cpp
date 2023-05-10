/* 1-4. Book class에 대한 묶음 문제
* 문제1(1), 2(1), 3, 4
	+=, -=, ==, !, < 연산자 함수를 왠만하면 클래스멤버/불가하면 외부함수로 구현하기
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

	// 문제1(1) +=, -= 연산자 함수를 Book 클래스의 멤버함수로 구현
	Book& operator+=(int price) {
		this->price += price;
		return(*this);
	}
	Book& operator-=(int price) {
		this->price -= price;
		return(*this);
	}

	// 문제2(1) == 연산자 함수 3개를 가진 Book 클래스 작성
	bool operator==(string title) { return this->title == title; }
	bool operator==(int price) { return this->price == price; }
	bool operator==(Book book) {
		return (this->title == book.title)
			&& (this->price == book.price)
			&& (this->pages == book.pages);
	}

	// 문제3 공짜책인지 판별하는 !연산자함수 작성
	bool operator!() { return this->price == 0; }

	// 문제4 책 제목을 사전 순으로 비교하는 <연산자함수 작성 (첫번째 매개변수가 string타입이므로 전역변수로 작성)
	friend bool operator<(string title, Book book);
	
};

bool operator<(string title, Book book) { return title < book.title; }

int main() {
	cout << "-------문제1(1)구현-------" << endl;
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;	// price 증가
	b == 500;	// price 감소
	a.show();
	b.show();
	cout << endl;

	cout << "-------문제2(1)구현-------" << endl;
	Book c("명품 C++", 30000, 500), d("고품 C++", 30000, 500);
	if (c == 30000) cout << "정가 30000원" << endl;			// price 비교
	if (c == "명품 C++") cout << "명품 C++ 입니다." << endl;	// title 비교
	if (c == d) cout << "두 책이 같은 책입니다." << endl;	// title, price, pages 모두 비교
	cout << endl;

	cout << "-------문제3구현-------" << endl;
	Book book("벼룩시장", 0, 50);
	if (!book) cout << "공짜다" << endl;
	cout << endl;

	cout << "-------문제4구현-------" << endl;
	string e;
	cout << "책 이름을 입력하세요>>";
	getline(cin, e);	// string입력
	if (e < a)
		cout << a.getTitle() << "이 " << e << "보다 뒤에 있구나!" << endl;
	cout << endl;

	return 0;
}