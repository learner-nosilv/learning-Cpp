/* Book 클래스 의 객체를 원소로 하는 가변배열 v 을 이용하여
*  책을 입고하고, 검색하는 프로그램을 작성하기
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
	string title, year, author;
public:
	Book(string title, string year, string author) {
		this->title = title;
		this->year = year;
		this->author = author;
	}
	string getTitle() { return this->title; }
	string getYear() { return this->year; }
	string getAuthor() { return this->author; }
};
int main() {
	vector<Book> v;
	string title, year, author;

	// 1. 입고하기
	cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다.\n";
	while (true) {
		cout << "년도>>";
		getline(cin, year);
		if (year == "-1") break;
		cout << "책이름>>";
		getline(cin, title);
		cout << "저자>>";
		getline(cin, author);
		v.push_back(Book(title, year, author));
	}
	// 2. 검색하기
	cout << "총 입고된 책은 " << v.size() << "권입니다.\n";
	cout << "검색하고자 하는 저자 이름을 입력하세요>>";
	cin >> author;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getAuthor() == author)
			cout << v[i].getYear() << "년도, " << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
	}
	cout << "검색하고자 하는 년도를 입력하세요>>";
	cin >> year;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getYear() == year)
			cout << v[i].getYear() << "년도, " << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
	}
	return 0;
}