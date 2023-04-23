/* 11.
* Book 클래스 : 책의 이름과 가격 저장 
* 
* ***너무하네ㅠㅠ***
*	main()에 java.set("명품자바", 12000); 가 있다.
* 
*	책엔 void set(char* title, ...)로 되어있어서, 컴파일 오류가 났다.
*	답은 void set(const char* title, ...)로 은근슬쩍 바뀌어있음. 으휴33
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price) { this->set(title, price); }	// (1) 생성자 작성70
//	Book(const Book& book) {			// (2) 컴파일러가 생성하는 디폴트 복사 생성자 코드8
//		this->title = book.title;		// 이전에 동적할당받은 this->title의 값이 사라지면서 메모리 누수발생 & 같은 title 공간을 가리킴 = 두 객체의 소멸자가 중복실행되며 런타임오류발생
//		this->price = book.price;
//	}
	Book(const Book& book);			// (3) 깊은 복사가 가능한 사용자 지정 복사 생성자 코드
	~Book() { delete[] title; }							// (1) 생성자, 소멸자, set함수 작성
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const Book& book) {			// (3) 깊은 복사가 가능한 사용자 지정 복사 생성자 코드
	int len = strlen(book.title);			// 입력받은 문자열의 크기
	this->title = new char[len + 1];		// NULL문자까지 포함해서, title로 동적할당받기
	strcpy(this->title, book.title);		// 문자들 복사하기
	this->price = book.price;				// 가격
}

void Book::set(const char* title, int price) {		// (1) 생성자, 소멸자, set함수 작성
	if (this->title)								// 이미 존재하는 동적할당이 있다면 해제
		delete[] this->title;						

	int len = strlen(title);			// 입력받은 문자열의 문자갯수
	this->title = new char[len + 1];	// 입력받은 title + \0 만큼 동적할당받기
	strcpy(this->title, title);			// 문자열 전부 복사
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