/* Book Ŭ���� �� ��ü�� ���ҷ� �ϴ� �����迭 v �� �̿��Ͽ�
*  å�� �԰��ϰ�, �˻��ϴ� ���α׷��� �ۼ��ϱ�
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

	// 1. �԰��ϱ�
	cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�.\n";
	while (true) {
		cout << "�⵵>>";
		getline(cin, year);
		if (year == "-1") break;
		cout << "å�̸�>>";
		getline(cin, title);
		cout << "����>>";
		getline(cin, author);
		v.push_back(Book(title, year, author));
	}
	// 2. �˻��ϱ�
	cout << "�� �԰�� å�� " << v.size() << "���Դϴ�.\n";
	cout << "�˻��ϰ��� �ϴ� ���� �̸��� �Է��ϼ���>>";
	cin >> author;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getAuthor() == author)
			cout << v[i].getYear() << "�⵵, " << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
	}
	cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>>";
	cin >> year;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getYear() == year)
			cout << v[i].getYear() << "�⵵, " << v[i].getTitle() << ", " << v[i].getAuthor() << endl;
	}
	return 0;
}