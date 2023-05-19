/* 411p OpenChallenge
* 문제1: main()에서 세 가지의 다른 클래스 객체들을 어떻게 한번에 관리하지?
*	product포인터 배열을 하면 업캐스팅은 되겠지만 모든 멤버출력이 불가능함
* 
* 문제2: switch 속 switch 의 오작동 -> 해결
* https://stackoverflow.com/questions/42297348/transfer-of-control-bypasses-initialization-of
* 
* 문제3: 개행문자를 입력버퍼에 남겨두는 cin -> 개행문자(delimiter)까지를 받고 delimiter전까지를 할당하는 getline
* https://namwhis.tistory.com/entry/cin%EA%B3%BC-getline%EC%9D%84-%EA%B0%99%EC%9D%B4-%EC%82%AC%EC%9A%A9%ED%95%A0%EB%95%8C-cinignore%EC%9D%B4-%ED%95%84%EC%9A%94%ED%95%9C-%EC%9D%B4%EC%9C%A0-%EA%B8%B0%EB%A1%9D
* cin.ignore 함수의 원형은 istream& ignore (streamsize n = 1, int delim = EOF); 이다.
n의 수만큼의 문자를 읽어들인 후 버리게 되고 또는 delim에 해당하는 문자를 만나면 해당 문자까지를 읽어들인 후 버리게 된다.(둘 중에 먼저 만족하는 조건을 따르게 된다.)
https://dntworry-behappy.tistory.com/2

* 문제4:
* 팝으로 배우는 영어 회화를 입력할 때
Conversation Book의 입력형태가 Book의 입력형태랑 뒤죽박죽되어있다.
setProduct, setBook 이런 걸 사용하지 않은 것 같다.
오ㅐ?
*/
#include <iostream>
#include <string>
using namespace std;

// 숫자가 아닌 문자열 입력시 발생하는 입력에러 처리
bool isError() {
	if (cin.fail()) {
		cin.clear();
		cin.ignore(999, '\n');
		return true;
	}
	else return false;
}

class Product {
	static int productTotal;	// 총 상품 갯수
	int kind;					// 상품종류 0Product 1Book 2CD 3ConversationBook
	int id;						// 식별자
	string description;			// 설명
	string madeIn;				// 생산자
	int price;					// 가격
public:
	Product(int kind = 0) {
		this->kind = kind;
		this->id = productTotal;	// 식별자 자동생성
		productTotal++;
	}
	void setProduct() {
		cout << "상품설명 : ";
		getline(cin, this->description,'\n');
		cout << "생산자 : ";
		getline(cin, this->madeIn,'\n');
		do {
			cout << "가격 : ";
			cin >> this->price;
			cin.ignore(1, '\n');		// 입력버퍼에 남아있는 개행문자 삭제
		} while (isError());
	}
	void showProduct() {
		cout << "--- 상품ID : " << this->id << '\n'
			<< "상품설명 : " << this->description << '\n'
			<< "생산자 : " << this->madeIn << '\n'
			<< "가격 : " << this->price << endl;
	}
	int whatKind() { return kind; }
};
int Product::productTotal = 0;	// 총 상품 갯수

class Book : public Product {
	int isbn;				// ISBN번호
	string title;			// 제목
	string author;			// 저자
public:
	Book(int kind = 1) : Product(kind) { }
	void setBook() {
		setProduct();
		do {
			cout << "ISBN : ";
			cin >> isbn;
			cin.ignore(1, '\n');		// 입력버퍼에 남아있는 개행문자 삭제
		} while (isError());
		cout << "책제목 : ";
		getline(cin, title);
		cout << "저자 : ";
		getline(cin, author);
	}
	void showBook() {
		showProduct();
		cout << "ISBN : " << isbn << '\n'
			<< "책제목 : " << title << '\n'
			<< "저자 : " << author << endl;
	}
};

class CompactDisc : public Product {
	string title;			// 제목
	string artist;			// 가수
public:
	CompactDisc(int kind = 2) : Product(kind) { }
	void setCD() {
		setProduct();
		cout << "앨범제목 : ";
		getline(cin, title);
		cout << "가수 : ";
		getline(cin, artist);
	}
	void showCD() {
		showProduct();
		cout << "앨범제목 : " << title << '\n'
			<< "가수 : " << artist << endl;
	}
};

class ConversationBook : public Book {
	string language;	// 언어
public:
	ConversationBook(int kind = 3) :Book(kind) { }
	void setCB() {
		setBook();
		cout << "언어 : ";
		getline(cin, language);
	}
	void showCB() {
		showBook();
		cout << "언어 : " << language << endl;
	}
};

int main() {
	int total = 0;				// 0:total, 1:book, 2:cd, 3:conversation book
	Product* management[100];
	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
	int menu = 0;					// 관리메뉴
	while(menu!=3 && total<100) {				// 루프탈출조건: 3 (끝내기)
		do {
			cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
			cin >> menu;
			cin.ignore(1,'\n');		// 입력버퍼에 남아있는 개행문자 삭제
		} while (isError());
		
		switch (menu) {		// 상품관리메뉴
			case 1: {		// 상품관리메뉴 [1. 상품추가]
				int kind;				//	상품 종류 입력받아서, 상품 종류에 맞는 객체 생성하기
				do {
					cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
					cin >> kind;
					cin.ignore(1, '\n');		// 입력버퍼에 남아있는 개행문자 삭제
				} while (isError() && (kind == 1 || kind == 2 || kind == 3));

				switch (kind) {			//	상품 종류 입력받아서, 상품 종류에 맞는 객체 생성하기
					case 1: {			//	1. Book
						management[total] = new Book;						// upcasting
						((Book*)management[total])->setBook();
						total++;
						break;
					}
					case 2: {			//	2. CD
						management[total] = new CompactDisc;				// upcasting
						((CompactDisc*)management[total])->setCD();
						total++;
						break;
					}
					case 3: {			//	3. Conversation Book
						management[total] = new ConversationBook;			// upcasting
						((ConversationBook*)management[total])->setCB();
						total++;
						break;
					}
				}
				break;					//	상품 종류 입력받기 break
			}
			case 2: {		// 상품관리메뉴 [2. 모든상품조회]
				for (int i = 0; i < total; i++) {
					switch (management[i]->whatKind()) {	// 상품종류 0Product 1Book 2CD 3ConversationBook
						case 1: {		// Book
							((Book*)management[i])->showBook();				// Downcasting
							break;
						}

						case 2: {		// CD
							((CompactDisc*)management[i])->showCD();		// Downcasting
							break;
						}

						case 3: {		// Conversation Book
							((ConversationBook*)management[i])->showCB();	// Downcasting
							break;
						}
					}
				}
				break;					//	2. 모든상품조회 break
			}
		}	// 상품관리메뉴 Switch
	}	// 상품관리 Loop 탈출

	for (int i = 0; i < total; i++)		// delete[] management; 는 오류
		delete management[i];

	return 0;
}