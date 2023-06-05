/*
 -
*/

#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {	// Inline Constructor(Default Parameter) : 객체의 모든 멤버변수 초기화
		this->title = title; this->price = price; 	this->pages = pages;
	}
	void show() {	// 객체의 모든 멤버변수value 콘솔출력
		cout << title << ' ' << price << " Won " << pages << " Pages" << endl;
	}
	string getTitle() { return title; }		// 멤버변수 title의 value return
	Book& operator +=(int price);		//P5.1(1) 합연산 후 할당하는 += operator overloading
	Book& operator -=(int price);		//P5.1(1) 차연산 후 할당하는 -= operator overloading
	bool operator ==(string title) {	//P5.2(1) 값이 같은지 비교하는 == operator overloading : 현 객체의 멤버변수 title과 입력값이 같은지 비교 (같으면 true리턴) [inline]
		return (this->title == title);
	}
	bool operator ==(int price) {		//P5.2(1) == : 현 객체의 멤버변수 price와 입력값이 같은지 비교 (같으면 true리턴) [inline] & operator== function overloading
		return (this->price == price);
	}
	bool operator ==(Book book) {		//P5.2(1) == : 현 객체와 입력받은 객체의 멤버변수값이 전부 같은지 비교 (같으면 true리턴) [inline] & operator== function overloading
		return (this->title == book.title) && (this->price == book.price) && (this->pages == book.pages);
	}
	bool operator !(){					//P5.3    논리NOT ! operator overloading : 현 객체의 멤버변수 price가 0인지 비교 (0이면 true리턴) [inline]
		return this->price == 0;
	}
	friend bool operator <(string title, Book book);	//P5.4    크기비교 < operator overloading : 첫번째 파라미터가 Book 객체가 아니므로 전역함수로 구현 후 friend 선언
};

Book& Book::operator +=(int price) {			//현 객체의 멤버변수 price를 입력값만큼 증가시킴 & 객체자신 참조리턴
	this->price += price;
	return *this;
}
a += b;		// 코드
a. += (b);	// 컴파일러 인식
a.func(b);	// 예시


Book& Book::operator -=(int price) {			//현 객체의 멤버변수 price를 입력값만큼 감소시킴 & 객체자신 참조리턴
	this->price -= price;
	return *this;
}

bool operator <(string title, Book book) {		// 전역변수: 첫번째 파라미터인 문자열과 두번째 파라미터인 객체의 title 비교 (문자열이 사전순으로 앞이면 true리턴)
	return title < book.title;
}

int main() {
	Book a("YOUTH", 20000, 300), b("FUTURE", 30000, 500);
	a += 500; // Increase the price of the book a by 500 Won
	b -= 500; // Decrease the price of the book b by 500 Won
	a.show();
	b.show();
	cout << "---P7.1(1)----------------------------------------------" << endl;

	Book mp("Masterpiece C++", 30000, 500), hq("High Quality C++", 30000, 500);
	if (mp == 30000) cout << "Price is 30000 Won" << endl;	// price comparison
	if (mp == "Masterpiece C++") cout << "This book is the Masterpiece C++." << endl; 	// Comparison of book title
	if (mp == hq) cout << "These are some books." << endl; 				// Comparison of title, price & pages 
	cout << "---P7.2(1)----------------------------------------------" << endl;

	Book book("Flee Market", 0, 50); // Price is 0.
	if (!book) cout << "It is free." << endl;
	cout << "---P7.3-------------------------------------------------" << endl;

	string c;
	cout << "Please enter the title of book >> ";
	getline(cin, c); // Get the title of book from keyboard
	if (c < a)
		cout << a.getTitle() << " is after " << c << "!" << endl;
	cout << "---P7.4-------------------------------------------------" << endl;
}
