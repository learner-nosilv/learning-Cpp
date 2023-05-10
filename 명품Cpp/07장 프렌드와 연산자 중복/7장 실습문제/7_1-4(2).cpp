/* 1-4. Book class�� ���� ���� ����
* ����1(2), 2(2)
	+=, -=, == �������� �Լ��� �ܺ��Լ��� �����ϱ�
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
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
	}
	string getTitle() { return title; }

	friend Book& operator+=(Book& book, int price);
	friend Book& operator-=(Book& book, int price);
	friend bool operator==(Book book, string title);
	friend bool operator==(Book book, int price);
	friend bool operator==(Book book, Book book2);
};

// ����1(2) +=, -= ������ �Լ��� �ܺ��Լ��� ����
Book& operator+=(Book& book, int price) {
	book.price += price;
	return book;
}
Book& operator-=(Book& book, int price) {
	book.price -= price;
	return book;
}

// ����2(2) == ������ �Լ� 3���� �ܺ��Լ��� ����
bool operator==(Book book, string title) { return book.title == title; }
bool operator==(Book book, int price) { return book.price == price; }
bool operator==(Book book, Book book2) {
	return (book.title == book2.title)
		&& (book.price == book2.price)
		&& (book.pages == book2.pages);
}

int main() {
	cout << "-------����1(2)����-------" << endl;
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500;	// price ����
	b == 500;	// price ����
	a.show();
	b.show();
	cout << endl;

	cout << "-------����2(2)����-------" << endl;
	Book c("��ǰ C++", 30000, 500), d("��ǰ C++", 30000, 500);
	if (c == 30000) cout << "���� 30000��" << endl;			// price ��
	if (c == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl;	// title ��
	if (c == d) cout << "�� å�� ���� å�Դϴ�." << endl;	// title, price, pages ��� ��
	cout << endl;

	return 0;
}