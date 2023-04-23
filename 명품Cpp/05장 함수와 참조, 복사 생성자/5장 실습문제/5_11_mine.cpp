/* 11.
* Book 클래스 : 책의 이름과 가격 저장
*
* ***너무하네ㅠㅠ***
*	main()에 java.set("명품자바", 12000); 가 있다.
*
*	책엔 void set(char* title, ...)로 되어있어서, 컴파일 오류가 났다.
*	답은 void set(const char* title, ...)로 은근슬쩍 바뀌어있음. 으휴
*/

#include <iostream>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
//	Book(const Book& book) {			// (2) 컴파일러가 생성하는 디폴트 복사 생성자 코드
//		this->title = book.title;		// 이전에 동적할당받은 this->title의 값이 사라지면서 메모리 누수발생 & 같은 title 공간을 가리킴 = 두 객체의 소멸자가 중복실행되며 런타임오류발생
//		this->price = book.price;
//	}
	Book(const Book& book) {			// (3) 깊은 복사가 가능한 사용자 지정 복사 생성자 코드
		int null_idx;										// 입력받은 book.title문자열의 크기-1
		for (null_idx = 0; *((book.title) + null_idx) != '\0'; null_idx++);
		this->title = new char[null_idx + 1];				// 입력받은 title만큼 새로운 동적할당받기

		for (int i = 0; i <= null_idx; i++)					// 동적할당받은 title에 입력받은 title 복사하기
			*((this->title) + i) = *((book.title) + i);

		this->price = book.price;								// 가격
	}

	~Book() { delete[] title; }							// (1) 생성자, 소멸자, set함수 작성
	void set(char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }

};

Book::Book(const char* title, int price) {				// (1) 생성자, 소멸자, set함수 작성
	int null_idx;										// 입력받은 title문자열의 크기-1
	for (null_idx = 0; *(title + null_idx) != '\0'; null_idx++);

	this->title = new char[null_idx + 1];				// 입력받은 title만큼 동적할당받기

	for (int i = 0; i <= null_idx; i++) {				// 동적할당받은 title에 입력받은 title 복사하기
		*((this->title) + i) = *(title + i);
	}
	this->price = price;								// 가격
}

void Book::set(char* title, int price) {				// (1) 생성자, 소멸자, set함수 작성
	delete[] this->title;								// 생성자에 의해 발생한 동적할당 해제

	int null_idx;										// 입력받은 title문자열의 크기-1
	for (null_idx = 0; *(title + null_idx) != '\0'; null_idx++);

	this->title = new char[null_idx + 1];				// 입력받은 title만큼 동적할당받기

	for (int i = 0; i <= null_idx; i++) {				// 동적할당받은 title에 입력받은 title 복사하기
		*((this->title) + i) = *(title + i);
	}
	this->price = price;								// 가격
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	char name[9] = "명품자바";
	java.set(name, 12000);							// cannot convert argument 1 from 'const char [9] to 'char *'
//	java.set("명품자바", 12000);						// [오류] const char* 타입의 인수는 char* 타입의 파라미터로 호환될 수 없습니다 
	cpp.show();
	java.show();
	return 0;
}